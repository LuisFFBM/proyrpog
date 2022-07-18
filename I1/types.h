/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

/**
 * @brief Id
 *
 * This means every Id will be long type
 */
typedef long Id;


/**
 * @brief BOOL
 *
 * This enum indicates that something can be true or false
 */
typedef enum
{
  FALSE,
  TRUE
} BOOL;

/**
 * @brief STATUS
 *
 * This enum indicates the status (OK or ERROR)
 */
typedef enum
{
  ERROR,
  OK
} STATUS;

/**
 * @brief DIRECTION
 *
 * This enum indicates the position in the map
 */
typedef enum
{
  N,  /*!< North*/    
  S,  /*!< South*/
  E,  /*!< East*/
  W   /*!< West*/
} DIRECTION;

#endif
