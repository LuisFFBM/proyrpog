/** 
 * @brief It defines the game_reader.c functions
 * 
 * @file GameReader
 * @author Luis Fernandez
 * @version 1.0
 * @date 5-2-2022
 * @copyright 
 */
#ifndef __GAME_READER_H_
#define __GAME_READER_H_

#include "types.h"
#include "space.h"
#include "command.h"
#include "game.h"

/**
 * @brief It loads the spaces in the game
 * @author Luis Fernandez
 * 
 * game_load_spaces reads a file and use the directions to create a new space 
 * keeping it in the given Game pointer
 * @param game pointer to the game in which the spaces are save
 * @param filename string with the name of the file that has the spaces
 * @return status, if everything goes well or ERROR if there's a mistake
 */
STATUS game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It loads the objects in the game
 * @author Luis Fernandez y Joaquin Abad 
 * 
 * game_load_objects reads a file and use the directions to create a new object 
 * keeping it in the given Game pointer
 * @param game pointer to the game in which the objects are save
 * @param filename string with the name of the file that has the objects
 * @return status, if everything goes well or ERROR if there's a mistake
 */
STATUS game_reader_load_objects(Game *game, char *filename);

#endif
