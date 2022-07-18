/** 
 * @brief The Player module
 * 
 * @file Player.c
 * @author Joaquin Abad
 * @version 1.0 
 * @date 14-02-2022
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "types.h"

/**
 * @brief Player
 *
 * This struct stores all the information of the Player.
 */

struct _Player{
    Id id;                      /*!< id of player */
    char name[WORD_SIZE + 1];   /*!< name of player*/
    Id location;                /*!< location of player*/
    Id object;                  /*!<location id of the object of player*/
};

/**  player_create allocates memory for a new Player
  *  and initializes its members
  */
Player* player_create(Id id) {

    Player *newPlayer=NULL;

    /*Error control*/
    if(id== NO_ID)
    {
        return NULL;
    }
    
    newPlayer = (Player*) malloc(sizeof(Player));

    if(newPlayer==NULL)
    {
        return NULL;
    }

    /*Initialization of the members*/
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->location = NO_ID;
    newPlayer->object = NO_ID;
    
    return newPlayer;
}

/** player_destroy frees the previous memory allocation 
  *  for the Player
  */
STATUS player_destroy(Player* ply) {

    if(ply == NULL)
    {
        return ERROR;
    }

    free(ply);
    ply = NULL;

    return OK;
}


/** It gets the id of the Player
  */
Id player_get_id(Player* ply) {

    if(ply == NULL)
    {
        return NO_ID;
    }

    return ply->id;
}

/** It gets the name of the Player
  */
const char * player_get_name(Player* ply) {

    if(ply == NULL)
    {
        return NULL;
    }

    return ply->name;
}

/** It gets the id of the location of Player
  */
Id player_get_location_id(Player* ply) {

    if(ply == NULL)
    {
        return NO_ID;
    }

    return ply->location;
}

/** It gets the id of the object taken by the Player
  */
Id player_get_object_id(Player* ply) {

    if(ply == NULL)
    {
        return NO_ID;
    }

    return ply->object;
}

/** It set the id of the Player
  */
STATUS player_set_id(Player* ply, Id id) {

    if( !ply || id == NO_ID)
    {
        return ERROR;
    }

    ply->id = id;

    return OK;
}

/** It set the name of the Player
  */
STATUS player_set_name(Player* ply, char *name) {

    if( !ply || !name)
    {
        return ERROR;
    }

    if(!strcpy(ply->name, name))
    {
        return ERROR;
    };

    return OK;
}

/** It set the id of the location of Player
  */
STATUS player_set_location_id(Player* ply, Id id) {

    if( !ply || id == NO_ID)
    {
        return ERROR;
    }

    ply->location = id;

    return OK;
}

/** It set the id of the object taken by the Player
  */
STATUS player_set_object_id(Player* ply, Id id) {

    if( !ply || id == NO_ID)
    {
        return ERROR;
    }

    ply->object = id;

    return OK;
}

/** It prints the Player information
  */ 
STATUS player_print(Player* ply) {

    /* Error control */
    if(ply == NULL)
    {
        return ERROR;
    }
/*print de name and the id's of the Player*/
    
    fprintf(stdout,"--> Player (Id: %ld; Name: %s; Location id: %ld; Object id: %ld)\n", ply->id, ply->name, ply->location, ply->object);

   return OK;

}
