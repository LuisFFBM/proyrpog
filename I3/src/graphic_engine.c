/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG, Óskar, Álexx
 * @version 4.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/graphic_engine.h"
#include "../include/libscreen.h"
#include "../include/command.h"
#include "../include/space.h"
#include "../include/types.h"
#include "../include/link.h"
#include "../include/player.h"

#define ROWS 35
#define COLUMNS 80
#define LINE_SIZE 255
#define MAX_MAP_STRING 17
#define MAX_ENEMY 7

/**
 * @brief structure that stores the interface parameters
 */
struct _Graphic_engine
{
    Area *map, *descript, *banner, *help, *feedback;
};

/** Graphic_engine gets intialized allocating the necessary memory
 */
Graphic_engine *graphic_engine_create()
{
    static Graphic_engine *ge = NULL;

    if (ge)
        return ge;

    screen_init(ROWS, COLUMNS);
    ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
    if (ge == NULL)
        return NULL;

    ge->map = screen_area_init(1, 1, 48, 25);
    ge->descript = screen_area_init(50, 1, 29, 25);
    ge->banner = screen_area_init(19, 27, 41, 1);
    ge->help = screen_area_init(1, 28, 78, 2);
    ge->feedback = screen_area_init(1, 31, 78, 3);

    return ge;
}

/** Frees the Graphic_engine structure
 */
void graphic_engine_destroy(Graphic_engine *ge)
{
    if (!ge)
        return;

    screen_area_destroy(ge->map);
    screen_area_destroy(ge->descript);
    screen_area_destroy(ge->banner);
    screen_area_destroy(ge->help);
    screen_area_destroy(ge->feedback);

    screen_destroy();
    free(ge);
}

