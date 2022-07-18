/** 
 * @brief The Object module
 * 
 * @file Object.c
 * @author Luis_Fernandez
 * @version 1.0 
 * @date 10-02-2022
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

/**
 * @brief Object
 *
 * This struct stores all the information of an Object.
 */
struct _Object{
    Id id;                      /*!< id of the object*/
    char name[WORD_SIZE + 1];   /*!< name of the object*/
};

/** object_Object allocates memory for a new Object
  *  and initializes its members
  */
Object* object_create(Id id) {
    Object *newObj=NULL;

    /*Error control*/
    if(id== NO_ID)
    {
        return NULL;
    }
    
    newObj = (Object*) malloc(sizeof(Object));

    if(newObj==NULL)
    {
        return NULL;
    }

    /*Initialization of the members*/
    newObj->id = id;
    newObj->name[0] = '\0';
    
    return newObj;
}

/** object_destroy frees the previous memory allocation 
  *  for a Object
  */
STATUS object_destroy(Object* obj) {
    
    if(obj == NULL)
    {
        return ERROR;
    }

    free(obj);
    obj = NULL;

    return OK;
}

/** It gets the id of an Object
  */
Id object_get_id(Object* obj) {
    
    if(obj == NULL)
    {
        return NO_ID;
    }

    return obj->id;
}

/** It gets the name of an Object
  */
const char * object_get_name(Object* obj) {
   
    if(obj == NULL)
    {
        return NULL;
    }

    return obj->name;
}

/** It set the id of an Object
  */
STATUS object_set_id(Object* obj, Id id) {

    if( !obj || id == NO_ID)
    {
        return ERROR;
    }

    obj->id = id;

    return OK;
}

/** It sets the name of an Object
  */
STATUS object_set_name(Object* obj, char *name) {

    if( !obj || !name)
    {
        return ERROR;
    }

    if(!strcpy(obj->name,name))
    {
        return ERROR;
    }
    
    return OK;
}

/** It prints the Object information
  */ 
STATUS object_print(Object* obj) {

    /* Error control */
    if(obj == NULL)
    {
        return ERROR;
    }

/*print de id and name of the Object*/
    if(object_get_id(obj) != NO_ID) {
        
        if(object_get_name(obj))
        {
            fprintf(stdout,"--> Object (Id: %ld; Name: %s)\n", obj->id, obj->name);
        }
        else
        {
            fprintf(stdout, "--> Object (Id: %ld; Name: ERROR)\n", obj->id);
        }
    }
    else
    {
        fprintf(stdout, "--> Object (Id: ERROR; Name: %s\n)", obj->name);
    }

   return OK;

}
