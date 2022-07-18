/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Javii
 * @version 3.0
 * @date 12-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/object.h"

#define MAX_DESC 100
#define MAX_NAME 200

/**
 * @brief Object
 *
 * This struct stores all the information of an object.
 */
struct _Object
{
    Id id;                          /*!< Id number of the object, it must be unique */
    char name[MAX_NAME+1];          /*!< Name of the object */
    char description[MAX_DESC];     /*!< description of the object */
    BOOL movable;
    Id  dependency;
    Id open;
    BOOL iluminate;
    BOOL turnedon;
};

/** object_create allocates memory for a new object
 *  and initializes it by setting a name and an id
 */
Object *object_create(Id id, char *name)
{
    Object *obj = NULL;

    if (name == NULL || id == NO_ID)
    {
        return NULL;
    }

    obj = (Object *)malloc(sizeof(Object));

    if (obj == NULL)
    {
        return NULL;
    }

    strcpy(obj->name, name);

    if (object_set_id(obj, id) == ERROR)
    {
        free(obj);
        return NULL;
    }
    if (object_set_movable(obj, FALSE) == ERROR)
    {
        free(obj);
        return NULL;
    }
    if (object_set_dependency(obj, NO_ID) == ERROR)
    {
        free(obj);
        return NULL;
    }
    if (object_set_open(obj, NO_ID) == ERROR)
    {
        free(obj);
        return NULL;
    }
    if (object_set_iluminate(obj, FALSE) == ERROR)
    {
        free(obj);
        return NULL;
    }
    if (object_set_turnedon(obj, FALSE) == ERROR)
    {
        free(obj);
        return NULL;
    }

    

    return obj;
}

/** object_destroy frees the previous memory allocation
 *  for an object
 */
STATUS object_destroy(Object *object)
{
    if (!object)
    {
        return ERROR;
    }

    /*free(object->name);*/
    free(object);
    object = NULL;

    return OK;
}

/** It sets the name of an object
 */
STATUS object_set_name(Object *object, char *name)
{

    if (object == NULL || name == NULL)
    {
        return ERROR;
    }

    sprintf(object->name, "%s",name);
    return OK;
}

/** It sets the id of an object
 */
STATUS object_set_id(Object *object, Id id)
{
    if (object == NULL || id == NO_ID)
    {
        return ERROR;
    }

    object->id = id;
    return OK;
}

/** It gets the name of an object
 */
char *object_get_name(Object *object)
{
    if (object == NULL)
    {
        return NULL;
    }
    
    return object->name;
}

/** It gets the id of an object
 */
Id object_get_id(Object *object)
{
    if (object == NULL)
    {
        return NO_ID;
    }
    return object->id;
}

STATUS object_set_description(Object *object, char *desc) {
    if (object == NULL || desc == NULL) {
        return ERROR;
    }

    strcpy(object->description, desc);
    
    return OK;
}

char* object_get_description (Object *object) {
    if (object == NULL) {
        return NULL;
    }

    return object->description;
}
STATUS object_set_movable(Object *object, BOOL movable){
    if (object == NULL) {
        return ERROR;
    }

    object->movable = movable;
    
    return OK;
}
STATUS object_set_dependency(Object *object, Id dependency){
    if (object == NULL )
    {
        return ERROR;
    }

    object->dependency = dependency;
    return OK;
}
STATUS object_set_open(Object *object, Id open){
        if (object == NULL)
    {
        return ERROR;
    }

    object->open = open;
    return OK;
}
STATUS object_set_iluminate(Object *object, BOOL iluminate){
    if (object == NULL) {
        return ERROR;
    }

    object->iluminate = iluminate;
    
    return OK;
}
STATUS object_set_turnedon(Object *object, BOOL turnedon){
    if (object == NULL) {
        return ERROR;
    }

    object->turnedon = turnedon;
    
    return OK;
}

BOOL object_get_movable(Object *object){
    if (object == NULL) {
        return FALSE;
    }

    return object->movable;
}
Id object_get_dependency(Object *object){
    if (object == NULL) {
        return NO_ID;
    }

    return object->dependency;
}
Id object_get_open(Object *object){
    if (object == NULL) {
        return NO_ID;
    }

    return object->open;
}
BOOL object_get_iluminate(Object *object){
    if (object == NULL) {
        return FALSE;
    }

    return object->iluminate;
}
BOOL object_get_turnedon(Object *object){
    if (object == NULL) {
        return FALSE;
    }

    return object->turnedon;
}
/** It prints the object information
 */
STATUS object_print(Object *object)
{
    if (object == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Object (Id: %ld; Name: %s; Movable: %d; Dependency: %ld; Open: %ld; Iluminate: %d; Turnedon: %d)\n", object->id, object->name,object->movable,object->dependency,object->open,object->iluminate,object->turnedon);

    return OK;
}
