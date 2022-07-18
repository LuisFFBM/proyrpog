/**
 * @brief functions related to reading files to introduce elements in the game
 *
 * @file game_reader.c
 * @author Álexx y Óskar
 * @version 2.0
 * @date 12-03-2022
 */

#include "../include/game_reader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** reads the data file with spaces and save it in the game structure
 */
STATUS game_reader_load_spaces(Game *game, char *filename)
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID;
    Space *space = NULL;
    STATUS status = OK;
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
            
            
#ifdef DEBUG
            printf("Leido: %ld|%s|\n", id, name);
#endif
            space = space_create(id);
            if (space != NULL)
            {
                space_set_name(space, name);
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
STATUS game_reader_load_objects(Game *game, char *filename)
{
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, act_id = NO_ID;
    Object *object = NULL;
    STATUS status = OK;

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
            act_id = atol(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld\n", id, name, act_id);
#endif
            object = object_create(id, name);
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

STATUS game_reader_load_player(Game *game, char *filename)
{   
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, pos = NO_ID;
    int health, n_obj;
    Player *player = NULL;
    Inventory* rinyo =NULL;
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
            rinyo = inventory_create(n_obj);
            if(rinyo != NULL){
                
                player = player_create(id,name,pos,rinyo,health);
            
                
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


STATUS game_reader_load_link (Game *game, char *filename) {
    #define LINKWORD "#l:"
    Link *link = NULL;
    FILE *file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char *toks = NULL;
    Id id = NO_ID, id_org = NO_ID, id_dest = NO_ID;
    int direccion, estado;
    STATUS status;
    

    if (!game || !filename) {
       
        return ERROR;

    }
    status =OK;

    file = fopen(filename, "r");

    if (file == NULL) {

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

            if (link == NULL) {
                return ERROR;
            }

            link_set_name(link, name);
            link_set_origin(link, id_org);
            link_set_destination(link, id_dest);
            link_set_direction(link, direccion);
            link_set_status(link, estado);

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