/**
 * @brief It defines the set interface
 *
 * @file set.h
 * @author Javii, Óskar y alexx
 * @version 2.2
 * @date 12-03-2022
 */
#ifndef SET_H
#define SET_H

#include "types.h"

#define MAX_SET 200

typedef struct _Set Set;

/**
 * @brief It creates a new set and allocate memory for it
 * @author oskar

 * @return a new set, initialized
 */
Set *set_create();

/**
 * @brief It destroys the set and frees the memory allocation
 * @author alexx
 *
 * @param s a pointer to the set that must be destroyed
 */
void set_destroy(Set *s);

/**
 * @brief this function adds an element to the set
 * @author oskar
 *
 * @param s a pointer o
 * @param id of the element
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_add(Set *s, Id id);

/**
 * @brief this function deletes an element of the set
 * @author javii
 *
 * @param s a pointer to the set struct
 * @param id of the element
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_del(Set *s, Id id);

/**
 * @brief it gets the n_ids of the set struct
 * @author Alexx
 *
 * @param s a pointer to the set struct
 * @return int
 */
int set_get_n_ids(Set *s);

/**
 * @brief This fuction gets the ids of the set
 * @author Javii
 *
 * @param s a pointer to the set struct
 * @return Id* an array with the ids
 */
Id *set_get_ids(Set *s);

/**
 * @brief This function checKs if the id(input) is in the set
 * @author Oskar
 *
 * @param s a pointer to the set struct
 * @param id An id
 * @return TRUE or FALSE
 */
BOOL set_id_in_set(Set *s, Id id);

/**
 * @brief It prints the set information
 * @author JAvii
 *
 * @param s a pointer yo the set struct
 * @return  OK, if everything goes well or ERROR if there was some mistake
 */
STATUS set_print(Set *s);

/**
 * @brief This functions check if the set is empty
 * @author Javii
 *
 * @param s pointer to the set struct
 * @return True if empty or if theres an error, False if not empty
 */
BOOL set_is_empty(Set *s);

#endif