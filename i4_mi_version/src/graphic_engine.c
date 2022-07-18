/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG, Luis, Óskar, Álexx
 * @version 4.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/graphic_engine.h"
#include "../include/libscreen.h"


#define LINE_SIZE 511       /*!< LINE SIZE */
#define MAX_MAP_STRING 20   /*!< NUMBER MAX OF THE MAP STRING*/
#define MAX_ENEMY 7         /*!< MAX ENEMY size in number of characters*/

/*macros de formato*/

#define MAP_ROWS 29         /*!< NUMBER OF MAP & DESCRPTIONS ROWS */
#define MAP_COLS 50         /*!< NUMBER OF MAP COLUMNS */
#define DESC_COLS 50        /*!< NUMBER OF DESCRIPTION COLUMNS */
#define DESC_ROWS 20        /*!< NUMBER OF DESCRIPTION ROWS */
#define INTER_ROWS 1        /*!< NUMBER OF INTER LINE BETWEEN ROWS */
#define INTER_COLS 1        /*!< NUMBER OF INTER LINE BETWEEN COLS */
#define HELP_ROWS 6         /*!< NUMBER OF HELP ROWS */
#define HELP_COLS 101       /*!< NUMBER OF HELP & FEEDBACK COLUMNS */
#define FEEDBACK_ROWS 3     /*!< NUMBER OF FEEDBACK ROWS */
#define BANNER_COLS 80      /*!< NUMBER OF BANNER COLUMNS */
#define BANNER_ROWS 1       /*!< NUMBER OF BANNER ROWS */
#define BANNER_POS_X 12     /*!< POSITION OF THE BANNER COLS*/
#define ROWS 42             /*!< NUMBER OF TOTAL ROWS*/
#define COLUMNS 103         /*!< NUMBER OF TOTAL COLUMNS */






/**
 * @brief structure that stores the interface parameters
 */
struct _Graphic_engine
{
    Area *map;          /*!< a pointer to the area of the map of the game*/
    Area *descript;     /*!< a pointer to the area of the descrpit of the game*/
    Area *space_desc;     /*!< a pointer to the area of the descrpit of the objects and spaces*/
    Area *banner;       /*!< a pointer to the area of the banner of the game*/
    Area *help;         /*!< a pointer to the area of the help banner of the game*/
    Area *feedback;     /*!< a pointer to the area of the feedback banner of the game*/
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
    ge->banner = screen_area_init(BANNER_POS_X,0, BANNER_COLS, BANNER_ROWS);
    ge->map = screen_area_init(INTER_COLS, (BANNER_ROWS+(1*INTER_ROWS)), MAP_COLS, MAP_ROWS);
    ge->descript = screen_area_init((MAP_COLS+(2*INTER_COLS)), (BANNER_ROWS+(1*INTER_ROWS)), DESC_COLS, DESC_ROWS);
    ge->space_desc = screen_area_init((MAP_COLS+(2*INTER_COLS)), (BANNER_ROWS+DESC_ROWS+(2*INTER_ROWS)), DESC_COLS, (MAP_ROWS-DESC_ROWS-INTER_ROWS));
    ge->help = screen_area_init(INTER_COLS, (MAP_ROWS+(3*INTER_ROWS)), HELP_COLS, HELP_ROWS);
    ge->feedback = screen_area_init(INTER_COLS, (MAP_ROWS+HELP_ROWS+(4*INTER_ROWS)), HELP_COLS, FEEDBACK_ROWS);

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
    screen_area_destroy(ge->space_desc);
    screen_area_destroy(ge->banner);
    screen_area_destroy(ge->help);
    screen_area_destroy(ge->feedback);


    screen_destroy();
    free(ge);
}
/**
 * it prints the object list part of a space
*/
void graphic_engine_paint_object_part(Graphic_engine *ge, Game*game,Id id_space);

/**
 * It returns the enemy string with the enemy if the enemy is in the space
*/
char* _sprint_enemy(Game *game, Id enem_loc, char *new_enemy);

