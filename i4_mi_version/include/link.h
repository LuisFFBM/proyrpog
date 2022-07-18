#ifndef LINK_H
#define LINK_H


#include "types.h"

typedef struct _Link Link;

/**
 * @brief It creates a new link
 * @author Luis
 *
 * link_create allocates memory for a new link
 *  and initializes its members
 * @param id the identification number for the new link
 * @return a new link, initialized
 */
Link *link_create(Id id);

/**
 * @brief It destroys a link
 *@author Oskar
 *
 * link_destroy frees the previous memory allocation
 *  for a link
 * @param link a pointer to the link that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_destroy(Link *link);

/**
 * @brief It gets the id of a link
 *@author Oskar
 *
 * @param link a pointer to the link
 * @return the id of link
 */
Id link_get_id(Link *link);

/**
 * @brief It sets the name of a link
 *@author Oskar
 *
 * @param link a pointer to the link
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_name(Link *link, char *name);

/**
 * @brief It gets the name of a link
 *@author Oskar
 *
 * @param link a pointer to the link
 * @return  a string with the name of the link
 */
const char *link_get_name(Link *link);

/**
 * @brief It sets the open of a link
 * @author Luis
 *
 * @param link a pointer to the link
 * @param st a STATUS with the open of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_open(Link *link, BOOL open);


/**
 * @brief It gets the open of a link
 * @author Luis
 *
 * @param link a pointer to the link
 * @return TRUE, if everything goes well or FALSE if there was some mistake
 */
BOOL link_get_open(Link *link);

/**
 * @brief It sets the origin of a link
 *@author Oskar
 *
 * @param link a pointer to the link
 * @param id the id of the origin of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_origin(Link *link, Id id);

/**
 * @brief It sets the origin of a link
 *@author Oskar
 *
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Id link_get_origin(Link *link);

/**
 * @brief It sets the destination of a link
 * @author Luis
 *
 * @param link a pointer to the link
 * @param id the id of the destination of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_destination(Link *link, Id id);

/**
 * @brief It sets the destination of a link
 *@author Oskar
 *
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Id link_get_destination(Link *link);

/**
 * @brief It sets the direction of a link
 * @author Luis
 *
 * @param link a pointer to the link
 * @param dir the DIRECTION of the direction of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_set_direction(Link *link, DIRECTION dir);

/**
 * @brief It sets the direction of a link
 * @author Luis
 *
 * @param link a pointer to the link
 * @return direction of link, if everything goes well or NO_DIR if there was some mistake
 */
DIRECTION link_get_direction(Link *link);

/**
 * @brief It prints the link information
 * @author Luis
 *
 * This function shows the id, name, direction, origin and destianation
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS link_print(Link *link);

#endif