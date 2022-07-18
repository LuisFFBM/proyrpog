/**
 * @brief It defines the player interface
 *
 * @file player.h
 * @author Javii, Óskar, Álexx
 * @version 4.3
 * @date 17-03-2022
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "object.h"
#include "inventory.h"

typedef struct _Player Player;

/**
 * @brief It creates a new player
 * @author Javii
 *
 * player_create allocates memory for a new player and initializes
 *  its members with non null values
 * @param id the identification number for the new player
 * @param name the name of the new player
 * @param location the location of the new player
 * @param rinyo the player's inventory with an objects' set
 * @param health the health of the new player
 * @return a new player, initialized
 */
Player *player_create(Id id, char *name, Id location, Inventory *rinyo, int health);

/**
 * @brief It destroys a player
 * @author Javii
 *
 * player_destroy frees the previous memory allocation
 *  for a player
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_destroy(Player *player);

/**
 * @brief It sets the id of a player
 * @author Javii
 *
 * @param player a pointer to the player
 * @param id the new id of the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_id(Player *player, Id id);

/**
 * @brief It sets the name of a player
 * @author Javii
 *
 * player_set_name allocates memory for the name of
 *  the new player
 * @param player a pointer to the player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_name(Player *player, char *name);

/**
 * @brief It sets the location of a player
 * @author Javii
 *
 * @param player a pointer to the player
 * @param location the location of the player to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_location(Player *player, Id location);

/**
 * @brief It sets the inventory of a player
 * @author Alexx
 *
 * @param player a pointer to the player
 * @param rinyo the inventory of the player to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_inventory(Player *player, Inventory *rinyo);

/**
 * @brief Adds an object to La riño
 * @author Alexx
 *
 * @param player a pointer to the player
 * @param object an object to set in La riño
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_add_object_inventory(Player *player, Id object);

/**
 * @brief Removes an object from La riño
 * @author Alexx
 *
 * @param player a pointer to the player
 * @param object an object to remove from La riño
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_del_object_inventory(Player *player, Id object);

/**
 * @brief It gets the objects set of La riño
 * @author Alexx
 *
 * @param player a pointer to the player
 * @return the objects set of La riño
 */
Set *player_get_objects_inventory(Player *player);

/**
 * @brief Checks if an object is La rinyo of a player
 * @author Alexx
 * 
 * @param player a pointer to the player
 * @param object 
 * @return TRUE or FALSE
 */
BOOL player_id_in_inventory(Player *player, Id object);

/**
 * @brief It gets if the player's inventory is full
 * @author Joaquin Abad Diaz
 *
 * @param player a pointer to the player
 * @return TRUE if the player's inventory is full or FALSE in any other case
 */
BOOL player_inventory_is_full(Player *player);

/**
 * @brief It sets the health of a player
 * @author Óskar
 *
 * @param player a pointer to the player
 * @param health the health of the player to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_set_health(Player *player, int health);

/**
 * @brief It gets the id of a player
 * @author Javii
 *
 * @param player a pointer to the player
 * @return the id of the player
 */
Id player_get_id(Player *player);

/**
 * @brief It gets the name of a player
 * @author Javii
 *
 * @param player a pointer to the player
 * @return  a string with the name of the player
 */
char *player_get_name(Player *player);

/**
 * @brief It gets the location of a player
 * @author Javii
 *
 * @param player a pointer to the player
 * @return the player location
 */
Id player_get_location(Player *player);


/**
 * @brief It gets the inventory of a player
 * @author Alexx
 *
 * @param player a pointer to the player
 * @return the player's inventory
 */
Inventory *player_get_inventory(Player *player);

/**
 * @brief It gets the health of a player
 * @author Óskar
 *
 * @param player a pointer to the player
 * @return the player's health (int)
 */
int player_get_health(Player *player);

/**
 * @brief It prints the player information
 * @author Óskar
 *
 * This function shows the id, name, location, object and health of the player
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS player_print(Player *player);

#endif