/**
 * It paints the gdesc part
*/
void graphic_engine_paint_gdesc(Game *game, Graphic_engine *ge, Id id_space);
/**
 * It prints the objects locations in the description area 
*/
void graphic_engine_print_object_locations(Game *game, Graphic_engine *ge, char*str,Id id_act);

/**
 * It prints the player enemy and space id part when theres a player
*/
void graphic_engine_print_id_space_line(Graphic_engine *ge,Game *game, Id id_space, BOOL player);

/**
 * It prints the north and south border lines 
*/
void graphic_engine_print_line(Graphic_engine *ge);

/** It prints all the screen areas with the game information
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
    Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID;
    char str[LINE_SIZE];
    Command *last_cmd /*= command_create()*/;
    extern char *cmd_to_str[N_CMD][N_CMDT];    
    Set *ply_set = NULL;
    Id*ply_obj_ids = NULL;
    int i=0, n_objs=0;
    
    /* PAINTS IN THE MAP AREA */
    screen_area_clear(ge->map);
    if ((id_act = game_get_player_location(game)) != NO_ID)
    {
        
        id_back = game_get_connection(game,id_act,N);
        id_next =  game_get_connection(game,id_act,S);
        

        /* Prints the space above */
        if (id_back != NO_ID)
        {

            graphic_engine_print_line(ge);

            graphic_engine_print_id_space_line(ge,game,id_back,FALSE);
            graphic_engine_paint_gdesc(game,ge,id_back);
            graphic_engine_paint_object_part(ge,game,id_back);

            graphic_engine_print_line(ge);
            
            if(game_get_connection_status(game,id_act,N) == TRUE)
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
            graphic_engine_print_line(ge);
            
            graphic_engine_print_id_space_line(ge,game,id_act, TRUE);

            graphic_engine_paint_gdesc(game,ge,id_act);
            
            graphic_engine_paint_object_part(ge,game,id_act);

            graphic_engine_print_line(ge);
        }

        /* Prints the space below */
        if (id_next != NO_ID)
        {
            if(game_get_connection_status(game,id_act,S) == TRUE)
            {
                sprintf(str, "        v");
                screen_area_puts(ge->map, str);
            }
            else
            {
                sprintf(str, "        -");
                screen_area_puts(ge->map, str);   
            }
            
            graphic_engine_print_line(ge);

            graphic_engine_print_id_space_line(ge,game,id_next, FALSE);
            graphic_engine_paint_gdesc(game,ge,id_next);
            graphic_engine_paint_object_part(ge,game,id_next);

            graphic_engine_print_line(ge);
        }
    }

    /* PAINTS IN THE DESCRIPTION AREA */
    screen_area_clear(ge->descript);

    sprintf(str, " Objects nearby:");
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    
    graphic_engine_print_object_locations(game, ge, str,id_act);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);

    /*Player info*/
    sprintf(str, " Player location: %ld", player_get_location(game_get_player(game)));
    screen_area_puts(ge->descript, str);
    
    sprintf(str, " Player objects: ");
     screen_area_puts(ge->descript, str);
    ply_set = player_get_objects_inventory(game_get_player(game));
    if(ply_set != NULL)
    {
        ply_obj_ids = set_get_ids(ply_set);
        if(ply_obj_ids !=NULL)
        {
            
            for(i=0; i< set_get_n_ids(ply_set); i++, n_objs++){
                sprintf(str, "  ");
                strcat(str,object_get_name(game_get_object(game, ply_obj_ids[i])));

                screen_area_puts(ge->descript, str);
            }
            
            
            
            
        }
        
    }
    
    
    sprintf(str, " Player health: %d", player_get_health(game_get_player(game)));
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);

    /*Enemy info*/
    sprintf(str, " Enemy location: %ld", game_get_enemy_location(game));
    screen_area_puts(ge->descript, str);

    sprintf(str, " Enemy health: %d", enemy_get_health(game_get_enemy(game)));
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);
    
    /*Space description*/
    sprintf(str, " %s", space_get_description_short(game_get_space(game, id_act)));
    screen_area_puts(ge->descript, str);

    sprintf(str, " ");
    screen_area_puts(ge->descript, str);

    /*Inspect Description*/
    screen_area_clear(ge->space_desc);

    sprintf(str, " %s", command_get_description_large(game_get_last_command(game)));
    screen_area_puts(ge->space_desc, str);

    /* PAINTS IN THE BANNER AREA */
    screen_area_puts(ge->banner, "  Hormiga coge el grano y se va de excursion ");

    /* PAINTS IN THE HELP AREA */
    screen_area_clear(ge->help);
    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, "   move or m followed by south or s, north or n, west or w, east or e, up or u, down or d;exit or e; take or t, drop or d followed by an object name to take or drop;attack or a;inspect or i followed by s or space or an object name;open or o followed by with and an object name" );
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
    printf(" prompt:> ");
}

