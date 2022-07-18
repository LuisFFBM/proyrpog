/**
 * @brief functions related to reading files to introduce elements in the game
 *
 * @file game_management.h
 * @author Álexx y Óskar
 * @version 2.0
 * @date 12-03-2022
 */

#ifndef game_management_H
#define game_management_H

#include "game.h"
#include "object.h"
#include "player.h"
#include "link.h"
#include "dialogue.h"
#include "types.h"



/*
 * @brief reads the data in the start of the file and loads it in the game structure
 * @author Luis
 * 
 * @param game_new pointer to the game structure
 * @param game pointer to Game structure
 * @param filename name of the file containing the name of the file
 * @return returns ERROR if something fails and OK if everything runs fine
 */

/*
STATUS game_management_load_slot(Game *game_new, char*filename, Slot *last_slot);
*/


/**
 * @brief reads the data file with spaces and save it in the game structure
 * @author Álexx
 *
 * @param game pointer to Game structure
 * @param filename name of the file containing the spaces
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_management_load_spaces(Game *game, char *filename);

/**
 * @brief reads the data file with objects and save it in the game structure
 * @author Óskar
 *
 * @param game pointer to Game structure
 * @param filename name of the file containing the objects
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_management_load_objects(Game *game, char *filename);

/**
 * @brief reads player structure from file and saves them from game
 * 
 * @author
 * 
 * @param game pointer to Game structure
 * @param filename name of the file containing the objects
 * @return STATUS ERROR on failure OK on success
 */
STATUS game_management_load_player(Game *game, char *filename);


/**
 * @brief reads enemy structure from file and saves them from game
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure
 * @param filename name of the file containing the objects
 * @return STATUS ERROR on failure OK on success
 */
STATUS game_management_load_enemy(Game *game, char *filename);

/**
 * @brief reads link structures from file and saves them to game
 * 
 * @author Javi
 * 
 * @param game pointer to Game structure
 * @param filename name of the file containing the links
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_load_link (Game *game, char *filename);

/**
 * @brief reads dialogue structures from file and saves them to game
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure
 * @param filename name of the file containing the dialogue
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_load_dialogue (Game *game, char *filename);


/**
 * @brief starts writing in the file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the spaces
 * @param filename name of the file to write on
 * 
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_save_start(Game *game, char *filename);

/**
 * @brief reads the spaces in game structure data and saves them in the designated file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the spaces
 * @param filename name of the file to write on
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_save_spaces(Game *game, char *filename);


/**
 * @brief reads the object in game structure data and saves them in the designated file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the objects
 * @param filename name of the file to write on
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_save_objects(Game *game, char *filename);

/**
 * @brief reads the player in game structure data and saves it in the designated file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the player
 * @param filename name of the file to write on
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_save_player(Game *game, char *filename);
 

/**
 * @brief reads the enemy in game structure data and saves it in the designated file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the enemy
 * @param filename name of the file to write on
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_save_enemy(Game *game, char *filename);
 

/**
 * @brief reads the links in game structure data and saves them in the designated file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the links
 * @param filename name of the file to write on
 * @return STATUS ERROR on failure OK on success 
 */
STATUS game_management_save_link (Game *game, char *filename);


/**
 * @brief reads the dialogues in game structure data and saves them in the designated file
 * 
 * @author Luis
 * 
 * @param game pointer to Game structure containing the dialogues
 * @param filename name of the file to write on
 * @return STATUS ERROR on failure OK on success 
 */ 
STATUS game_management_save_dialogue (Game *game, char *filename);

#endif