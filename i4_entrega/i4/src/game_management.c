/**
 * @brief functions related to reading files to introduce elements in the game
 *
 * @file game_management.c
 * @author Álexx, Oskar, Luis, Joaquin
 * @version 2.0
 * @date 24-04-2022
 */

#include "../include/game_management.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/** reads the data file with spaces and save it in the game structure
 */
STATUS game_management_load_spaces(Game *game, char *filename) 
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char description_short[SIZE_SHORT_DESC] = "";
    char description_long[SIZE_LONG_DESC] = "";
    char *toks = NULL;
    Id id = NO_ID;
    Space *space = NULL;
    STATUS status = OK;
    BOOL light = FALSE;
    int i=0;
    
    if (!filename || !game)
    {
        
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#s:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            strcpy(description_short, toks);
            toks = strtok(NULL, "|");
            strcpy(description_long, toks);
            toks = strtok(NULL, "|");
            light = atoi(toks);
            
            
#ifdef DEBUG
            printf("Leido: %ld|%s|\n", id, name);
#endif
            space = space_create(id);
            if (space != NULL)
            {
                space_set_name(space, name);
                space_set_description_short(space, description_short);
                space_set_description_large(space, description_long);
                space_set_light(space, light);

                for (i = 0; i < NROWS; i++)
                {
                    toks = strtok(NULL, "|");
                    if (toks != NULL)
                    {
                        space_set_gdesc(space, toks,i);
                    }
#ifdef DEBUG
                printf("%s\n", toks);
#endif
                }
               
                game_add_space(game, space);
            }
        }
    }

    if (ferror(file))
    {
        
        status = ERROR;
    }

    fclose(file);
    
    return status;
}

/** reads the data file with objects and save it in the game structure
 */
STATUS game_management_load_objects(Game *game, char *filename)
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char description[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, act_id = NO_ID;
    Object *object = NULL;
    STATUS status = OK;
    BOOL movable;
    Id despendency;
    Id open;
    BOOL iluminate;
    BOOL turnedon;

    if (!filename || !game)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#o:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            strcpy(description, toks);
            toks = strtok(NULL, "|");
            movable = atol(toks);
            toks = strtok(NULL, "|");
            despendency = atol(toks);
            toks = strtok(NULL, "|");
            open = atol(toks);
            toks = strtok(NULL, "|");
            iluminate = atol(toks);
            toks = strtok(NULL, "|");
            turnedon = atol(toks);
            toks = strtok(NULL, "|");
            act_id = atol(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld\n", id, name, act_id);
#endif
            object = object_create(id, name);
            object_set_description(object, description);
            object_set_movable(object, movable);
            object_set_dependency(object, despendency);
            object_set_open(object, open);
            object_set_iluminate(object, iluminate);
            object_set_turnedon(object, turnedon);
        
            if (object != NULL)
            {
                game_add_object(game, object, act_id, name);
            }
        }
    }

    if (ferror(file))
    {
        status = ERROR;
    }

    fclose(file);

    return status;
}

/** reads the data file with player and save it in the game structure
 */
STATUS game_management_load_player(Game *game, char *filename)
{   
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, pos = NO_ID;
    int health =0, n_obj;
    Player *player = NULL;
    Inventory* inv =NULL;
    STATUS status =OK;

    if (!filename || !game)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#p:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            pos = atol(toks);
            toks = strtok(NULL, "|");
            health = atoi(toks);
            toks = strtok(NULL, "|");
            n_obj = atoi(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld\n", id, name, act_id);
#endif
            inv = inventory_create(n_obj);
            if(inv != NULL){
                
                player = player_create(id,name,pos,inv,health);
            
                
                if(player!=NULL){
                    game_add_player(game,player);
                }else{
                    status =ERROR;
                }
            }else{
                return ERROR;
            }
        }
    }
    if (ferror(file))
    {
        status = ERROR;
    }
    

    fclose(file);

    return status; 
    }

/** reads the data file with enemy and save it in the game structure
 */
STATUS game_management_load_enemy(Game *game, char *filename)
{   
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, pos = NO_ID;
    int health;
    Enemy *enemy = NULL;
    STATUS status =OK;

    if (!filename || !game)
    {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file))
    {
        if (strncmp("#e:", line, 3) == 0)
        {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            pos = atol(toks);
            toks = strtok(NULL, "|");
            health = atoi(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld\n", id, name, act_id);
#endif
            
            
                
            enemy = enemy_create(id,name,pos,health);
        
            
            if(enemy!=NULL)
            {
                game_add_enemy(game,enemy);
            }
            else
            {
                status = ERROR;
            }
            
        }
    }
    if (ferror(file))
    {
        status = ERROR;
    }
    

    fclose(file);

    return status; 
}

/** reads the data file with the links and save it in the game structure
 */
