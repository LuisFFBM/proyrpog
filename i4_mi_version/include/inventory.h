/**
 * @brief It defines the inventory interface
 *
 * @file inventory.h
 * @author Oskar Joakin
 * @version 3.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"




typedef struct _Inventory Inventory;


/**
 * @brief It creates a new inventory and allocate memory for it
 * @author oskar
 * @param nobjs int with number of objects

 * @return a new inventory, initialized
 */
Inventory *inventory_create(int nobjs);

/**
 * @brief It destroys the inventory and frees the memory allocation
 * @author oskar
 *
 * @param inventory a pointer to the inventory that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS inventory_destroy(Inventory *inventory);

/**
 * @brief this function adds an element to the inventory
 * @author oskar
 *
 * @param inventory a pointer to inventory structure
 * @param object id of the object to add
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS inventory_add_object(Inventory *inventory, Id object);

/**
 * @brief This functions checks if the inventory is full
 * @author oskar
 *
 * @param inventory pointer to the inventory struct
 * @return True or False
 */
BOOL inventory_is_full(Inventory *inventory);

/**
 * @brief This functions checks if the inventory is empty
 * @author Luis
 *
 * @param inventory pointer to the inventory struct
 * @return true if empty or error, false if not empty
 */
BOOL inventory_is_empty(Inventory *inventory);

/**
 * @brief This functions checks if a certain object is in the inventory
 * @author Joaquin Abad Diaz
 *
 * @param inventory pointer to the inventory struct
 * @param object that we want to check
 * @return True or False
 */
BOOL inventory_find_object(Inventory *inventory, Id object);

/**
 * @brief this function deletes an object of the inventory
 * @author oscar
 *
 * @param inventory a pointer to the inventory struct
 * @param object id of the object to be removed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS inventory_remove_object(Inventory *inventory, Id object);

/**
 * @brief This fuction gets the set of objects from the inventory
 * @author oskar
 *
 * @param inventory a pointer to the inventory struct
 * @return Id* an array with the ids
 */
Set* inventory_get_objects(Inventory *inventory);

/**
 * @brief This fuction gets the ids of the objects in the inventory
 * @author Joaquin
 *
 * @param inventory a pointer to the inventory struct
 * @return Id* an array with the ids
 */
Id *inventory_get_ids(Inventory *inventory);

/**
 * @brief it gets the n_objs of the inventory struct
 * @author oskar
 *
 * @param inventory a pointer to the inventory struct
 * @return int
 */
int inventory_get_n_objs(Inventory *inventory);

/**
 * @brief it sets the max_objs of the structure
 * @author oskar
 * 
 * @param inventory a pointer to inventory
 * @param nobjs a int value for the new max_objs
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS inventory_set_max_objs(Inventory *inventory, int nobjs);

/**
 * @brief It prints the inventory information
 * @author oskar
 *
 * @param inventory a pointer to the inventory struct
 * @return  OK, if everything goes well or ERROR if there was some mistake
 */
STATUS inventory_print(Inventory *inventory);


#endif
