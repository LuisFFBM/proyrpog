/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Luis y Oskar
 * @version 3.0
 * @date 17-03-2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link.h"


 
struct _Link
{
    Id id;                      /*!< Id number of the link, it must be unique */
    char name[WORD_SIZE + 1];   /*!< Name of the link */
    Id origin;                  /*!< Id of the link origin */
    Id destination;             /*!< Id of the link destination */
    DIRECTION direction;        /*!< Id of the link direction */
    BOOL open;                 /*!< Status of the link */

};

/** link_create allocates memory for a new link
 *  and initializes its members
 */
Link *link_create(Id id){
    
    Link* newLink = NULL; 
    
    if(id == NO_ID)
    {
        return NULL;
    }
    
    newLink = (Link*) malloc(sizeof(Link));
    if(newLink == NULL)
    {
        return NULL;
    }

    /* Error control */
    if (id == NO_ID)
        return NULL;

    /* Initialization of an empty link*/
    newLink->id = id;
    newLink->name[0] = '\0';

    newLink->origin = NO_ID;
    newLink->destination = NO_ID;

    newLink->direction = NO_DIR;
    newLink->open = FALSE;

    return newLink;
}

/** link_destroy frees the previous memory allocation
 *  for a link
 */
STATUS link_destroy(Link *link){
        if (link == NULL)
    {
        return ERROR;
    }

    free(link);
    
    return OK;
}

/** It gets the id of a link
 */
Id link_get_id(Link *link)
{
    if (link == NULL)
    {
        return NO_ID;
    }
    return link->id;
}

/** It sets the name of a link
 */
STATUS link_set_name(Link *link, char *name)
{
    if (link == NULL || name == NULL)
    {
        return ERROR;
    }

    if (strcpy(link->name, name) == NULL)
    {
        return ERROR;
    }
    return OK;
}

/** It gets the name of a link
 */
const char *link_get_name(Link *link)
{
    if (link == NULL)
    {
        return NULL;
    }
    return link->name;
}

/** It sets the open of a link
 */
STATUS link_set_open(Link *link, BOOL open) {
        if(link == NULL || open < FALSE || open > TRUE)
        {
            return ERROR;
        }

        link->open = open;
        return OK;
}


/** It gets the open of a link
 */
BOOL link_get_open(Link *link) {
    if(link == NULL)
    {
        return FALSE;
    }
    return link->open;
}

/** It sets the origin of a link
 */
STATUS link_set_origin(Link *link, Id id)
{
    if (link == NULL || id == NO_ID)
    {
        return ERROR;
    }
    link->origin = id;
    return OK;
}

/** It gets the origin of a link
 */
Id link_get_origin(Link *link)
{
    if (link == NULL)
    {
        return NO_ID;
    }
    return link->origin;
}

/** It sets the destination of a link
 */
STATUS link_set_destination(Link *link, Id id)
{
    if (link == NULL || id == NO_ID)
    {
        return ERROR;
    }
    link->destination = id;
    return OK;
}

/** It get the destination of a link
 */
Id link_get_destination(Link *link)
{
    if (link == NULL)
    {
        return NO_ID;
    }
    return link->destination;
}




/** It sets the direction of a link
 */
STATUS link_set_direction(Link *link, DIRECTION dir)
{

    /*LFF cambio el maximo a D*/
    if (!link || dir <= NO_DIR || dir > D)
    {
        return ERROR;
    }
    link->direction = dir;
    return OK;
}

/** It gets the direction of a link
 */
DIRECTION link_get_direction(Link *link)
{
    if(link == NULL){
        return NO_DIR;
    }
    return link->direction;
}


/** It prints the link information
 */
STATUS link_print(Link *link)
{   
    Id dest = NO_ID, orig = NO_ID;
    DIRECTION dir = NO_DIR;
    char *dir_char = "\0";

    /* Error Control */
    if (link == NULL)
    {
        return ERROR;
    }

    /* 1. Print the id and the name of the link */
    fprintf(stdout, "--> Link (Id: %ld; Name: %s)\n", link->id, link->name);

    /* 2. Prints the direction of the link */
    dir = link_get_direction(link);

    if (NO_DIR != dir)
    {
        switch (dir)
        {
        case N:
            sprintf(dir_char, "north");
            break;
        case S:
            sprintf(dir_char, "south");
            break;
        case E:
            sprintf(dir_char, "east");
            break;
        case W:
            sprintf(dir_char, "west");
            break;
        case U:
            sprintf(dir_char, "up");
            break;
        case D:
            sprintf(dir_char, "down");
            break;

        
        default:
            sprintf(dir_char, "tartarus");
            break;
        }

        fprintf(stdout, "---> Direction: %s\n", dir_char);
    }
    else
    {
        fprintf(stdout, "---> No direction\n");
    }
    
    /* 3. Prints the origin and destination of the link */

    dest = link_get_destination(link);
    orig = link_get_origin(link);

    if(orig != NO_ID && dest == NO_ID)
    {
        fprintf(stdout, "---> origin: %ld >> destination: No destination\n", orig);
    }
    else if(orig == NO_ID && dest != NO_ID)
    {
        fprintf(stdout, "---> origin: No origin >> destination: %ld\n", dest);

    }
    else if(orig == NO_ID && dest == NO_ID)
    {
        fprintf(stdout, "---> origin: No origin >> destination: No destination\n");
    }
    else
    {
        fprintf(stdout, "---> origin: %ld >> destination: %ld\n", orig, dest);
    }
    
    return OK;
}


