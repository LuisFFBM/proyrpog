/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define CHAR_GDESC 10
#define N_LINES 5

/**
  * @brief It creates a new space
  * @author Profesores PPROG
  *
  * space_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space
  * @author Profesores PPROG
  *
  * space_destroy frees the previous memory allocation 
  *  for a space
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It sets the id of the space located at the north
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param id the id number of the space located at the north
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_north(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the north
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the north 
  */
Id space_get_north(Space* space);

/**
  * @brief It sets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the south
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_south(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the south 
  */
Id space_get_south(Space* space);

/**
  * @brief It sets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the east
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_east(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the east
  */
Id space_get_east(Space* space);

/**
  * @brief It sets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the west
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_west(Space* space, Id id);

/**
  * @brief It gets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the west
  */
Id space_get_west(Space* space);

/**
  * @brief It adds an object to the given space
  * @author Joaquín Abad
  *
  * @param space a pointer to the space
  * @param id the id number of the object we want to add
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_add_object(Space* space, Id id);

/**
  * @brief It deletes an object from the given space
  * @author Joaquin Abad
  *
  * @param space a pointer to the space
  * @param id the id number of the object we want to delete
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_del_object(Space* space, Id id);

/**
  * @brief It obtains the identifiers of the objects in the space
  * @author Joaquin Abad
  *
  * @param space a pointer to the space
  * @return the ids numbers of the objects of the space
  */
Id* space_get_object_ids(Space* space);

/**
  * @brief It searchs for a certain object on the space
  * @author Joaquin Abad
  *
  * space_find_object determines whether or not a
  * given object is in the space
  * 
  * @param space a pointer to the Space
  * @param id of an object to search for it in the space
  * @return TRUE when thar object is shomewere in the space or FALSE if it insn't there
  */
BOOL space_find_object(Space* space, Id id);

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
  * @brief It sets the ascii description of a space
  * @author Luis Fernandez
  *
  * @param space a pointer to the space
  * @param gd a pointer to char 
  * @param pos int for the position in the array of the string
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_set_gdesc(Space *space, char * gd, int pos);

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);


#endif
