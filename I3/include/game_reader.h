/**
 * @brief functions related to reading files to introduce elements in the game
 *
 * @file game_reader.h
 * @author Álexx y Óskar
 * @version 2.0
 * @date 12-03-2022
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "object.h"
#include "player.h"
#include "link.h"
#include "types.h"

/**
 * @brief reads the data file with spaces and save it in the game structure
 * @author Álexx
 *
 * @param game pointer to Game structure
 * @param filename name of the file containing the spaces
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief reads the data file with objects and save it in the game structure
 * @author Óskar
 *
 * @param game pointer to Game structure
 * @param filename name of the file containing the objects
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_reader_load_objects(Game *game, char *filename);

/**
 * @brief reads player structure from file and saves them from game
 * 
 * @author
 * 
 * @param game pointer to Game structure
 * @param filename name of the file containing the objects
 * @return STATUS ERROR on failure OK on success
 */
STATUS game_reader_load_player(Game *game, char *filename);

/**
 * @brief reads link structures from file and saves them to game
 * 
 * @author Javi
 * 
 * @param game pointer to Game structure
 * @param filename name of the file containing the objects
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_reader_load_link (Game *game, char *filename);
#endif