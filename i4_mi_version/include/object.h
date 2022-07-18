/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Javii Oskar
 * @version 3.0
 * @date 12-03-2022
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"



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

/**
 * @brief it sets the description of the object 
 * @author Oskar
 *
 * @param object a pointer to the object struct 
 * @param desc a pointer to the description
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_description(Object *object, char *desc);

/**
 * @brief it gets the descrption of the object
 * @author Oskar
 *
 * @param object a pointer to the object struct 
 * @return a pointer to the description
 */
char* object_get_description (Object *object);

/**
 * @brief it sets the movable value 
 * @author Oskar
 *
 * @param object a pointer to the object struct 
 * @param movable a Bool value that says if the object is movable or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_movable(Object *object, BOOL movable);

/**
 * @brief it sets the dependency value(links between objects)
 * @author Oskar
 *
 * @param object a pointer of the object struct
 * @param dependency the id of the object that the first depend
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_dependency(Object *object, Id dependency);

/**
 * @brief it sets the open value (objects open doors)
 * @author Oskar
 *
 * @param object a pointer of the object struct 
 * @param open the id of the link that the object open
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_open(Object *object, Id open);

/**
 * @brief it sets the iluminate value(if the object iluminates or no) 
 * @author Oskar
 *
 * @param object a pointer to the object struct
 * @param iluminate a Bool value that indicates if the object iluminates or no
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_iluminate(Object *object, BOOL iluminate);

/**
 * @brief it sets the turnedon value
 * @author Oskar
 *
 * @param object a pointer to the object struct 
 * @param turnedon s BOOL value of turnedon
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS object_set_turnedon(Object *object, BOOL turnedon);

/**
 * @brief it gets the movable value of an object
 * @author Oskar
 *
 * @param object a pointer of the object struct 
 * @return the movable value
 */
BOOL object_get_movable(Object *object);

/**
 * @brief it gets the dependency value of an object
 * @author Oskar
 *
 * @param object a pointer of the object struct
 * @return the dependency value(ID)
 */
Id object_get_dependency(Object *object);

/**
 * @brief it gets the "open" object value
 * @author Oskar
 *
 * @param object a pointer of the object struct 
 * @return the open value(ID)
 */
Id object_get_open(Object *object);

/**
 * @brief it gets the iluminate value(BOOL)
 * @author Oskar
 *
 * @param object a pointer of the objact struct 
 * @return the iluminate value of an object
 */
BOOL object_get_iluminate(Object *object);

/**
 * @brief it gets the turnedon value(BOOL)
 * @author Oskar
 * @param object a pointer of the object struct 
 * @return the turnedon value of an object
 */
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