char* _sprint_enemy(Game *game, Id enem_loc, char* new_enemy){
   

    if(game_get_enemy_location(game) == enem_loc && enemy_get_health(game_get_enemy(game)) > 0)
    {
        sprintf(new_enemy, "/\\oo/\\");  
    }
    else
    {
        sprintf(new_enemy, "      ");
    }

    return new_enemy;
}

void graphic_engine_paint_object_part(Graphic_engine *ge, Game*game,Id id_space){ 
    
    char obj_part[LINE_SIZE];
    char aux_list[LINE_SIZE];
    Object **objects = NULL;
    Id obj_loc = NO_ID;
    BOOL full = FALSE, open = FALSE;
    int i, object_n_ids=0;

    if(game_get_connection(game,id_space,W) != NO_ID)
    {

        open = game_get_connection_status(game, id_space, W);

        if (open == TRUE)
            sprintf(obj_part, "<<|");
        else
            sprintf(obj_part, "--|");   

    }
    else
    {
        sprintf(obj_part, "  |"); 
    }
    
    /*write the object list*/
    objects = game_get_objects(game);

    object_n_ids = set_get_n_ids(space_get_objects(game_get_space(game, id_space)));



    for (full = FALSE, i = 0; i < MAX_OBJECTS && objects[i] != NULL && full == FALSE && object_n_ids > 0; i++)
    {
        obj_loc = game_get_object_location(game, object_get_id(objects[i]));

        if (obj_loc == id_space)
        {
        
            sprintf(aux_list, "%s, ", object_get_name(objects[i]));
            if((strlen(obj_part) + strlen(aux_list)) < (MAX_MAP_STRING-1)){
                strcat(obj_part, aux_list);  
            }
            else if(obj_loc != NO_ID){
                
                full = TRUE;
            }
            
        }
    }

    if(full == TRUE ){

        obj_part[(strlen(obj_part)-2)] = 0;

        strcat(obj_part, "...");
        while(strlen(obj_part) <= MAX_MAP_STRING){
            strcat(obj_part, " ");
        }                
    }
    else{
        if(strlen(obj_part)>3){
            obj_part[(strlen(obj_part)-2)] = 0;

            while(strlen(obj_part) <= MAX_MAP_STRING ){
            strcat(obj_part, " ");
            } 
        }
        else{
            while(strlen(obj_part) <= MAX_MAP_STRING ){
            strcat(obj_part, " ");
            } 
        }   
        
    }
    /*finish writing the object list*/

    if(game_get_connection(game,id_space,E) != NO_ID)
    {

        open = game_get_connection_status(game, id_space, E);

        if (open == TRUE)
            strcat(obj_part, "|>>");
        else
            strcat(obj_part, "|--");   

    }
    else
    {
        strcat(obj_part, "|  "); 
    }

    screen_area_puts(ge->map, obj_part);

}

