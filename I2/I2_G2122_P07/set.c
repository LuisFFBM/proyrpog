/** 
 * @brief The Set module
 * 
 * @file set.c
 * @author Joaquin Abad
 * @version 1.0 
 * @date 23-02-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "set.h"

/**
 * @brief Set
 *
 * This struct stores all the information of sets.
 */
struct _Set
{
    Id ids[MAX_SET_ELEMENTS]; /*!< Array of the object ids */
    int n_ids;                /*!< Number of objects in the set */
};

/**  set_create allocates memory for a new Set
  *  and initializes its members
  */
Set* set_create() {

    Set * newSet = NULL;
    int i;

    newSet = (Set*) malloc(sizeof(Set));

    if(newSet==NULL){
        return NULL;
    }

    /*Initialization of the members*/
    for (i = 0; i < MAX_SET_ELEMENTS; i++)
    {
        newSet->ids[i] = NO_ID;    
    }
    newSet->n_ids = 0;
    
    
    return newSet;
}

/** set_destroy frees the previous memory allocation 
  *  for the set
  */
STATUS set_destroy(Set* set){

    /*Error control*/
    if(set == NULL)
    {
        return ERROR;
    }

    free(set);
    set = NULL;

    return OK;
}

/**
  * It adds an object to a certain set
  */
STATUS set_add_object(Set *set, Id id) {
  
  int i;
  
  if (!set || id == NO_ID)
  {
    return ERROR;
  }
  
  for (i = 0; i < MAX_SET_ELEMENTS; i++)
  {
    if (set->ids[i] == NO_ID)
    {
      set->ids[i] = id;
      set->n_ids++;
      return OK;
    }
  }
  return ERROR;
}

/**
  * It deletes an object from a certain set
  */
STATUS set_del_object(Set *set, Id id) {
  
  int i;

  if (!set || id == NO_ID)
  {
    return ERROR;
  }
  
  for (i = 0; i < MAX_SET_ELEMENTS; i++)
  {
    if (set->ids[i] == id)
    {
      set->ids[i] = NO_ID;
      set->n_ids--;
      return OK;
    }
  }
  return ERROR;
}

/** It returns the set's array
  */ 
Id * set_id_object(Set * set) {

  if(!set)
  {
    return NULL;
  }

  return set->ids;
}

/** It searchs for a certain object on the set
  */ 
BOOL set_find_object(Set* set, Id id) {
  
  int i;
  if (!set || id == NO_ID)
  {
    return FALSE;
  }
  
  for (i = 0; i < MAX_SET_ELEMENTS; i++)
  {
    if (set->ids[i] == id)
    {
      return TRUE;
    }
    
  }
  return FALSE;

}

/** It prints the Set information
  */ 
STATUS set_print(Set* set) {
    
    int i;

    /* Error control */
    if(set == NULL)
    {
      return ERROR;
    }


/*print de elements of a certain Set*/
    
    fprintf(stdout,"--> Set ( ");

    for (i = 0; i < MAX_SET_ELEMENTS; i++)
    {
      
      fprintf(stdout,"Id%d: %ld;\n", i + 1, set->ids[i]);
    }
    
    fprintf(stdout,"Numero de id's: %d", set->n_ids);

   return OK;

}