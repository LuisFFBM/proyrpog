/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000  /*!< max word size*/
#define NO_ID -1        /*!< NO_ID references is -1*/
#define IN_INVENTORY -2 /*!< if the object is in inventory has this id*/

#define SIZE_SHORT_DESC 50    /*!< max leght of the description*/
#define SIZE_LONG_DESC 200    /*!< max leght of the description*/

/**
 * @brief id (defined as long)
 */
typedef long Id;

/**
 * @brief boolean value
 */
typedef enum
{
    FALSE, /* FALSE is associated with the value 0 */
    TRUE   /* TRUE is associated with the value 1 */
} BOOL;

/**
 * @brief boolean value to describe status, it is used in error control
 */
typedef enum
{
    ERROR,  /*!< ERROR is asociated with the value 0*/
    OK      /*!< OK is asociated with the value 1*/
} STATUS;

/**
 * @brief enum to describe directions
 */
typedef enum
{   
    NO_DIR=-1,      /*!< No direction*/
    N,              /*!< North */
    S,              /*!< South */
    E,              /*!< East */
    W,              /*!< West */
    U,              /*!< UP*/
    D               /*!< DOWWN*/
} DIRECTION;

#endif
