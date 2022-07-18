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

#include "space.h"
#include "player.h"
#include "command.h"
#include "types.h"
#include "enemy.h"
#include "object.h"
#include "link.h"
#include "set.h"
#include "inventory.h"

typedef struct _Game Game;

/**
 * @brief Adds the space structure to the spaces array of the game structure
 *
 * @param game pointer to the game structure
 * @param space pointer to the space to add
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief Adds the object structure to the objects array of the game structure
 *
 * @param game pointer to the game structure
 * @param space pointer to the object to add
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_add_object(Game *game, Object *object, Id location, char *name);

/**
 * @brief adds the player structure to the
 *
 * @param game
 * @param player
 * @return STATUS
 */
STATUS game_add_player(Game *game, Player *player);

/**
 * @brief  it creates the game and reserve memory for it
 * @author Profesores de pprog
 *
 * @param game pointer to the game structure
 *
 * @return returns ERROR if something fails and OK if everything runs fine
 */
Game *game_create();

/**
 * @brief This function creates the game from the file information
 * @author Profesores PPROG
 *
 * @param game pointer to the game structure
 * @param filename puntero a cadena que contiene el nombre del fichero para inicializar datos
 *
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_create_from_file(Game **game, char *filename);

/**
 * @brief This function adminitrates the command function calls according to the received cmd
 *
 * @param game pointer to the game structure
 * @param cmd comado
 *
 * @return Status
 */
STATUS game_update(Game *game, Command *cmd);

/**
 * @brief This function destroy the game and free the alloc memory
 *
 * @author Profesores PPROG
 *
 * @param puntero a estrcutura game
 *
 * @return Status
 */
STATUS game_destroy(Game *game);

/**
 * @brief This function tells if the game is over
 *
 * @param game pointer to the game structure
 * @return BOOL
 */
BOOL game_is_over(Game *game);

/**
 * @brief This function prints the game information
 *
 * @author Profesores PPROG
 *
 * @param game pointer to the game structure
 */
void game_print_data(Game *game);

/**
 * @brief This function gets the space from the id
 *
 * @author Profesores PPROG
 *
 * @param game puntero a estructura game
 * @param id id para buscar espacio
 * @return Space*
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief This functions gets the object in the game
 *
 * @author Alexx
 *
 * @param game puntero a estructura game
 * @param id id para buscar objeto
 * @return Object*
 */
Object *game_get_object(Game *game, Id id);

/**
 * @brief This functions gets the player in the game
 *
 * @author Luis
 *
 * @param game puntero a estructura game
 * @return Player pointer
 */
Player *game_get_player(Game *game);

/**
 * @brief This functions gets the enemy in the game
 *
 * @author Luis
 *
 * @param game puntero a estructura game
 * @return Enemy pointer
 */
Enemy*game_get_enemy(Game * game);

/**
 * @brief This function gets The player location
 *
 * @author Profesores PPROG
 *
 * @param game pointer to the game structure
 * @return Id
 */
Id game_get_player_location(Game *game);

/**
 * @brief This function gets The enemy location
 *
 * @author Oskar
 *
 * @param game pointer to the game structure
 * @return Id
 */
Id game_get_enemy_location(Game *game);

/**
 * @brief gets the space id of the space where the object is
 *
 * @author Profesores PPROG
 *
 * @param game pointer to the game structure
 * @return space id
 */
Id game_get_object_location(Game *game, Id object);

/**
 * @brief gets the last command entered
 *
 * @author Profesores PPROG
 *
 * @param game pointer to the game structure
 * @return the last command entered
 */
Command *game_get_last_command(Game *game);

/**
 * @brief gets the objects of the game
 *
 * @author SOMEONE
 *
 * @param game pointer to the game structure
 * @return the pointer to the object array in game
 */
Object **game_get_objects(Game *game);

/**
 * @brief gets the spaces of the game
 *
 * @author SOMEONE
 *
 * @param game pointer to the game structure
 * @return the pointer to the space array in game
 */
Space **game_get_spaces(Game *game);

/**
 * @brief gets the links of the game
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @return the pointer to the link array in game
 */
Link **game_get_links(Game * game);

/**
 * @brief gets the status of the connection of a determinated link
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param space id of the actual space
 * @param dir direction of the link
 * @return the status of the link, if everything goes well or ERROR if there was some mistake
 */
STATUS game_get_connection_status(Game *game, Id space, DIRECTION dir);

/**
 * @brief gets the destination of a determinated link
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param space id of the actual space
 * @param dir direction of the link
 * @return the id of the destination of the link, if everything goes well or NO_ID if there was some mistake
 */
Id game_get_connection(Game *game, Id space, DIRECTION dir);

/**
 * @brief Adds the link structure to the links array of the game structure
 *
 * @param game pointer to the game structure
 * @param link pointer to the link to add
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_add_link(Game *game, Link *link);

#endif
