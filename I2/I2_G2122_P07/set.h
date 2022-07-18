/**
 * @brief It defines set.c
 *
 * @file set.h
 * @author Joaquin Abad
 * @version 1.0
 * @date 23-02-2022
 * @copyright GNU Public License
 */
#ifndef SET_H
#define SET_H

#define MAX_SET_ELEMENTS 30

#include "types.h"

typedef struct _Set Set;

/**
  * @brief It creates a new Set
  * @author Joaquin Abad
  *
  *  set_create allocates memory for a new Set
  *  and initializes its members
  * 
  * @return a new Set, initialized
  */
Set* set_create();

/**
  * @brief It creates a new Set
  * @author Joaquin Abad
  *
  *  set_destroy frees the previous memory allocation 
  *  for the set
  * 
  * @param set a pointer to the Set that must be destroyed 
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_destroy(Set* set);

/**
  * @brief It adds an objet to a certain set
  * @author Joaquin Abad
  *
  * set_add_object looks for elements with NO_ID to add
  * in that place a certain Id
  * @param set a pointer to the Set where the id will be stored 
  * @param id of an object or an element that will be stored in the set 
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_add_object(Set *set, Id id);

/**
  * @brief It deletes an objet from a certain set
  * @author Joaquin Abad
  *
  * set_del_object looks for elements with the id we gave to it
  * to delete that certain matchin element from the set
  * 
  * @param set a pointer to the Set where the element will be deleted 
  * @param id of an object or an element that will be deleted in the set 
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_del_object(Set *set, Id id);

/**
  * @brief It returns the set's array
  * @author Joaquin Abad
  *
  * @param set a pointer to the Set
  * @return the array from the set
  */
Id * set_id_object(Set * set);


/**
  * @brief It searchs for a certain object on the set
  * @author Joaquin Abad
  *
  * set_find_object determines whether or not a
  * given object is in the set
  * 
  * @param set a pointer to the Set
  * @param id of an object to search for it in the set
  * @return TRUE when thar object is shomewere in the set or FALSE if it insn't there
  */
BOOL set_find_object(Set* set, Id id);

/**
  * @brief It prints the Set information
  * @author Joaquin Abad
  *
  * This function shows the elements and number of elements
  * of a certain set
  * @param set a pointer to the Set
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS set_print(Set* set);


#endif