/**
 * @brief It defines the Object 
 *
 * @file Object.h
 * @author Luis_Fernandez
 * @version 1.0
 * @date 15-02-2022
 * @copyright GNU Public License
 */
#ifndef OBJECT_H
#define OBJECT_H
#define OBJECT_INITIAL_ID 1

#include "types.h"

typedef struct _Object Object;


/**
  * @brief It creates a new Object
  * @author Luis_Fernandez
  *
  * object_create allocates memory for a new Object
  *  and initializes its members
  * @param id the identification number for the new Object
  * @return a new Object, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys an Object
  * @author Luis_Fernandez
  *
  * object_destroy frees the previous memory allocation 
  *  for a Object
  * @param obj a pointer to the Object that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* obj);

/**
  * @brief It gets the id of an Object
  * @author Luis_Fernandez
  * 
  * @param obj a pointer to the Object 
  * @return the id of Object
  */
Id object_get_id(Object* obj);

/**
  * @brief It gets the name of an Object
  * @author Luis_Fernandez
  * 
  * @param obj a pointer to the Object
  * @return  a string with the name of the Object
  */
const char * object_get_name(Object* obj);

/**
  * @brief It sets the id of an Object
  * @author Luis_Fernandez
  * 
  * @param obj a pointer to the Object
  * @param id the id to store in the Object
  * @return  OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_set_id(Object* obj, Id id);

/**
  * @brief It sets the name of an Object
  * @author Luis_Fernandez
  * 
  * @param obj a pointer to the Object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* obj, char *name);

/**
  * @brief It prints the Object information
  * @author Luis_Fernandez
  *
  * This fucntion shows the id and name of the Object.
  * @param obj a pointer to the Object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* obj);

#endif