void graphic_engine_paint_gdesc(Game *game, Graphic_engine *ge, Id id_space){
    
    
    char str[LINE_SIZE], aux[LINE_SIZE];   
    int i=0, j=0, gdesc=0;

    if(space_get_light(game_get_space(game, id_space))==TRUE || game_inventory_objects_are_iluminated(game) == TRUE)
    {
        for(i=0; i<NROWS; i++){
            
            sprintf(str, "  |");

            gdesc = sprintf(aux, "%s", space_get_gdesc(game_get_space(game, id_space),i));
            strcat(str, aux);
            
            for(j=1; j<(MAX_MAP_STRING-gdesc-1); j++){
                strcat(str, " ");
            }
            strcat(str, "|  ");
            screen_area_puts(ge->map, str);
        }
    }
    else 
    {
        for(i=0;i<NROWS;i++){
            
            sprintf(str, "  |");

            for(j=0, gdesc=0;j<NCOLS;j++, gdesc ++){
                strcat(str, "#");
            }
            
            for(j=1; j<(MAX_MAP_STRING-gdesc-1); j++){
                strcat(str, " ");
            }
            strcat(str, "|  ");
            screen_area_puts(ge->map, str);
        }
    }
}

void graphic_engine_print_object_locations(Game *game, Graphic_engine *ge, char*str,Id id_act){
    int i=0;
    Object **objects;
    Id obj_loc = NO_ID, id_back, id_next, id_right, id_left, id_up, id_down;

    id_back = game_get_connection(game,id_act,N);
    id_next =  game_get_connection(game,id_act,S);
    id_right =  game_get_connection(game,id_act,E);
    id_left =  game_get_connection(game,id_act,W);
    id_up =  game_get_connection(game,id_act,U);
    id_down =  game_get_connection(game,id_act,D);
    

    objects = game_get_objects(game);

    for (i = 0; i < MAX_OBJECTS && objects[i] != NULL; i++)
    {   
        obj_loc = game_get_object_location(game, object_get_id(objects[i]));
        if(obj_loc != NO_ID)
        {
            
            if( obj_loc == id_act || obj_loc == id_back || obj_loc == id_next || obj_loc == id_right || obj_loc == id_left || obj_loc == id_up || obj_loc == id_down )
            {
                
                sprintf(str, "   %s:%ld", object_get_name(objects[i]), game_get_object_location(game, object_get_id(objects[i])));

                screen_area_puts(ge->descript, str);
                
            }
                
            
        }
        
        
    }

    
}

void graphic_engine_print_line(Graphic_engine *ge){
    int i=0;
    char str[LINE_SIZE];

    sprintf(str, "  +");
    for(i=1; i<(MAX_MAP_STRING-1); i++){
        strcat(str, "-");
    }
    strcat(str, "+  ");
    screen_area_puts(ge->map, str);
}

void graphic_engine_print_id_space_line(Graphic_engine *ge,Game *game, Id id_space, BOOL player){
    int i=0, count=0;
    char aux[MAX_MAP_STRING], str[LINE_SIZE], enemy[MAX_ENEMY];
    Id id_up = NO_ID, id_down = NO_ID;
    BOOL open_up = FALSE, open_down = FALSE;

    id_up = game_get_connection(game,id_space,U);
    id_down = game_get_connection(game,id_space,D);
    open_up = game_get_connection_status(game, id_space, U);
    open_down = game_get_connection_status(game, id_space, D);

    if(id_up != NO_ID){
        if(open_up == TRUE){
            sprintf(str, " o|");
        }
        else{
            sprintf(str, " x|");
        }
    }
    else{
        sprintf(str, "  |");
    }

    
    if(player == TRUE)
    {
        strcat(str, " m^ ");
    }
    else
    {
        strcat(str, "    ");
    }
    count = strlen(strcat(str, _sprint_enemy(game, id_space ,enemy)));
    for(i=0; i<MAX_MAP_STRING-count-3; i++){
        strcat(str, " ");
    }
    sprintf(aux, " %3d",(int)id_space);
    strcat(str,aux);

    if(id_down != NO_ID){
        if(open_down == TRUE){
            strcat(str, "|ov");
        }
        else{
            strcat(str, "|xv");
        }
    }
    else{
        strcat(str, "|  ");
    }

    screen_area_puts(ge->map, str);
}