STATUS game_management_load_link (Game *game, char *filename) {
    
    Link *link = NULL;
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, id_org = NO_ID, id_dest = NO_ID;
    int direccion, estado;
    STATUS status;
    

    if (!game || !filename) 
    {
       
        return ERROR;

    }
    status =OK;

    file = fopen(filename, "r");

    if (file == NULL) 
    {

        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#l:", line, 3)==0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            id_org = atol(toks);
            toks = strtok(NULL, "|");
            id_dest = atol(toks);
            toks = strtok(NULL, "|");
            direccion = atoi(toks);
            toks = strtok(NULL, "|");
            estado = atoi(toks);
            #ifdef DEBUG
                printf("Leido: %ld|%s|%ld|%ld|%ld|%d|%d\n", id, name, id_org, id_dest, direccion, estado);       
            #endif
            link = link_create(id);

            if (link == NULL) 
            {
                return ERROR;
            }

            link_set_name(link, name);
            link_set_origin(link, id_org);
            link_set_destination(link, id_dest);
            link_set_direction(link, direccion);
            link_set_open(link, estado);

            game_add_link(game, link);
        }
        if (ferror(file))
        {
            status = ERROR;
        }
    }

    

    fclose(file);

    return status;
}



/** reads the data file with the dialogues and save it in the game structure
 */

/*
STATUS game_management_load_dialogue (Game *game, char *filename) {
    
    Dialogue *d = NULL;
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char *toks = NULL, *cmd_res[MAX_CMD_RES];
    int i = 0;
    T_Command cmd = NO_CMD;
    STATUS cmd_st = ERROR;
    STATUS st = OK;
    

    if (!game || !filename) 
    {
       
        return ERROR;

    }

    file = fopen(filename, "r");

    if (file == NULL) 
    {

        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#m:", line, 3)==0) {
            toks = strtok(line + 3, "|");
            cmd = (T_Command)toks;
            toks = strtok(NULL, "|");
            cmd_st = (STATUS)toks;
            for(i=0;(toks = strtok(NULL,"|")) != NULL; i++){
                strcpy(cmd_res[i], toks);
            }
            #ifdef DEBUG
                
                printf("Leido: %d|%d|", cmd, cmd_st);
                for(i=0; i<MAX_CMD_RES; i++){
                    printf("%s|", cmd_res[i]);
                }
                printf("\n");

            #endif
            d = dialogue_create(cmd);
            if (d == NULL) 
            {
                return ERROR;
            }
            
            dialogue_set_cmd_st(d, cmd_st);
            for(i=0; i<MAX_CMD_RES; i++){
                dialogue_set_frase(d, cmd_res[i]);
            }

            st = game_add_dialogue(game, d);
        }
        if (ferror(file))
        {
            st = ERROR;
        }
    }

    fclose(file);

    return st;
}
 */

/**
 * starts writing in the file
*/
/*
STATUS game_management_save_start(Game *game, char *filename)
{
    FILE *file = NULL;

    if(game == NULL || filename == NULL) 
    {
        return ERROR; 
    }
    
    file = fopen(filename, "w");
    if(file == NULL){
        return ERROR;
    }

    fprintf(file,"\n");

    if (ferror(file))
    {
        fclose(file);
        return ERROR;
    }

    return OK;
}
*/

/** reads the spaces in game structure data and saves them in the designated file
 */
/*
STATUS game_management_save_spaces(Game *game, char *filename) {
    
    FILE *file = NULL;
    Space **space;
    Id id_space = NO_ID;
    char* name_space = "vacio", *desc_space = "no desc";
    char **gdesc;
    int i=0, j=0;
    STATUS status = OK;

    
    if (!game || !filename) 
    {
       
        return ERROR;

    }

    file = fopen(filename, "a");

    if (file == NULL) 
    {

        return ERROR;
    }

    space = game_get_spaces(game);

    for(i=0; i<MAX_SPACES && space[i] != NULL; i++){
        fprintf(file, "#s:");

        id_space = space_get_id(space[i]);
        fprintf(file, "%ld|", id_space);

        name_space = space_get_name(space[i]);
        fprintf(file, "%s|", name_space);

        desc_space = space_get_description_short(space[i]);
        fprintf(file, "%s|", desc_space);

        for(j=0; j<NROWS; j++){
            gdesc[j] = space_get_gdesc(space[i], j);
            fprintf(file, "%s|", gdesc[j]);
        }

        fprintf(file, "\n");

    }

    fprintf(file, "\n");

    if (ferror(file))
    {
        
        status = ERROR;
    }

    fclose(file);
    
    return status;

}
*/


/** reads the object in game structure data and saves them in the designated file
 */
