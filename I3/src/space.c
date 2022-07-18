/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG, Óskar, Javi
 * @version 3.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/space.h"
#include "../include/set.h"
#include "../include/game.h"

#define MAX_DESC 100

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
    Id id;                    /*!< Id number of the space, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the space */
    Set *objects;             /*!< Pointer to the objects set */
    char gdesc[NROWS][NCOLS]; /*!< Graphic description of the space, if any */
    char description[MAX_DESC];
    BOOL light;
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space *space_create(Id id)
{
    Space *newSpace = NULL;
    int i=0;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newSpace = (Space *)malloc(sizeof(Space));
    if (newSpace == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty space*/
    newSpace->id = id;
    newSpace->name[0] = '\0';
    newSpace->objects = set_create();
    newSpace->light = FALSE;

    for (i = 0; i < NROWS; i++)
    {
        strcpy(newSpace->gdesc[i],"xxxxxxxxx");
    }

    return newSpace;
}

/** space_destroy frees the previous memory allocation
 *  for a space
 */
STATUS space_destroy(Space *space)
{   
    if (!space)
    {
        return ERROR;
    }

    set_destroy(space->objects);
    free(space);
    space = NULL;
    return OK;
}

/** It gets the id of a space
 */
Id space_get_id(Space *space)
{
    if (!space)
    {
        return NO_ID;
    }
    return space->id;
}

/** It sets the name of a space
 */
STATUS space_set_name(Space *space, char *name)
{
    if (!space || !name)
    {
        return ERROR;
    }

    if (!strcpy(space->name, name))
    {
        return ERROR;
    }
    return OK;
}

/** It gets the name of a space
 */
const char *space_get_name(Space *space)
{
    if (!space)
    {
        return NULL;
    }
    return space->name;
}


/** It sets the space graphic ascii description
  */
STATUS space_set_gdesc(Space* space, char* gd, int pos){
  
  if(space == NULL || gd == NULL || pos < 0 || pos >= NROWS)
  {
    return ERROR;
  }


  if(strlen(gd) == (NCOLS-1))
  {
    strcpy(space->gdesc[pos],gd);
    return OK;
  }

  return ERROR;
}

/** It gets the graphic description of a space
 */

char* space_get_gdesc(Space* space,int pos){
  if(space == NULL || pos < 0 || pos >= NROWS)
  {
    return NULL;
  }

  return space->gdesc[pos];
}


/** It sets the object in the space by adding it to the objets set in the space structure
 */
STATUS space_add_object(Space *space, Id object)
{
    if (!space || !object)
    {
        return ERROR;
    }

    if (set_add(space->objects, object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/** It removes an object from a space
 */
STATUS space_remove_object(Space *space, Id object)
{
    if (!space || object == NO_ID)
    {
        return ERROR;
    }

    if (set_del(space->objects, object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/**This functions checks if a certain object is in the space
 */
BOOL space_find_object(Space *space, Id object)
{
    if(!space || object == NO_ID)
    {
        return FALSE;
    }
    if(set_id_in_set(space->objects, object) == TRUE){
        return TRUE;
    }
   return FALSE; 
}

/** It gets the objects set of a space
 */
Set *space_get_objects(Space *space)
{
    if (!space)
    {
        return NULL;
    }
    return space->objects;
}

STATUS space_set_description(Space *space, char *desc) {
    if (space == NULL || desc == NULL) {
        return ERROR;
    }

    strcpy(space->description, desc);
    
    return OK;
}

char* space_get_description (Space *space) {
    if (space == NULL) {
        return NULL;
    }

    return space->description;
}
STATUS space_set_light(Space *space, BOOL light){
    if(space == NULL||(light!=TRUE&&light!=FALSE)){
        return ERROR;
    }
    space->light = light;
    return OK;
}
BOOL space_get_light(Space *space){
    if(space == NULL ){
        return FALSE;
    }
    return space->light;
}

/** It prints the space information
 */
STATUS space_print(Space *space)
{
    Id *obj_ids = NULL;
    int n_obj_ids = -1, i;

    /* Error Control */
    if (!space)
    {
        return ERROR;
    }

    /* 1. Print the id and the name of the space */
    fprintf(stdout, "--> Space (Id: %ld; Name: %s;Light: %d)\n", space->id, space->name, space->light);
    

    /* 3. Print the ids of the objects in this space */
    obj_ids = set_get_ids(space->objects);

    if (obj_ids == NULL)
    {
        return ERROR;
    }

    n_obj_ids = set_get_n_ids(space->objects);

    fprintf(stdout, "objects in space (id's) --->");

    for (i = 0; i < n_obj_ids; i++)
    {
        fprintf(stdout, "#%d: id %ld", i, obj_ids[i]);
    }

    free(obj_ids);

    return OK;
}
