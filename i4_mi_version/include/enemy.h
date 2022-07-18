/**
 * @brief It defines the enemy interface
 *
 * @file enemy.h
 * @author Oscar
 * @version 2.0
 * @date 10-03-2022
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"

typedef struct _Enemy Enemy;
/**
 * @brief It creates a new enemy
 * @author Oscar
 *
 * enemy_create allocates memory for a new enemy and initializes
 *  its members with non null values (except of the object that can be null)
 * @param id the identification number for the new enemy
 * @param name the name of the new enemy
 * @param location the location of the new enemy
 * @param object the object of the new enemy
 * @return a new enemy, initialized
 */
Enemy *enemy_create(Id id, char *name, Id location, int health);

/**
 * @brief It destroys an enemy
 * @author Oscar
 *
 * enemy_destroy frees the previous memory allocation
 *  for an enemy
 * @param enemy a pointer to the enemy that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS enemy_destroy(Enemy *enemy);

/**
 * @brief It sets the id of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @param id the new id of the enemy
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS enemy_set_id(Enemy *enemy, Id id);

/**
 * @brief It sets the name of an enemy
 * @author Oscar
 *
 * enemy_set_name allocates memory for the name of
 *  the new enemy
 * @param enemy a pointer to the enemy
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS enemy_set_name(Enemy *enemy, char *name);

/**
 * @brief It sets the location of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @param location the location of the enemy to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS enemy_set_location(Enemy *enemy, Id location);

/**
 * @brief It sets the health of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @param health the health of the enemy to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS enemy_set_health(Enemy *enemy, int health);

/**
 * @brief It gets the id of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @return the id of the enemy
 */
Id enemy_get_id(Enemy *enemy);

/**
 * @brief It gets the name of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @return  a string with the name of the enemy
 */
char *enemy_get_name(Enemy *enemy);

/**
 * @brief It gets the location of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @return the enemy location
 */
Id enemy_get_location(Enemy *enemy);

/**
 * @brief It gets the health of an enemy
 * @author Oscar
 *
 * @param enemy a pointer to the enemy
 * @return the object the enemy has
 */
int enemy_get_health(Enemy *enemy);

/**
 * @brief It prints the enemy information
 * @author Oscar
 *
 * This function shows the id, name, location and object of the enemy
 * @param enemy a pointer to the enemy
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS enemy_print(Enemy *enemy);

#endif
