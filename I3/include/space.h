/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG, Óskar, Javii
 * @version 3.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "object.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define MAX_LINKS 400
#define FIRST_SPACE 1
#define NCOLS 10
#define NROWS 5

/**
 * @brief It creates a new space
 * @author Profesores PPROG
 *
 * space_create allocates memory for a new space
 *  and initializes its members
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space *space_create(Id id);

/**
 * @brief It destroys a space
 * @author Profesores PPROG
 *
 * space_destroy frees the previous memory allocation
 *  for a space
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_destroy(Space *space);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space *space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_set_name(Space *space, char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *space_get_name(Space *space);

/**
  * @brief It sets the ascii description of a space
  * @author Luis
  *
  * @param space a pointer to the space
  * @param gd a pointer to char 
  * @param pos int for the position in the array of the string
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_set_gdesc(Space *space, char * gd, int pos);


/**
  * @brief It obtains the ascii description of a space
  * @author Luis Fernandez
  *
  * @param space a pointer to the space
  * @param pos int for the position in the array of the string
  * @return the graphic ascii description of the space
  */
char *space_get_gdesc(Space *space, int pos);

/**
 * @brief It sets the object in the space by adding it to the objets set in the space structure
 * @author Javii
 *
 * @param space a pointer to the space
 * @param object the object id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_add_object(Space *space, Id object);

/**
 * @brief It removes an object from a space
 * @author Javii
 *
 * @param space a pointer to the space
 * @param object the object id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_remove_object(Space *space, Id object);

/**
 * @brief This functions checks if a certain object is in the space
 * @author Joaquin Abad Diaz
 *
 * @param space pointer to the space struct
 * @param object that we want to check
 * @return True or False
 */
BOOL space_find_object(Space *space, Id object);

/**
 * @brief It gets the objects set of a space
 * @author Javii
 *
 * @param space a pointer to the space
 * @return a pointer to objects set of the space
 */
Set *space_get_objects(Space *space);

STATUS space_set_description(Space *space, char *desc);

char* space_get_description (Space *space);
/**
 * @brief 
 * 
 * @param space 
 * @param light 
 * @return STATUS 
 */
STATUS space_set_light(Space *space, BOOL light);

BOOL space_get_light(Space *space);

/**
 * @brief It prints the space information
 * @author Javii
 *
 * This function shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS space_print(Space *space);

#endif