/*
STATUS game_management_save_objects(Game *game, char *filename) {
    
    FILE *file = NULL;
    Object **object;
    Id id_object = NO_ID;
    char* name_object = "ninguno", *desc_object = "???";
    BOOL movable;
    Id despendency;
    Id open;
    BOOL iluminate;
    BOOL turnedon;
    Id loc_object = NO_ID;
    int i=0;
    STATUS status = OK;

    if (!game || !filename) 
    {
       
        return ERROR;

    }

    file = fopen(filename, "a");

    if (file == NULL) 
    {

        return ERROR;
    }

    object = game_get_objects(game);

    for(i=0; i<MAX_OBJECTS && object[i] != NULL; i++){
        fprintf(file, "#o:");

        id_object = object_get_id(object[i]);
        fprintf(file, "%ld|", id_object);

        name_object = object_get_name(object[i]);
        fprintf(file, "%s|", name_object);

        desc_object = object_get_description(object[i]);
        fprintf(file, "%s|", desc_object);

        movable = object_get_movable(object[i]);
        fprintf(file, "%d|", movable);

        despendency = object_get_dependency(object[i]);
        fprintf(file, "%ld|", despendency);

        open = object_get_open(object[i]);
        fprintf(file, "%ld|", open);

        iluminate = object_get_iluminate(object[i]);
        fprintf(file, "%d|", iluminate);

        turnedon = object_get_turnedon(object[i]);
        fprintf(file, "%d|", turnedon);

        loc_object = game_get_object_location(game, object[i]);
        fprintf(file, "%ld|", loc_object);

        fprintf(file, "\n");

    }

    fprintf(file, "\n");

    if (ferror(file))
    {
        
        status = ERROR;
    }

    fclose(file);
    
    return status;
}
*/

/** reads the player in game structure data and saves it in the designated file
 */
/*
STATUS game_management_save_player(Game *game, char *filename) {
    
    FILE *file = NULL;
    Player* player = NULL;
    Id id_player = NO_ID;
    char* name_player = "don pepito";
    Id loc_player = NO_ID;
    int health_player = -1, n_objs_player = 0;
    STATUS status = OK;

    if (!game || !filename) 
    {
       
        return ERROR;

    }

    file = fopen(filename, "a");

    if (file == NULL) 
    {

        return ERROR;
    }

    player = game_get_player(game);

   
    fprintf(file, "#p:");

    id_player = player_get_id(player);
    fprintf(file, "%ld|", id_player);

    name_player = player_get_name(player);
    fprintf(file, "%s|", name_player);

    loc_player = game_get_player_location(game);
    fprintf(file, "%ld|", loc_player);

    health_player = player_get_health(player);
    fprintf(file, "%d|", health_player);

    n_objs_player = inventory_get_n_objs(player_get_inventory(player));
    fprintf(file, "%d|", n_objs_player);

    fprintf(file, "\n");

    fprintf(file, "\n");


    if (ferror(file))
    {
        
        status = ERROR;
    }

    fclose(file);
    
    return status;
}
*/

/** reads the enemy in game structure data and saves it in the designated file
 */
/*
STATUS game_management_save_enemy(Game *game, char *filename) {
      
    FILE *file = NULL;
    Player* enemy = NULL;
    Id id_enemy = NO_ID;
    char* name_enemy = "don pepito";
    Id loc_enemy = NO_ID;
    int health_enemy = -1;
    STATUS status = OK;

    if (!game || !filename) 
    {
       
        return ERROR;

    }

    file = fopen(filename, "a");

    if (file == NULL) 
    {

        return ERROR;
    }

    enemy = game_get_enemy(game);

   
    fprintf(file, "#e:");

    id_enemy = enemy_get_id(enemy);
    fprintf(file, "%ld|", id_enemy);

    name_enemy = enemy_get_name(enemy);
    fprintf(file, "%s|", name_enemy);

    loc_enemy = game_get_enemy_location(game);
    fprintf(file, "%ld|", loc_enemy);

    health_enemy = enemy_get_health(enemy);
    fprintf(file, "%d|", health_enemy);

    fprintf(file, "\n");

    fprintf(file, "\n");

    if (ferror(file))
    {
        
        status = ERROR;
    }

    fclose(file);
    
    return status;
}*/

/** reads the links in game structure data and saves them in the designated file
 */

/*
STATUS game_management_save_link (Game *game, char *filename) {
    
    FILE *file = NULL;
    Link **link;
    char* name_link = "link";
    Id id_link = NO_ID, ori_link = NO_ID, dest_link = NO_ID;
    DIRECTION direction_link = NO_DIR;
    BOOL open_link = FALSE;
    STATUS status = OK;
    int i=0;

    if (!game || !filename) 
    {
       
        return ERROR;

    }

    file = fopen(filename, "a");

    if (file == NULL) 
    {

        return ERROR;
    }

    link = game_get_links(game);

    for(i=0; i<MAX_LINKS && link[i] != NULL; i++){
        
        fprintf(file, "#l:");

        id_link = link_get_id(link[i]);
        fprintf(file, "%ld|", id_link);

        name_link = link_get_name(link[i]);
        fprintf(file, "%s|", name_link);

        ori_link = link_get_origin(link[i]);
        fprintf(file, "%ld|", ori_link);

        dest_link = link_get_destination(link[i]);
        fprintf(file, "%ld|", dest_link);

        direction_link = link_get_direction(link[i]);
        fprintf(file, "%d|", direction_link);

        open_link = link_get_open(link[i]);
        fprintf(file, "%d|", open_link);
        

        fprintf(file, "\n");
    }

    fprintf(file, "\n");

    if (ferror(file))
    {
        
        status = ERROR;
    }

    fclose(file);
    
    return status;

}
*/
/** reads the dialogue of the game structure and save it in the designated file
*/
/*
STATUS game_management_save_dialogue (Game *game, char *filename);
*/