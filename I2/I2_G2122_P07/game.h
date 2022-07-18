/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "player.h"
#include "object.h"
#include "set.h"
#include "enemy.h"

#define MAX_OBJECTS 10

/**
 * @brief Game
 *
 * This struct stores all the information of a game.
 */

typedef struct _Game
{
Player *player;                   /*!< pointer to the Player in game */
  Object *objects[MAX_OBJECTS];   /*!< array of objects in game */
  Enemy *enemy;                   /*!< pointer to the Enemy in game */
  Space *spaces[MAX_SPACES];      /*!< array of spaces in game */
  Command * last_cmd;             /*!< pointer to the command register */
} Game;

/**
  * @brief It adds a space to the game
  * @author Profesores PPROG
  *
  * @param game a pointer to  Game
  * @param space a pointer to  Space
  * @return OK if both pointer are valid and i is minor than MAX_SPACES, if not returns ERROR
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief It adds an object to the game
  * @author Luis Fernandez
  *
  * @param game a pointer to  Game
  * @param object a pointer to  Object
  * @return OK if both pointer are valid and i is minor than MAX_SET_ELEMENTS, if not returns ERROR
  */
STATUS game_add_object(Game *game, Object *object);

/**
  * @brief It initializes the game elements
  * @author Profesores PPROG
  *
  * @param game a pointer to Game
  * @param space a pointer to Space
  * @return OK
  */
STATUS game_create(Game *game);

/**
  * @brief It uses a file to create the spaces
  * @author Profesores PPROG
  *
  * reads a file and interpretates it as a space
  * to initialize the elements of it
  * 
  * @param game a pointer to  Game
  * @param filename a pointer to char
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_create_from_file(Game *game, char *filename);

/**
  * @brief It updates the game status
  * @author Joaquin Abad
  *
  * game_update reads the user input to update 
  * the game according to it
  * 
  * @param game a pointer to  Game
  * @param cmd from T_Command
  * @return OK if the pointer and the file are both valid, if not returns ERROR
  */
STATUS game_update(Game *game, Command * cmd);

/**
  * @brief It destroys the actual instace of the game
  * @author Profesores PPROG
  *
  * game_destroy destroys the actual instance of the game
  * freeing the allocated memory for it
  * 
  * @param game a pointer to  Game
  * @return OK
  */
STATUS game_destroy(Game *game);

/**
  * @brief It checks if the game must end 
  * @author Joaquin Abad Diaz
  * 
  * due to dead of the player or 
  * 
  * @param game a pointer to  Game
  * @return TRUE if it must end,  
  */
BOOL game_is_over(Game *game);

/**
  * @brief It prints the data of the game
  * @author Profesores PPROG
  * 
  * It prints the information related to different
  * elemnts of the game
  *
  * @param game a pointer to Game
  */
void game_print_data(Game *game);

/**
  * @brief It gets a pointer to a specific space
  * @author Profesores PPROG
  *
  * @param game a pointer to Game
  * @param id from Id
  * @return game->spaces[i] if the id is valid and NULL if not
  */
Space *game_get_space(Game *game, Id id);

/**
  * @brief It returns the location_id of player
  * @author Luis_Fernandez
  *
  * @param game a pointer to Game
  * @return location_id from game->player
  */
Id game_get_player_location(Game *game);

/**
  * @brief It returns the id of object in game
  * @author Luis Fernandez
  *
  * @param game a pointer to Game
  * @return id from game->object 
  */
Id game_get_object_location(Game *game, Id object);

/**
  * @brief It returns the location_id of enemy
  * @author Luis Fernandez
  *
  * @param game a pointer to Game
  * @return location_id from game->enemy
  */
Id game_get_enemy_location(Game *game);

/**
  * @brief It returns the last cmd command given by user
  * @author Profesores PPROG
  *
  * @param game a pointer to Game
  * @return game->last_cmd from T_Command
  */
Command *game_get_last_command(Game *game);
/**
  * @brief It sets the id of the object in the indicated space set of the game
  * @author Joaquin Abad Diaz
  *
  * @param game a pointer to Game
  * @param space the id of the space where the object belongs
  * @param object the object id 
  * @return OK if it succeded, ERROR if not
  */
STATUS game_set_object_location(Game *game,  Id space, Id object);


#endif