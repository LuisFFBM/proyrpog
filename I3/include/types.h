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

#define WORD_SIZE 1000
#define NO_ID -1

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
    ERROR,
    OK
} STATUS;

/**
 * @brief enum to describe directions
 */
typedef enum
{   
    NO_DIR=-1,      /*No direction*/
    N,              /* North */
    S,              /* South */
    E,              /* East */
    W,               /* West */
    U,               /*UP*/
    D               /*DOWWN*/
} DIRECTION;

#endif
