/**
 * @brief It defines the Enemy
 *
 * @file enemy.h
 * @author Luis Fernandez
 * @version 1.0
 * @date 23-02-2022
 * @copyright GNU Public License
 */
#ifndef ENEMY_H
#define ENEMY_H
#define ENEMY_INITIAL_ID 1
#define ENEMY_HP 7
#include "types.h"

typedef struct _Enemy Enemy;

/**
  * @brief It creates a new Enemy
  * @author Luis Fernandez
  *
  * enemy_create allocates memory for a new Enemy
  *  and initializes its members
  * @param id the identification number for the new Enemy
  * @return a new Enemy, initialized
  */
Enemy* enemy_create(Id id);

/**
  * @brief It destroys a Enemy
  * @author Luis Fernandez
  *
  * enemy_destroy frees the previous memory allocation 
  * for a Enemy
  * @param enem a pointer to the Enemy that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_destroy(Enemy* enem);

/**
  * @brief It gets the id of the Enemy
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy 
  * @return the id of Enemy, if everything goes well or NO_ID if there was some mistake
  */
Id enemy_get_id(Enemy* enem);

/**
  * @brief It gets the name of the Enemy
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy 
  * @return the name of the Enemy, if everything goes well or NO_ID if there was some mistake
  */
const char * enemy_get_name(Enemy* enem);

/**
  * @brief It gets the id of the Enemy's location
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy 
  * @return the id of Enemy's location, if everything goes well or NULL if there was some mistake
  */
Id enemy_get_location(Enemy* enem);

/**
  * @brief It gets the health of the Enemy
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy 
  * @return the health value of the Enemy, if everything goes well or NO_ID if there was some mistake
  */
long int enemy_get_health(Enemy* enem);

/**
  * @brief It sets the id of the Enemy
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy
  * @param id the id to store in the Enemy
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_set_id(Enemy* enem, Id id);

/**
  * @brief It sets the name of the Enemy
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS enemy_set_name(Enemy* enem, char *name);

/**
  * @brief It sets the id of the Enemy's location
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy
  * @param id the id to store in the Enemy's location
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_set_location(Enemy* enem, Id id);

/**
  * @brief It sets the health of Enemy
  * @author Luis Fernandez
  * 
  * @param enem a pointer to the Enemy
  * @param hlt the value of the enemy's health 
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_set_health(Enemy* enem,long int hp);

/**
  * @brief It prints the Enemy information
  * @author Luis Fernandez
  *
  * This function shows the name and the ids of the Enemy
  * @param enem a pointer to the Enemy
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS enemy_print(Enemy* enem);

#endif