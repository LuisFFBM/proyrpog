/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Javii
 * @version 3.0
 * @date 12-03-2022
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define MAX_OBJECTS 40

typedef struct _Object Object;

/**
 * @brief It creates a new object
 * @author Javii
 *
 * object_create allocates memory for a new object
 *  and initializes its members
 * @param id the identification number for the new object
 * @param name the name of the new object
 * @return a new object, initialized
 */
Object *object_create(Id id, char *name);

/**
 * @brief It destroys an object
 * @author Javii
 *
 * object_destroy frees the previous memory allocation
 *  for an object
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_destroy(Object *object);

/**
 * @brief It sets the name of an object
 * @author Javii
 *
 * object_set_name allocates memory for the name of
 *  the new object
 * @param object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_name(Object *object, char *name);

/**
 * @brief It sets the id of an object
 * @author Javii
 *
 * @param object a pointer to the object
 * @param id the new id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_id(Object *object, Id id);

/**
 * @brief It gets the name of an object
 * @author Javii
 *
 * @param object a pointer to the object
 * @return a string with the name of the object
 */
char *object_get_name(Object *object);

/**
 * @brief It gets the id of an object
 * @author Javii
 *
 * @param object a pointer to the object
 * @return the id of the object
 */
Id object_get_id(Object *object);

STATUS object_set_description(Object *object, char *desc);

char* object_get_description (Object *object);

STATUS object_set_movable(Object *object, BOOL movable);
STATUS object_set_dependency(Object *object, Id dependency);
STATUS object_set_open(Object *object, Id open);
STATUS object_set_iluminate(Object *object, BOOL iluminate);
STATUS object_set_turnedon(Object *object, BOOL turnedon);

BOOL object_get_movable(Object *object);
Id object_get_dependency(Object *object);
Id object_get_open(Object *object);
BOOL object_get_iluminate(Object *object);
BOOL object_get_turnedon(Object *object);


/**
 * @brief It prints the object information
 * @author Javii
 *
 * This function shows the id and name of the object
 * @param object a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_print(Object *object);

#endif