/** It prints all the screen areas with the game information
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
    Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID;/* obj_loc = NO_ID;*/
    char str[LINE_SIZE];
    char aux[LINE_SIZE];
    char enemy[MAX_ENEMY];
    Command *last_cmd /*= command_create()*/;
    extern char *cmd_to_str[N_CMD][N_CMDT];    
    Object **objects = NULL;
    Set *ply_set = NULL;
    Id obj_id = NO_ID, *ply_obj_ids = NULL;
    STATUS st = ERROR;
    BOOL full = FALSE;
    int i;
    
    /* PAINTS IN THE MAP AREA */
    screen_area_clear(ge->map);
    if ((id_act = game_get_player_location(game)) != NO_ID)
    {
        
        id_back = game_get_connection(game,id_act,N);
        id_next =  game_get_connection(game,id_act,S);
        id_right =  game_get_connection(game,id_act,E);
        id_left =  game_get_connection(game,id_act,W);

        /* Prints the space above */
        if (id_back != NO_ID)
        {
            if(game_get_enemy_location(game) == id_back && enemy_get_health(game_get_enemy(game)) > 0)
            {
                sprintf(enemy, "/\\oo/\\");  
            }
            else
            {
                sprintf(enemy, "      ");
            }

            sprintf(str, "  +---------------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |   %s  %3d|  ",enemy ,(int)id_back);
            screen_area_puts(ge->map, str);

            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_back),0));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_back),1));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_back),2));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_back),3));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_back),4));
            screen_area_puts(ge->map, str);

            /* If it has a space to the left it prints two arrows in this direction */
            st = game_get_connection_status(game, id_back, W);
            if (st == OK)
                sprintf(str, "<<|");
            else
                sprintf(str, "  |");

             /* Prints the name of the objects that are in this space */
            objects = game_get_objects(game);
            for (full = FALSE, i = 0; i < MAX_OBJECTS && objects[i] != NULL && full == FALSE; i++)
            {
                if ((obj_id=game_get_object_location(game, object_get_id(objects[i]))) == id_back)
                {
                
                    sprintf(aux, "%s, ", object_get_name(objects[i]));
                    if((strlen(str) + strlen(aux)) < (MAX_MAP_STRING-1)){
                        strcat(str, aux);  
                    }

                    else if(obj_id != NO_ID){
                        
                        full = TRUE;
                    }
                    
                }
            }

            if(full == TRUE){

                str[(strlen(str)-2)] = 0;

                strcat(str, "...");
                while(strlen(str) <= MAX_MAP_STRING){
                    strcat(str, " ");
                }                
            }
            else{
                if(strlen(str)>3){
                    str[(strlen(str)-2)] = 0;

                    while(strlen(str) <= MAX_MAP_STRING ){
                    strcat(str, " ");
                    } 
                }
                else{
                    while(strlen(str) <= MAX_MAP_STRING ){
                    strcat(str, " ");
                    } 
                }   
                
            }

            /* If it has a space to the right it prints two arrows in this direction */
            st = game_get_connection_status(game, id_back, E);
            if (st == OK)
                strcat(str, "|>>");
            else
                strcat(str, "|  ");

            screen_area_puts(ge->map, str);

            sprintf(str, "  +---------------+");
            screen_area_puts(ge->map, str);
            
            if(game_get_connection_status(game,id_act,N))
            {
            sprintf(str, "        ^");
            screen_area_puts(ge->map, str);
            }
            else
            {
            sprintf(str, "        -");
            screen_area_puts(ge->map, str);   
            }
        }


        /* Prints the current space */
        if (id_act != NO_ID)
        {
            if(game_get_enemy_location(game) == id_act && enemy_get_health(game_get_enemy(game)) > 0)
            {
                sprintf(enemy, "/\\oo/\\");  
            }
            else
            {
                sprintf(enemy, "      ");
            }

            sprintf(str, "  +---------------+");
            screen_area_puts(ge->map, str);
            /* ant coding */
            sprintf(str, "  | m^ %s  %3d|  ",enemy ,(int)id_act);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_act),0));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_act),1));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_act),2));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_act),3));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_act),4));
            screen_area_puts(ge->map, str);
            

            /* If it has a space to the left it prints two arrows in this direction */
            st = game_get_connection_status(game, id_act, W);
            if (st == OK && id_left != NO_ID) 
            {
                sprintf(str, "<<|");
            }
            else
            { 
                sprintf(str, "  |");
            }

             /* Prints the name of the objects that are in this space */
            objects = game_get_objects(game);
            for (full = FALSE, i = 0; i < MAX_OBJECTS && objects[i] != NULL && full == FALSE; i++)
            {
                if ((obj_id=game_get_object_location(game, object_get_id(objects[i]))) == id_act )
                {
                    
                    sprintf(aux, "%s, ", object_get_name(objects[i]));
                    if((strlen(str) + strlen(aux)) < (MAX_MAP_STRING-1)){
                        strcat(str, aux);  
                    }
                    else if(obj_id != NO_ID){
                        
                        full = TRUE;
                    }
                    
                }
            }

            if(full == TRUE){

                str[(strlen(str)-2)] = 0;

                strcat(str, "...");
                while(strlen(str) <= MAX_MAP_STRING){
                    strcat(str, " ");
                }                
            }
            else{
                if(strlen(str)>3){
                    str[(strlen(str)-2)] = 0;

                    while(strlen(str) <= MAX_MAP_STRING ){
                    strcat(str, " ");
                    } 
                }
                else{
                    while(strlen(str) <= MAX_MAP_STRING ){
                    strcat(str, " ");
                    } 
                }   
                
            }
            
            

            /* If it has a space to the right it prints two arrows in this direction */
            st = game_get_connection_status(game, id_act, E);
            if (st == OK && id_right != NO_ID)
                strcat(str, "|>>");
            else
                strcat(str, "|  ");

            screen_area_puts(ge->map, str);

            sprintf(str, "  +---------------+");
            screen_area_puts(ge->map, str);
        }

        /* Prints the space below */
        if (id_next != NO_ID)
        {
            if(game_get_enemy_location(game) == id_next && enemy_get_health(game_get_enemy(game)) > 0)
            {
                sprintf(enemy, "/\\oo/\\");  
            }
            else
            {
                sprintf(enemy, "      ");
            }

            sprintf(str, "        v");
            screen_area_puts(ge->map, str);
            sprintf(str, "  +---------------+");
            screen_area_puts(ge->map, str);
            sprintf(str, "  |   %s  %3d|  ",enemy ,(int)id_next);
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_next),0));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_next),1));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_next),2));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_next),3));
            screen_area_puts(ge->map, str);
            sprintf(str, "  |%s      |  ", space_get_gdesc(game_get_space(game, id_next),4));
            screen_area_puts(ge->map, str);

            

            /* If it has a space to the left it prints two arrows in this direction */
            st = game_get_connection_status(game, id_next, W);
            if (st == OK)
            {
                sprintf(str,"<<|");
            }
            else
            {
                sprintf(str, "  |");
            }

            /* Prints the name of the objects that are in this space */
            objects = game_get_objects(game);
            for (full = FALSE, i = 0; i < MAX_OBJECTS && objects[i] != NULL && full == FALSE; i++)
            {
                if ((obj_id=game_get_object_location(game, object_get_id(objects[i]))) == id_next )
                {
                    
                    sprintf(aux, "%s, ", object_get_name(objects[i]));
                    if((strlen(str) + strlen(aux)) < (MAX_MAP_STRING-1)){
                        strcat(str, aux);  
                    }
                    else if(obj_id != NO_ID){
                        
                        full = TRUE;
                    }
                    
                }
            }

            if(full == TRUE){

                str[(strlen(str)-2)] = 0;

                strcat(str, "...");
                while(strlen(str) <= MAX_MAP_STRING){
                    strcat(str, " ");
                }                
            }
            else{
                if(strlen(str)>3){
                    str[(strlen(str)-2)] = 0;

                    while(strlen(str) <= MAX_MAP_STRING ){
                    strcat(str, " ");
                    } 
                }
                else{
                    while(strlen(str) <= MAX_MAP_STRING ){
                    strcat(str, " ");
                    } 
                }   
                
            }
            


            /* If it has a space to the right it prints two arrows in this direction */
            st = game_get_connection_status(game, id_next, E);
            if (st == OK)
                strcat(str, "|>>");
            else
                strcat(str, "|  ");

            screen_area_puts(ge->map, str);

            sprintf(str, "  +---------------+");
            screen_area_puts(ge->map, str);
        }
    }

    /* PAINTS IN THE DESCRIPTION AREA */
    screen_area_clear(ge->descript);

    sprintf(str, "  Objects location:");
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    objects = game_get_objects(game);
    for (i = 0; i < MAX_OBJECTS && objects[i] != NULL; i++)
    {   
        if(game_get_object_location(game,object_get_id(objects[i])) != NO_ID){
            sprintf(aux, "%s:%ld", object_get_name(objects[i]), game_get_object_location(game, object_get_id(objects[i])));
            if (objects[i + 1] != NULL)
            {
                strcat(aux, ", ");
            }
            strcat(str, aux);
        }
        
        
    }
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);

    sprintf(str, "Player location: %ld", player_get_location(game_get_player(game)));
    screen_area_puts(ge->descript, str);
    
    sprintf(str, "Player objects: ");
    ply_set = player_get_objects_inventory(game_get_player(game));
    if(ply_set != NULL)
    {
        ply_obj_ids = set_get_ids(ply_set);
        if(ply_obj_ids !=NULL)
        {
            
            for(i=0; i< set_get_n_ids(ply_set); i++){
                strcat(str,object_get_name(game_get_object(game, ply_obj_ids[i])));
                strcat(str, ", ");
            }
            if(i > 0){
                str[strlen(str)-2] = 0;
            }
            
            
        }
        
    }
    screen_area_puts(ge->descript, str);
    
    sprintf(str, "Player health: %d", player_get_health(game_get_player(game)));
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);

    sprintf(str, "Enemy location: %ld", game_get_enemy_location(game));
    screen_area_puts(ge->descript, str);

    sprintf(str, "Enemy health: %d", enemy_get_health(game_get_enemy(game)));
    screen_area_puts(ge->descript, str);

    /* PAINTS IN THE BANNER AREA */
    screen_area_puts(ge->banner, " Hormiga coge el grano y se va dxcursion ");

    /* PAINTS IN THE HELP AREA */
    screen_area_clear(ge->help);
    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, " move or m followed by next or n, back or b, left or l, right or r; exit or e, take or t, drop or d, inspect or i");
    screen_area_puts(ge->help, str);

    /* PAINTS IN THE FEEDBACK AREA */
    last_cmd = game_get_last_command(game);
    if (command_get_status(last_cmd) == OK)
        sprintf(str, " %s (%s): OK", cmd_to_str[command_get_cmd(last_cmd) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(last_cmd) - NO_CMD][CMDS]);
    else
        sprintf(str, " %s (%s): ERROR", cmd_to_str[command_get_cmd(last_cmd) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(last_cmd) - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);

    /* DUMP TO THE TERMINAL */
    screen_paint();
    printf("prompt:> ");
}
