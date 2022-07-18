/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author javi, Oscar, alex, luis, joaquin
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
#include "game_rules.h"

#define MAX_SLOTS 5             
#define MAX_OBJECTS 40 

typedef struct _Slot Slot;

typedef struct _Game Game;

/*SLOT*/

/**
 * @brief creates new slot structure
 * @author Luis
 * 
 * @return returns pointer to the new structure
 */
Slot* slot_create();


/**
 * @brief destroys slot structure
 * @author Luis
 * 
 * @param slot pointer to the slot to free
 * 
 */
void slot_destroy(Slot * slot);


/**
 * @brief gets nslot from slot structure
 * @author Luis
 * 
 * @param slot pointer to the slot structure
 * @return n_slots from the structure if everything when well, if not NULL 
*/
int slot_get_n_slots(Slot *slot);


/**
 * @brief sets nslot from slot structure
 * @author Luis
 * 
 * @param slot pointer to the slot structure
 * @param n integer whith the new number of slots
 * @return OK if everything when well, if not ERROR 
*/
STATUS slot_set_n_slots(Slot *slot, int n);


/**
 * @brief gets slot from slot structure
 * @author Luis
 * 
 * @param slot pointer to the slot structure
 * @return slot from the structure if everything when well, if not NULL 
*/
char **slot_get_slot(Slot *slot);

/**
 * @brief sets slot from slot structure
 * @author Luis
 * 
 * @param slot pointer to the slot structure
 * @param new_slot pointer to char array whith the new of slot
 * @return OK if everything when well, if not ERROR 
*/
STATUS slot_set_slot(Slot *slot, char **new_slot);

/*-------------------------------------------------------*/

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
 * @param object pointer to the object to add
 * @param name pointer to the name
 * @param location Id of the space location
 * 
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
 * @brief adds the enemy structure to the
 *
 * @param game
 * @param enemy
 * @return STATUS
 */
STATUS game_add_enemy(Game *game, Enemy *enemy);

/**
 * @brief Adds the link structure to the links array of the game structure
 *
 * @param game pointer to the game structure
 * @param link pointer to the link to add
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_add_link(Game *game, Link *link);



/**
 * @brief Adds the slots structure to the game structure
 *
 * @author Luis
 * 
 * @param game pointer to the game structure
 * @param slots pointer to the slot to add
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_add_slots(Game *game, Slot *slots);

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
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param filename puntero a cadena que contiene el nombre del fichero para inicializar datos
 *
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_load_from_file(Game **game, char *filename);

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
 * @brief This function adminitrates the command function calls according to the received rule
 *
 * @param game pointer to the game structure
 * @param rule rule
 *
 * @return Status
 */
STATUS game_update_pc(Game *game);


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
 * @author Oscar
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
 * @brief gets the last rule
 *
 * @author Joaquin
 *
 * @param game pointer to the game structure
 * @return the last rule executed
 */
Rule *game_get_last_rule(Game *game);

/**
 * @brief sets the last command entered
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param cmd command to set as last command 
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_set_last_command(Game *game, Command *cmd);

/**
 * @brief gets the objects of the game
 *
 * @author Oscar
 *
 * @param game pointer to the game structure
 * @return the pointer to the object array in game
 */
Object **game_get_objects(Game *game);

/**
 * 
 * @brief checks if theres a turned on object in the inventory wich can iluminate a space
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @return TRUE if theres a turned on object in the inventory, FALSE in any other case 
 */
BOOL game_inventory_objects_are_iluminated(Game *game);

/**
 * @brief gets the spaces of the game
 *
 * @author Oscar
 *
 * @param game pointer to the game structure
 * @return the pointer to the space array in game
*/
Space ** game_get_spaces(Game *game);

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
 * @brief gets the slots of the game
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * 
 * @return the pointer to the slot sructure in game
 */
Slot *game_get_slots(Game *game);

/**
 * @brief sets the slots of a game
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param slot new slot structure of the game
 * 
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_set_slot(Game *game, Slot *slot);

/**
 * @brief Adds the filename to the slots if theres space and increments by 1 the n_slots
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param filename name of the file to put in the slot
 * 
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_add_slot(Game *game, char *filename);

/**
 * @brief gets the status of the connection of a determinated link
 *
 * @author Luis
 *
 * @param game pointer to the game structure
 * @param space id of the actual space
 * @param dir direction of the link
 * @return the status of the link, if everything goes well or FALSE if there was some mistake
 */
BOOL game_get_connection_status(Game *game, Id space, DIRECTION dir);

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


#endif
