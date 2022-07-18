/**
 * @brief It implements the inventory module
 *
 * @file inventory.c
 * @author Profesores PPROG, Joaquin, Óskar, Javi
 * @version 3.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/inventory.h"
#include "../include/set.h"
#include "../include/game.h"
#include "../include/player.h"

#define MAX_OBJS 5


struct _Inventory
{                
    int max_objs;
    Set *objs;         /*!< Pointer to the objects set*/
};

/*
 * It creates a new inventory and allocates memory for it
 */
Inventory *inventory_create(int nobjs)
{
    Inventory *newInventory = NULL;
    if(nobjs<1){
        return NULL;
    }

    newInventory = (Inventory *)malloc(sizeof(Inventory));
    if (newInventory == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty inventory*/
    newInventory->objs = set_create();
    
    newInventory->max_objs = nobjs;

    return newInventory;
}

/*
 * It destroys the inventory and frees the memory allocation
 */
STATUS inventory_destroy(Inventory *inventory)
{
    if (!inventory)
    {
        return ERROR;
    }
    
    set_destroy(inventory->objs);

    free(inventory);
    inventory = NULL;
    return OK;
}

/**
 *this function checks if the Inventory is FULL
 */
BOOL inventory_is_full(Inventory *inventory)
{
    if(!inventory)
    {
        return FALSE;
    }
    if(inventory_get_n_objs(inventory)== inventory->max_objs){
        return TRUE;
    }
   return FALSE; 
}

/**
 *this function checks if the Inventory is FULL
 */
BOOL inventory_find_object(Inventory *inventory, Id object)
{
    if(!inventory)
    {
        return FALSE;
    }
    if(set_id_in_set(inventory->objs, object) == TRUE){
        return TRUE;
    }
   return FALSE; 
}

/**
 * this function adds an object id to the inventory 
 */
STATUS inventory_add_object(Inventory *inventory, Id object)
{
    if (!inventory || object == NO_ID)
    {
        return ERROR;
    }
    if(inventory_get_n_objs(inventory) == MAX_OBJS){
        return ERROR;
    }

    if (set_add(inventory_get_objects(inventory), object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/**
 * this function deletes an object of the inventory
 */
STATUS inventory_remove_object(Inventory *inventory, Id object)
{
    if (!inventory || object == NO_ID)
    {
        return ERROR;
    }

    if (set_del(inventory_get_objects(inventory), object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/**
 * This fuction gets the objs of the inventory
 */
Set *inventory_get_objects(Inventory *inventory)
{
    if (!inventory)
    {
        return NULL;
    }
    return inventory->objs;
}

/**
 * it gets the n_objs of the inventory structure
 */
int inventory_get_n_objs(Inventory *inventory){
    int num;
    
    if(!inventory){
        return -1;
    }
    num = set_get_n_ids(inventory_get_objects(inventory));
    return num;

}

/**
 * It sets the maximun amount of objects in the inventory
 */
STATUS inventory_set_max_objs(Inventory *inventory, int nobjs){
    if(!inventory||nobjs<1)
    {
        return ERROR;
    }

    inventory->max_objs = nobjs;
    return OK;


}

/**
 * It prints the inventory information
 */
STATUS inventory_print(Inventory *inventory)
{
    int i, n;
    Id * obj_ids = NULL;

    /* Error Control */
    if (!inventory)
    {
        return ERROR;
    }

    n = inventory_get_n_objs(inventory);
  
    fprintf(stdout, "--> Inventory\n numero de objetos :%d\n", n);

    obj_ids = set_get_ids(inventory_get_objects(inventory));

    fprintf(stdout, "objects in La Rinyo (id's) --->");

    for (i = 0; i < n; i++)
    {
        fprintf(stdout, "#%d: id %ld", i, obj_ids[i]);
    }
    free(obj_ids);
    

    return OK;
}
