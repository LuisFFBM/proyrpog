/** 
 * @brief It implements the space module
 * 
 * @file space.c
 * @author Profesores PPROG
 * @author Joaquin Abad
 * @author Luis FErnandez
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"



/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  char gdesc[N_LINES][CHAR_GDESC]; /*!< contains the graphic description of the space in string array of 9x5*/
  Set * object;             /*!< Cointains the set of objects in the space*/
};

/** space_create allocates memory for a new space
  *  and initializes its members
  */
Space* space_create(Id id) {
  Space* newSpace = NULL;
  int i = 0;

  /* Error control */
  if (id == NO_ID)
  {
    return NULL;
  }

  newSpace = (Space *) malloc(sizeof (Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->object = set_create();
  for(i=0;i<N_LINES;i++){
    strcpy(newSpace->gdesc[i],"xxxxxxxxx");
  }

  return newSpace;
}

/** space_destroy frees the previous memory allocation 
  *  for a space
  */
STATUS space_destroy(Space* space) {
  int i = 0;
  if (!space) 
  {
    return ERROR;
  }
  
  set_destroy(space->object);
  for(i=0;i<N_LINES;i++){
    strcpy(space->gdesc[i], "");
  }
  free(space);
  
  space = NULL;
  
  
  return OK;
}

/** It gets the id of a space
  */
Id space_get_id(Space* space) {

  if (!space) 
  {
    return NO_ID;
  }
  
  return space->id;
}

/** It sets the name of a space
  */
STATUS space_set_name(Space* space, char* name) {

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
const char * space_get_name(Space* space) {

  if (!space) 
  {
    return NULL;
  }
  
  return space->name;
}

/** It sets the id of the space located at the north
  */
STATUS space_set_north(Space* space, Id id) {

  if (!space || id == NO_ID) 
  {
    return ERROR;
  }
  
  space->north = id;
  
  return OK;
}
/** It gets the id of the space located at the north
  */
Id space_get_north(Space* space) {

  if (!space) 
  {
    return NO_ID;
  }
  
  return space->north;
}

/** It sets the id of the space located at the south
  */
STATUS space_set_south(Space* space, Id id) {

  if (!space || id == NO_ID) 
  {
    return ERROR;
  }
  
  space->south = id;
  
  return OK;
}
/** It gets the id of the space located at the south
  */
Id space_get_south(Space* space) {

  if (!space) 
  {
    return NO_ID;
  }
  
  return space->south;
}

/** It sets the id of the space located at the east
  */
STATUS space_set_east(Space* space, Id id) {

  if (!space || id == NO_ID) 
  {
    return ERROR;
  }

  space->east = id;
  
  return OK;
}
/** It gets the id of the space located at the east
  */
Id space_get_east(Space* space) {

  if (!space) 
  {
    return NO_ID;
  }

  return space->east;
}

/** It sets the id of the space located at the west
  */
STATUS space_set_west(Space* space, Id id) {

  if (!space || id == NO_ID) 
  {
    return ERROR;
  }

  space->west = id;

  return OK;
}
/** It gets the id of the space located at the west
  */
Id space_get_west(Space* space) {

  if (!space) 
  {
    return NO_ID;
  }

  return space->west;
}

/** It adds an object to the given space
  */
STATUS space_add_object(Space* space, Id id) {

  if (!space || id == NO_ID) 
  {
    return ERROR;
  }

  if(set_add_object(space->object, id) == ERROR)
  {
   return ERROR;
  }
  return OK;
}

/** It deletes an object from the given space
  */
STATUS space_del_object(Space* space, Id id) {

  if (!space || id == NO_ID) 
  {
    return ERROR;
  }

  if(set_del_object(space->object, id) == ERROR) return ERROR;

  return OK;
}

/** It obtains the identifiers of the objects in the space
  */
Id* space_get_object_ids(Space* space) {

  Id * id = NULL;
  if (!space) 
  {
    return NULL;
  }

  id = set_id_object(space->object);
  if (id == NULL)
  {
    return NULL;
  }
  
  return id;
}

/** It searchs for a certain object on the space
  */ 
BOOL space_find_object(Space* space, Id id) {

  if (!space || id == NO_ID)
  {
    return FALSE;
  }

  if (set_find_object(space->object, id) == TRUE)
  {
    return TRUE;
  }
  
  return FALSE;
}

/** It gets the space graphic ascii description
  */
char* space_get_gdesc(Space* space,int pos){
  if(space == NULL || pos < 0 || pos >= N_LINES)
  {
    return NULL;
  }

  return space->gdesc[pos];
}

/** It sets the space graphic ascii description
  */
STATUS space_set_gdesc(Space* space, char* gd, int pos){
  
  if(space == NULL || gd == NULL || pos < 0 || pos >= N_LINES)
  {
    return ERROR;
  }


  if(strlen(gd) == (CHAR_GDESC-1))
  {
    strcpy(space->gdesc[pos],gd);
    return OK;
  }

  return ERROR;
}



/** It prints the space information
  */
STATUS space_print(Space* space) {

  Id idaux = NO_ID;
  int i = 0;

  /* Error Control */
  if (!space) 
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
 
  /* 2. For each direction, print its link */ 
  idaux = space_get_north(space);

  if (NO_ID != idaux) 
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } 
  else 
  {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);

  if (NO_ID != idaux) 
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } 
  else 
  {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);

  if (NO_ID != idaux) 
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } 
  else 
  {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);

  if (NO_ID != idaux) 
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } 
  else 
  {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Print if the objects in the space or not */
  if (NULL!= space_get_object_ids(space)) 
  {
    fprintf(stdout, "---> Objects in the space.\n");
    set_print(space->object);
  } 
  else 
  {
    fprintf(stdout, "---> No object in the space.\n");
  }

  /*4. print the space gdesc*/
  fprintf(stdout, "---> graphic description of the space.\n");
  if(space->gdesc != NULL)
  {
    for(i=0; i < N_LINES ; i++){
      if(space_get_gdesc(space, i) != NULL)
      {
        if(strcmp(space->gdesc[i], "         ") == 0)
        {
          fprintf(stdout, "*********");
        }
        else
        {
          fprintf(stdout, "%s\n", space->gdesc[i]); 
        }
        
      }

    }
  }
  else
  {
    fprintf(stdout, "---> No graphic description of space.\n");
  }


  return OK;
}

