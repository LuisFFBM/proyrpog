/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Javii, Óskar y Alexx
 * @version 2.2
 * @date 12-03-2022
 */

#include "../include/set.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SET 200


/**
 * @brief Set
 *
 * this struct stores the set information
 */
struct _Set
{
    Id ids[MAX_SET];   /*!< An array with the ids of the set*/
    int n_ids; /*!< A counter with the number of elements in the set*/
};

/*PRIVATE FUNCTIONS*/
/**
 * @brief this function returns the position of an ID
 * @author Javii
 *
 * @param s a pointer to the set struct
 * @param id of the element
 * @return the position of the element in the array, -1 if not found or error
 */
int _set_get_id_pos(Set *s, Id id);

/**
 * @brief this function checs if the Set is FULL
 * @author Alexx
 *
 * @param s a pointer to the set struct
 * @return TRUE OR FALSE
 */
BOOL _set_is_full_(Set *s);

/**
 * this function returns the position of an ID
 */
int _set_get_id_pos(Set *s, Id id)
{
    int i;

    if (s == NULL)
    {
        return -1;
    }

    for (i = 0; i < s->n_ids; i++)
    {
        if (s->ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}

/**
 *this function checs if the Set is FULL
 */
BOOL _set_is_full_(Set *s)
{
    if (s == NULL)
    {
        return TRUE;
    }

    if (s->n_ids == MAX_SET)
    {
        return TRUE;
    }

    return FALSE;
}

/**
 * This functions check if the set is empty
 */
BOOL set_is_empty(Set *s)
{
    if (s == NULL)
    {
        return FALSE;
    }

    if (s->n_ids == 0)
    {
        return TRUE;
    }

    return FALSE;
}

/*
 * It creates a new set and allocate memory for it
 */

Set *set_create()
{
    Set *s = NULL;
    int i = 0;

    s = (Set *)malloc(sizeof(Set));

    if (s == NULL)
    {
        return NULL;
    }

    /*s->ids = (Id *)malloc(MAX_SET * sizeof(Id));*/
    for(i=0; i<MAX_SET; i++){
        s->ids[i] = NO_ID;
    }
    
    s->n_ids = 0;

    return s;
}

/*
 * It destroys the set and frees the memory allocation
 */

void set_destroy(Set *s)
{   
    if (s == NULL)
    {
        return;
    }

    free(s);
}
/**
 * this function adds an element to the set
 */

STATUS set_add(Set *s, Id id)
{
    if (s == NULL)
    {
        return ERROR;
    }

    if (_set_get_id_pos(s, id) != -1)
    {
        return ERROR;
    }

    if (_set_is_full_(s))
    {
        return ERROR;
    }

    s->ids[s->n_ids] = id;
    s->n_ids++;

    return OK;
}

/**
 * this function deletes an object of the set
 */
STATUS set_del(Set *s, Id id)
{
    int pos;

    if (s == NULL)
    {
        return ERROR;
    }

    if (s->n_ids == 0)
    {
        return ERROR;
    }

    pos = _set_get_id_pos(s, id);

    if (pos == -1)
    {
        return ERROR;
    }

    s->ids[pos] = s->ids[s->n_ids - 1];

    s->n_ids--;

    return OK;
}

/**
 * it gets the n_ids of the set struct
 */

int set_get_n_ids(Set *s)
{
    if (!s)
    {
        return -1;
    }

    return s->n_ids;
}

/**
 * This fuction gets the ids of the set
 */
Id *set_get_ids(Set *s)
{

    if (!s)
    {
        return NULL;
    }

    return s->ids;
}

/**
 * This function check if the id(input) is in the set
 */
BOOL set_id_in_set(Set *s, Id id)
{
    if (s == NULL)
    {
        return FALSE;
    }

    if (_set_get_id_pos(s, id) == -1)
    {
        return FALSE;
    }

    return TRUE;
}

/**
 * It prints the set information
 */

STATUS set_print(Set *s)
{
    int i;

    if (s == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Set (n_ids: %d", s->n_ids);

    for (i = 0; i < s->n_ids; i++)
    {
        fprintf(stdout, " #%d: id:%ld", i, s->ids[i]);
    }
    fprintf(stdout, ")");

    return OK;
}