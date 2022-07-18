/**
 * @brief It defines the Player
 *
 * @file player.h
 * @author Joaquin_Abad
 * @version 1.0
 * @date 15-02-2022
 * @copyright GNU Public License
 */
#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_INITIAL_ID 1
#include "types.h"

typedef struct _Player Player;

/**
  * @brief It creates a new Player
  * @author Joaquin_Abad
  *
  * player_create allocates memory for a new Player
  *  and initializes its members
  * @param id the identification number for the new Player
  * @return a new Player, initialized
  */
Player* player_create(Id id);

/**
  * @brief It destroys a Player
  * @author Joaquin_Abad
  *
  * player_destroy frees the previous memory allocation 
  * for a Player
  * @param ply a pointer to the Player that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_destroy(Player* ply);

/**
  * @brief It gets the id of the Player
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player 
  * @return the id of Player
  */
Id player_get_id(Player* ply);

/**
  * @brief It gets the name of the Player
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player 
  * @return the name of the Player
  */
const char * player_get_name(Player* ply);

/**
  * @brief It gets the id of the Player's location
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player 
  * @return the id of Player's location
  */
Id player_get_location_id(Player* ply);

/**
  * @brief It gets the id of an object taken by the Player
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player 
  * @return the id of an object taken by the Player
  */
Id player_get_object_id(Player* ply);

/**
  * @brief It sets the id of the Player
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player
  * @param id the id to store in the Player
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_set_id(Player* ply, Id id);

/**
  * @brief It sets the name of the Player
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_name(Player* ply, char *name);

/**
  * @brief It sets the id of the Player's location
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player
  * @param id the id to store in the Player's location
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_set_location_id(Player* ply, Id id);

/**
  * @brief It sets the id of an object taken by the Player
  * @author Joaquin_Abad
  * 
  * @param ply a pointer to the Player
  * @param id the id to store in the object taken by the Player
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_set_object_id(Player* ply, Id id);

/**
  * @brief It prints the Player information
  * @author Joaquin_Abad
  *
  * This fucntion shows the name and the ids of the Player
  * @param ply a pointer to the Player
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_print(Player* ply);

#endif