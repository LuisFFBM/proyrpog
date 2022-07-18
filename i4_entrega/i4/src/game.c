/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG, Joaquin, Luis, Javii, Oskar y Alexx
 * @version 3.0
 * @date 17-02-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../include/game.h"
#include "../include/game_management.h"



#define MAX_FILE_NAME  20       /*!< max number of characters for filenames in load and save*/



/*declaraciones de valores default*/
#define DEFAULT_PLAYER_ID 1                             /*!< player id*/
#define DEFAULT_PLAYER_NAME "Jose Pintos y Vanesssa"    /*!< player name*/
#define DEFAULT_HEALTH_PLAYER 5                         /*!< player health*/

#define DEFAULT_OBJECT_ID 1                             /*!< object id*/
#define DEFAULT_OBJECT_NAME "Grano"                     /*!< object name*/

#define DEFAULT_ENEMY_ID 1                              /*!<enemy id*/
#define DEFAULT_ENEMY_NAME "Monica"                     /*!< enemy name*/
#define DEFAULT_HEALTH_ENEMY 5                          /*!< enemy health*/

#define DEFAULT_INVENTORY_SIZE 4                        /*!< inventory size*/


/*SLOT*/

struct _Slot{
    int n_slots;            /*!< number of slots*/
    char *slot[MAX_SLOTS];  /*!< slots filenames as array of char pointers*/
};



/**
 * creates new slot structure
*/
Slot* slot_create(){

    Slot *slot = NULL;
    
    slot = (Slot*) malloc(sizeof(Slot));
    if(slot == NULL){
        return NULL;
    }

    slot->n_slots = 0;

    return slot;
}

/**
 * free slot structure
*/
void slot_destroy(Slot * slot) {
    if(slot == NULL){
        return;
    }
    free(slot);
}

/**
 * gets nslot from slot structure
*/
int slot_get_n_slots(Slot *slot) {
    if(slot == NULL){
        return -1;
    }

    return slot->n_slots;
}

/**
 * sets nslot from slot structure
*/
STATUS slot_set_n_slots(Slot *slot, int n) {
    if(slot == NULL || n < 0) {
        return ERROR;
    }

    slot->n_slots = n;

    return OK;
}

/**
 * gets slot from slot structure
*/
char **slot_get_slot(Slot *slot) {
    if(slot == NULL) {
        return NULL;
    }

    return slot->slot;
}

/**
 * sets slot from slot structure
*/
STATUS slot_set_slot(Slot *slot, char **new_slot) {
    
    int i=0;
    
    if(slot == NULL || new_slot == NULL){
        return ERROR;
    }

    for(i=0; i<MAX_SLOTS; i++){
        strcpy(slot->slot[i], new_slot[i]);
    }
    
    return OK;
}

/*----------------------------------------------*/


/**
 * @brief Structure that contains the different data of the game
 */
struct _Game
{
    Player *player;                         /*!< player in the game*/
    Enemy *enemy;                           /*!< enemy in the game*/
    Object *objects[MAX_OBJECTS];           /*!< objects in the game*/
    Space *spaces[MAX_SPACES];              /*!< spaces in the game*/
    Command *last_cmd;                      /*!< last command in the game*/
    Link *links[MAX_LINKS];                 /*!< link between spaces in the game*/
    Slot *slots;                            /*!< slots of the game */
    Rule * last_rule;                       /*!< random rules of the game */
};



/**
   Private functions
*/
/**
 * @brief gets a space id according to its position in the array of game spaces
 *
 * @param game pointer to the game structure
 * @param position position of the space in the array of spaces of the Game structure
 * @return the space id
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief Given an id of a space, the position of the player is established based on said id
 *
 * @param game pointer to the game structure
 * @param id the space id
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_set_player_location(Game *game, Id id);

/**
 * @brief This Function set the enmy in the game
 * @author Oskar
 *
 * @param game a pointer to the game struct
 * @param id enemy id
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_set_enemy_location(Game *game, Id id);

/**
 * @brief Given an id of an object, the position of the object is established based on said id
 *
 * @param game pointer to the game structure
 * @param object pointer to the object
 * @param location space id
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_set_object_location(Game *game, Id object, Id location);

/**
 * @brief Instructions to execute when unknown command is entered (none)
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_unknown(Game *game);

/**
 * @brief The exit of the game is executed
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_exit(Game *game);

/**
 * @brief Command implemetation for moving the player
 *
 * @author Javi
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_move(Game *game, char *input);

/**
 * @brief The object is removed from the space and assigned to the player's inventory
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @param object name of the object to interact with
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_take(Game *game, char *object);

/**
 * @brief The item is removed from the player's inventory and assigned to the space
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @param object char to indicate the object we want to remove
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_drop(Game *game, char *object);


/**
 * @brief The player attack the enemy
 * @author Oskar
 * @param game  a pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_attack(Game *game);

/**
 * @brief It saves actual game data in a new or an existing file
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @param filename char to indicate the file wich stores game data 
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_save(Game *game, char *filename);

/**
 * @brief It loads game data from a saved file
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @param filename char to indicate the file wich stores game data 
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_load(Game **game, char *filename);

/**
 * @brief It finds an object Id through a name
 * @author Joaquin
 *
 * @param game pointer to the game structure
 * @param name of the object to find
 * @return the object id
 */
Id game_find_object_byname(Game *game, char *name);

/**
 * @brief It finds an space Id through a name
 * @author Joaquin
 *
 * @param game pointer to the game structure
 * @param name of the space to find
 * @return the space id
 */
Id game_find_space_byname(Game *game, char *name);

/**
 * @brief The object tunrns on if it can be ligthed
 *
 * @author Luis
 *
 * @param game pointer to the game struct
 * @param object name of the object to interact with
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_on(Game *game, char *object);

/**
 * @brief The object turns off
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @param object name of the object to interact with
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_off(Game *game, char *object);

/**
 * @brief It gives the description of an object or space
 *
 * @author Javi
 *
 * @param game pointer to the game struct
 * @param name of the object to interact with
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_inspect(Game *game, char *name);

/**
 * @brief It opens a door with a certain object
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @param object name of the object to interact with
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_open(Game *game, char *object);

/**
 * @brief It respawns a dead enemy
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_rule_enemy_respawn(Game *game);

/**
 * @brief It changes the localization of the enemy
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_rule_enemy_loc(Game *game);

/**
 * @brief It damages the player by a falling rock
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_rule_rock(Game *game);

/**
 * @brief It turns off a ligthed object
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_rule_off(Game *game);

/**
 * @brief It drops an item from players inventory
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_rule_drop(Game *game);

/**
 * @brief It paralizes the player a few turns
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_rule_paralized(Game *game);


/**
   Game interface implementation
*/
/*
 *it creates the game and reserve memory for it
 */
Game *game_create()
{
    Game *game = NULL;
    Inventory *inv;
    int i;

    game = (Game *)malloc(sizeof(Game));

    if (!game)
    {
        return NULL;
    }
    

    for (i = 0; i < MAX_SPACES; i++)
    {
        game->spaces[i] = NULL;
    }
    for (i = 0; i < MAX_OBJECTS; i++)
    {
        game->objects[i] = NULL;
    }
    for(i = 0; i < MAX_LINKS; i++)
    {
        game->links[i] = NULL;
    }

    inv=inventory_create(DEFAULT_INVENTORY_SIZE);
    
    game->player = player_create(DEFAULT_PLAYER_ID, DEFAULT_PLAYER_NAME, NO_ID, inv, DEFAULT_HEALTH_PLAYER);
    game->enemy = enemy_create(DEFAULT_ENEMY_ID, DEFAULT_ENEMY_NAME, NO_ID, DEFAULT_HEALTH_ENEMY);
    game->last_cmd = command_create();
    game->last_rule = rule_create();
    game->slots = slot_create();

    return game;
}

/**
 * This function creates the game from the file information
 */
STATUS game_load_from_file(Game **game, char *filename) {
    Game *game_new = NULL;
    
    if(!game || !filename){
        return ERROR;
    }

    game_new = game_create();


    if(game_new == NULL)
    {
        return ERROR;
    }

    if (game_management_load_spaces(game_new, filename) == ERROR)
    {
        game_destroy(game_new);
        return ERROR;
    }
    if (game_management_load_objects(game_new, filename) == ERROR)
    {
        game_destroy(game_new);
        return ERROR;
    }
    if (game_management_load_player(game_new, filename) == ERROR)
    {
        game_destroy(game_new);
        return ERROR;
    }
    if(game_management_load_enemy(game_new, filename)==ERROR)
    {
        game_destroy(game_new);
        return ERROR;
    }
    if (game_management_load_link(game_new,filename)==ERROR)
    {
        game_destroy(game_new);
        return ERROR;
    }
    
 
    game_destroy(*game);

    (*game) = game_new;

    return OK;
}
/*
STATUS game_save_in_file(Game *game, char *filename) {
    
    if(!game || !filename)
    {
        return ERROR;
    }

    if(ERROR == game_add_slot(game, filename))
    {
        return ERROR;
    }


    if(game_management_save_start(game, filename) == ERROR)
    {

        return ERROR;
    }
    
    if(game_management_save_last_file(game,filename) == ERROR)
    {
       
        return ERROR;
    }
    

    if (game_management_save_spaces(game, filename) == ERROR)
    {
        
        return ERROR;
    }
    if (game_management_save_objects(game, filename) == ERROR)
    {
        
        return ERROR;
    }
    if (game_management_save_player(game, filename) == ERROR)
    {
      
        return ERROR;
    }
    if (game_management_save_link(game,filename)==ERROR)
    {
       
        return ERROR;
    }
    if(game_management_save_player(game, filename)==ERROR)
    {
       
        return ERROR;
    }

    

    return OK;
}
*/
/**
 * This function destroy the game and free the alloc memory
 */
STATUS game_destroy(Game *game)
{
    int i = 0;

    if (!game)
    {
        return ERROR;
    }
    

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        space_destroy(game->spaces[i]);
    }

    for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    {
        object_destroy(game->objects[i]);
    }
    
    for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++)
    {
        link_destroy(game->links[i]);
    }

    command_destroy(game->last_cmd);
    player_destroy(game->player);
    enemy_destroy(game->enemy);
    slot_destroy(game->slots);
    rule_destroy(game->last_rule);
    

    free(game);

    return OK;
}

/**
 * Adds the space structure to the spaces array of the game structure
 */
STATUS game_add_space(Game *game, Space *space)
{
    int i = 0;
    
    if (!game || space == NULL)
    {
        return ERROR;
    }

    while (i < MAX_SPACES && game->spaces[i] != NULL)
    {
        i++;
    }
     
    game->spaces[i] = space;
    

    return OK;
}

/**
 * Adds the player structure to the game structure
 */
STATUS game_add_player(Game *game, Player *player)
{

    if (!game || player == NULL)
    {
        return ERROR;
    }

    if (game->player != NULL) {
        player_destroy(game->player);
    }


    game->player = player;

    return OK;
}

/**
 * Adds the enemy structure to the game structure
 */
STATUS game_add_enemy(Game *game, Enemy *enemy)
{

    if (game == NULL || enemy == NULL)
    {
        return ERROR;
    }

    if (game->enemy != NULL) {
        enemy_destroy(game->enemy);
    }

    game->enemy = enemy;

    return OK;
}

/**
 * Adds the object structure to the objects array of the game structure
 */
STATUS game_add_object(Game *game, Object *object, Id location, char *name)
{
    int i = 0;

    if (!game || object == NULL)
    {
        return ERROR;
    }

    while (i < MAX_OBJECTS && game->objects[i] != NULL)
    {
        i++;
    }

    game->objects[i] = object;

    game_set_object_location(game, object_get_id(object), location);
    object_set_name(object, name);

    return OK;
}

/**
 * Adds the link structure to the links array of the game structure
 */
STATUS game_add_link(Game *game, Link *link)
{
    int i = 0;

    if (!game || !link)
    {
        return ERROR;
    }

    while (i < MAX_LINKS && game->links[i] != NULL)
    {
        i++;
    }

    game->links[i] = link;

    return OK;
}


/**
 * Adds the dialogue structure to the dialogue array of the game structure
 */
STATUS game_add_dialogue(Game *game, Dialogue* dialogue) {
    return OK;
}

/*LFF*/
/* Adds the slots structure to the game structure
 */
/*
STATUS game_add_slots(Game *game, Slot *slots) {

    if (!game || !slots)
    {
        return ERROR;
    }

    return game_set_slot(game, slots);

}
*/

/**
 * Adds the filename to the slots if theres space and increments by 1 the n_slots
*/
STATUS game_add_slot(Game *game, char *filename) {
    int i=0, cmp = 1;
    char **slot_aux;
    
    if(!game || !filename)
    {
        return ERROR;
    }
    
    slot_aux = slot_get_slot(game_get_slots(game));

    for(i=0; i < slot_get_n_slots(game_get_slots(game)) && (cmp = strcmp(filename, slot_aux[i])) != 0; i++){
        if(cmp == 0){

            return OK;
        }
    }

    if(i < MAX_SLOTS)
    {
        strcpy(slot_aux[i],filename);
    }
    else
    {
        return ERROR;
    }
    slot_set_slot(game_get_slots(game), slot_aux);

    slot_set_n_slots(game_get_slots(game), i+1);

    return OK;
}

/**gets a space id according to its position in the array of game spaces
 */
Id game_get_space_id_at(Game *game, int position)
{
    if (position < 0 || position >= MAX_SPACES)
    {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}

/**
 *This function gets the space from the id
 */
Space *game_get_space(Game *game, Id id)
{
    int i = 0;

    if (id == NO_ID)
    {
        return NULL;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        if (id == space_get_id(game->spaces[i]))
        {
            return game->spaces[i];
        }
    }

    return NULL;
}

/**
 * This functions gets the object in the game
 */
Object *game_get_object(Game *game, Id id)
{
    int i = 0;

    if (id == NO_ID)
    {
        return NULL;
    }

    for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    {
        if (id == object_get_id(game->objects[i]))
        {
            return game->objects[i];
        }
    }

    return NULL;
}

/**
 *  It finds an object Id through a name
 */
Id game_find_object_byname(Game *game, char *name) {

    int i = 0;

    if (!game || !name)
    {
        return NO_ID;
    }

    

    for ( i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    {
       if (strcasecmp(object_get_name(game->objects[i]), name) == 0)
        {
            return object_get_id(game->objects[i]);
        }
        
    }
    return NO_ID;
}

/**
 * It finds an space Id through a name
*/
Id game_find_space_byname(Game *game, char *name) {

    int i = 0;

    if (!game || !name)
    {
        return NO_ID;
    }

    for ( i = 0; i < MAX_SPACES; i++)
    {
        if (strcmp(space_get_name(game->spaces[i]), name) == 0)
        {
            return space_get_id(game->spaces[i]);
        }
        
    }
    return NO_ID;
}

/**
 *  This function gets The player location
 */
STATUS game_set_player_location(Game *game, Id id)
{

    if (id == NO_ID)
    {
        return ERROR;
    }

    player_set_location(game->player, id);

    return OK;
}

/**
 * This Function set the enmy in the game
 */
STATUS game_set_enemy_location(Game *game, Id id)
{

    if (id == NO_ID)
    {
        return ERROR;
    }

    enemy_set_location(game->enemy, id);

    return OK;
}

/**
 * Given an id of an object, the position of the object is established based on said id
 */
STATUS game_set_object_location(Game *game, Id object, Id location)
{
    Id oldlocation = NO_ID;
    int i;

    if (game == NULL)
    {
        return ERROR;
    }

    oldlocation = game_get_object_location(game, object);

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        if (oldlocation == space_get_id(game->spaces[i]))
        {
            space_remove_object(game->spaces[i], object);
        }
    }

    if (location != NO_ID && location != IN_INVENTORY)
    {
        for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
            if (space_get_id(game->spaces[i]) == location)
            {
                space_add_object(game->spaces[i], object);
            }
        }
    }

    return OK;
}

/*sets the slots of a game*/
STATUS game_set_slot(Game *game, Slot *slot) {
    if(!game || !slot)
    {
        return ERROR;
    }

    game->slots = slot;

    return OK;
}

/**
 * gets player from game
*/
Player*game_get_player(Game * game)
{
    if(game == NULL){
        return NULL;
    }

    return game->player;
}

/**
 * gets enemy from game
*/
Enemy*game_get_enemy(Game * game)
{
    if(game == NULL){
        return NULL;
    }

    return game->enemy;
}

/**
 * This function gets The player location
 */
Id game_get_player_location(Game *game)
{

    if (game == NULL) {
        return NO_ID;
    }

    return player_get_location(game->player);
}

/**
 * This function gets The enemy location
 */
Id game_get_enemy_location(Game *game)
{

    return enemy_get_location(game->enemy);
}

/**
 * gets the space id of the space where the object is
 */
Id game_get_object_location(Game *game, Id object)
{
    Set *s = NULL;
    int i;

    if (game == NULL)
        return NO_ID;

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        s = space_get_objects(game->spaces[i]);
        if (set_id_in_set(s, object) == TRUE)
        {
            return game_get_space_id_at(game, i);
        }
    }

    return NO_ID;
}

/**
 * gets the slots of a game
 */
Slot *game_get_slots(Game *game) {
    if(!game)
    {
        return NULL;
    }
    
    return game->slots;
}

/**
 * This function adminitrates the command function calls according to the received cmd
 */
STATUS game_update(Game *game, Command *cmd)
{
  
  if(command_set_cmd(game->last_cmd, command_get_cmd(cmd)) == ERROR)
  {
    return ERROR;
  }
  if(command_set_input(game->last_cmd, command_get_input(cmd)) == ERROR)
  {
    return ERROR;
  }

  if(command_set_sec_input(game->last_cmd, command_get_sec_input(cmd)) == ERROR)
  {
    return ERROR;
  }

  if(command_set_status(game->last_cmd, command_get_status(cmd)) == ERROR)
  {
    return ERROR;
  }

  if(command_set_description_short(game->last_cmd, command_get_description_short(cmd)) == ERROR)
  {
    return ERROR;
  }
  
  if(command_set_description_large(game->last_cmd, command_get_description_large(cmd)) == ERROR)
  {
    return ERROR;
  }

    switch (command_get_cmd(game->last_cmd))
    {
    case UNKNOWN:
        command_set_status(game->last_cmd, game_command_unknown(game));
        break;

    case EXIT:
        command_set_status(game->last_cmd, game_command_exit(game));
        break;

    
    case MOVE:
        command_set_status(game->last_cmd, game_command_move(game, command_get_input(game->last_cmd)));
        break;

    
    case TAKE:
        command_set_status(game->last_cmd, game_command_take(game, command_get_input(game->last_cmd)));
        break;

    case DROP:
        command_set_status(game->last_cmd, game_command_drop(game, command_get_input(game->last_cmd)));
        break;

    case ATTACK:
        command_set_status(game->last_cmd, game_command_attack(game));
        break;
    case INSPECT:
        command_set_status(game->last_cmd, game_command_inspect(game, command_get_input(game->last_cmd)));
        break;
    case SAVE:
        command_set_status(game->last_cmd, game_command_save(game, command_get_input(game->last_cmd)));
        break;
    case LOAD:
        command_set_status(game->last_cmd, game_command_load(&game, command_get_input(game->last_cmd)));
        break;
    case TURNON:
        command_set_status(game->last_cmd, game_command_on(game, command_get_input(game->last_cmd)));
        break;
    case TURNOFF:
        command_set_status(game->last_cmd, game_command_off(game, command_get_input(game->last_cmd)));
        break;
    case OPEN:
        command_set_status(game->last_cmd, game_command_open(game, command_get_sec_input(game->last_cmd)));
        break;

    default:
        break;
    }

    return OK;
}

STATUS game_update_pc(Game * game) {
    int n = 0;
    T_Rules random = NO_RULE;

    if (!game)
    {
        return ERROR;
    }



    n = rand() % 16;

    random = rule_selection(n);

    if (rule_set_acction(game->last_rule, random) == ERROR)
    {
        return ERROR;
    }
    
    switch (random)
    {
    case NO_RULE:

        rule_set_status(game->last_rule, OK);
        break;
    
    case ENEMY:
    
        rule_set_status(game->last_rule, game_rule_enemy_respawn(game));
        break;

    case ENEMY_LOC:

        rule_set_status(game->last_rule, game_rule_enemy_loc(game));
        break;

    case OBJ_OFF:
    
        rule_set_status(game->last_rule, game_rule_off(game));
        break;

    case OBJ_DROP:
    
        rule_set_status(game->last_rule, game_rule_drop(game));
        break;

    case ROCK:
    
        rule_set_status(game->last_rule, game_rule_rock(game));
        break;

    case PARALIZED:
    
        rule_set_status(game->last_rule, game_rule_paralized(game));
        break;
    
    default:
        break;
    }

    return OK;

}

/**
 * gets the last command entered
 */
Command *game_get_last_command(Game *game)
{
    
    return game->last_cmd;
}

/**
 * gets the last rule
 */
Rule *game_get_last_rule(Game *game)
{
    
    return game->last_rule;
}

STATUS game_set_last_command(Game *game, Command *cmd){
    if(game == NULL || cmd == NULL){
        return ERROR;
    }

    if(game->last_cmd != NULL){

        free(game->last_cmd);
    }
    game->last_cmd = cmd;

    return OK;
}

/**
 * This function prints the game information
 */
void game_print_data(Game *game)
{
    Id id;

    int i = 0;

    printf("\n\n-------------\n\n");

    printf("=> Spaces: \n");
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        space_print(game->spaces[i]);
    }

    printf("=> Object location: ");
    for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    {
        id = object_get_id(game->objects[i]);

        printf("#%d %ld %ld ", i, id, game_get_object_location(game, id));
    }
    printf("\n");
    printf("=> Player location: %d\n", (int)player_get_location(game->player));
    printf("=> Enemy location: %d\n", (int)enemy_get_location(game->enemy));
}

/**
 * This function tells if the game is over
 */
BOOL game_is_over(Game *game)
{

    if (game == NULL) {
        return FALSE;
    }

    if (player_get_health(game->player) <= 0)
    {
        return TRUE;
    }

    return FALSE;
}

/**
   Calls implementation for each action
*/

/**
 * Instructions to execute when unknown command is entered (none)
 */
STATUS game_command_unknown(Game *game)
{
    return ERROR;
}

/**
 * The exit of the game is executed
 */
STATUS game_command_exit(Game *game)
{
    return OK;
}

/**
 * Operations and comparations are performed to advance one space in the direction given
 */
STATUS game_command_move(Game *game, char *input)
{
    DIRECTION direction = NO_DIR;
    Id player_location = NO_ID;
    

    if (game == NULL || input == NULL) {
        return ERROR;
    }

    if (strcmp(input, "south") == 0 || strcmp(input, "s") == 0) {
        direction = S;
    } else if (strcmp(input, "north")  == 0 || strcmp(input, "n") == 0) {
        direction = N;
    } else if (strcmp(input, "east")  == 0 || strcmp(input, "e") == 0) {
        direction = E;
    } else if (strcmp(input, "west")  == 0 || strcmp(input, "w") == 0) {
        direction = W;
    } else if (strcmp(input, "up")  == 0 || strcmp(input, "u") == 0) {
        direction = U;
    } else if (strcmp(input, "down")  == 0 || strcmp(input, "d") == 0) {
        direction = D;
    } else {
        direction = NO_DIR;
    }


    player_location = game_get_player_location(game);
    if (player_location == NO_ID)
    {
        return ERROR;
    }



    if(game_get_connection_status(game, player_location, direction) == TRUE)
    {
        if(game_set_player_location(game, game_get_connection(game, player_location, direction)) == OK)
        {
            return OK;
        }
    }

    return ERROR;
}

/**
 * The object is removed from the space and assigned to the player
 */
STATUS game_command_take(Game *game, char *object)
{
  int i = 0;
  Id object_id = NO_ID;

  if (!game || !object)
  {
    return ERROR;
  }

  object_id = game_find_object_byname(game, object);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == game_get_player_location(game))
    {
        if (space_get_objects(game->spaces[i])!=NULL)
        {
            /*Checks if the object is in the space*/
            if(space_find_object(game->spaces[i], object_id) == TRUE)
            {
                /*Checks if the player's inventory is full*/
                if(player_inventory_is_full(game->player) == FALSE)
                {   
                    /*Checks if the object is movable*/
                    if (object_get_movable(game_get_object(game,object_id)) == TRUE)
                    {
                        /*Sets player's object to the indicated one*/
                        if(player_add_object_inventory(game->player,object_id) == OK)
                        {
                            if(ERROR == game_set_object_location(game,object_id , IN_INVENTORY))
                            {
                                
                                return ERROR;
                            }                            
                            return OK;
                        }
                    }
                }
            }
        }
    } 
  }
  return ERROR; 
}

/**
 * The item is removed from the player and assigned to the space it is on
 */
STATUS game_command_drop(Game *game, char *object) {
  int i = 0;
  Id object_id = NO_ID;

  if (!game)
  {
    return ERROR;
  }
  object_id = game_find_object_byname(game, object);

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    /*Checks that the player is in the actual space*/
    if (space_get_id(game->spaces[i]) == game_get_player_location(game))
    {
      /*Checks that the player has an object to drop*/
      if (player_get_inventory(game->player) != NULL)
      {
          /*Checks that the object isn't already in the space*/
          if (space_find_object(game->spaces[i], object_id) == FALSE)
          {
            /*Checks if the object is in player's inventory*/
            if (player_id_in_inventory(game->player, object_id) == TRUE)
            {
                /*Deletes that object from player's inventory*/
                if (player_del_object_inventory(game->player, object_id) == OK)
                {
                    /*Adds that object to the space*/
                    if (space_add_object(game->spaces[i], object_id) == OK)
                    {

                        return OK;
                    }   
                }
            }
          }
      }
    }
  }
  return ERROR; 
}

STATUS game_command_inspect(Game *game, char *name) {
    
    Id id;
    int i = 0;
    Space * space = NULL;
    Object * object = NULL;
    BOOL light = FALSE;
    BOOL iluminating = FALSE;

    if (!game || !name) {
        return ERROR;
    } 

    iluminating = game_inventory_objects_are_iluminated(game);

    if (strcmp(name, "") == 0) {
        return ERROR;
    }
    
    if (strcasecmp(name, "s") == 0 || strcasecmp(name, "space") == 0) {

        for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++){   
            
            light = space_get_light(game->spaces[i]);
            if(space_get_id(game->spaces[i]) == game_get_player_location(game))
            {   
                space = game->spaces[i];

                if (light ==  TRUE ||  iluminating == TRUE)
                {
                    
                    return command_set_description_large(game->last_cmd, space_get_description_large(space));
                }
                else
                {
                    command_set_description_large(game->last_cmd, "You cant see nothing in the current space, theres no light");
                    return ERROR;
                }
                
            }
        }
    }
    else{
        id = game_find_object_byname(game, name);

        if (id != NO_ID) 
        {
            object = game_get_object(game, id);
            return command_set_description_large(game->last_cmd, object_get_description(object));
        }
    }
    

    

    return ERROR;
}

STATUS game_command_open(Game *game, char *object) {
    Object * obj = NULL;
    int i = 0;
    Id obj_id = NO_ID, dependency = NO_ID;
    BOOL dep_in_inv = FALSE;

    if (!game || !object)
    {
        return ERROR;
    }
    
    obj_id = game_find_object_byname(game, object);

    if (obj_id == NO_ID)
    {
        return ERROR;
    }

    obj = game_get_object(game, obj_id);

    if (!obj)
    {
        return ERROR;
    }
    
    dependency = object_get_dependency(obj);
    if(dependency != NO_ID){
        dep_in_inv = player_id_in_inventory(game_get_player(game), dependency);
    }
    else{
        
        dep_in_inv = TRUE;
    }

    if (player_id_in_inventory(game->player, obj_id) == TRUE && dep_in_inv == TRUE)
    {    
        for (i = 0; i < MAX_LINKS; i++)
        {
            if (link_get_id(game->links[i]) == object_get_open(obj))
            {
                if (game_get_player_location(game) ==  link_get_origin(game->links[i]))
                {
                    if (link_set_open(game->links[i], TRUE))
                    {
                        player_del_object_inventory(game_get_player(game),obj_id);
                        return OK;
                    }
                }
                
            }
        }
    }
    
    return ERROR;
}

/**
 * The player attack the enemy
 */
STATUS game_command_attack(Game *game) {
    
    int n;
    if (game == NULL){
        return ERROR;
    }
        

    if (game_get_enemy_location(game) == game_get_player_location(game) && enemy_get_health(game->enemy) != 0)
    {
        n = rand() % 10;
        if (n > 4 && n < 9)
        {
            /*gana vanesa*/
            enemy_set_health(game->enemy, enemy_get_health(game->enemy) - 1);
        }
        else if (n < 5 && n >= 0)
        {
            /*gana monica*/
            player_set_health(game->player, player_get_health(game->player) - 1);
        }
        else
        {
            /*error*/
            return ERROR;
        }
    }
    else
    {
        return ERROR;
    }
    

    return OK;
}

STATUS game_command_save(Game *game, char *filename) {
/*
    if(!game || !filename)
    {
        return ERROR;
    }
   
    if(game_save_in_file(game, filename) == ERROR)
    {
        return ERROR;
    }
*/
    return OK;
    
}

STATUS game_command_load(Game **game, char *filename) {

    if(!(*game) || !filename)
    {
        return ERROR;
    }
    
    if(game_load_from_file(game, filename) == ERROR)
    {
        return ERROR;
    }
    
    return OK;
    
    
}

/** The object turn on if it can be ligthed
 */
STATUS game_command_on(Game *game, char *object) {
    int i = 0;
    Id obj_id = 0,dependency = NO_ID;
    Object * obj;
    BOOL in_inventory = FALSE;

    if (!game || !object)
    {
        return ERROR;
    }

    obj_id = game_find_object_byname(game, object);

    if (obj_id == NO_ID)
    {
        return ERROR;
    }
    
    obj = game_get_object(game,obj_id);
    
    if (obj == NULL)
    {
        return ERROR;
    }

    dependency = object_get_dependency(obj);

    if(dependency != NO_ID){
        in_inventory = inventory_find_object(player_get_inventory(game_get_player(game)),dependency);
    }
    
    
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        
        if (space_get_id(game->spaces[i]) == game_get_player_location(game))
        {
        
            if (dependency == NO_ID || in_inventory == TRUE) 
            {   
                if (object_get_iluminate(obj) == TRUE && object_get_turnedon(obj) == FALSE){
                    
                    if (object_set_turnedon(obj, TRUE) == OK)
                    {
                        return OK;

                    }
                }
                
            }
        }
    }
    
    return ERROR;
 
}

/** The object turns off
 */

STATUS game_command_off(Game *game, char *object) {

    
    int i = 0;
    Id obj_id = NO_ID;
    Object * obj;
    

    if (!game || !object)
    {
        return ERROR;
    }

    obj_id = game_find_object_byname(game, object);

    if (obj_id == NO_ID)
    {
        return ERROR;
    }
    
    obj = game_get_object(game,obj_id);
    
    if (obj == NULL)
    {
        return ERROR;
    }
    
    
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        
        if (space_get_id(game->spaces[i]) == game_get_player_location(game))
        {
        
            
            if (object_get_iluminate(obj) == TRUE && object_get_turnedon(obj) == TRUE){
                
                if (object_set_turnedon(obj, FALSE) == OK)
                {
                    return OK;

                }
            }
            
        }
    }
    
    return ERROR;
    
}

STATUS game_rule_enemy_respawn(Game *game) {

    if (!game)
    {
        return ERROR;
    }

    if (enemy_get_health(game->enemy) <= 0)
    {
        if(enemy_set_health(game->enemy, DEFAULT_HEALTH_ENEMY) == OK)
        {
            if (rule_set_description(game->last_rule, "Monica volvio a aparecer"))
            {
                return OK;
            }
        }
    }
    

    return ERROR;
}

STATUS game_rule_enemy_loc(Game *game) {

    if (!game)
    {
        return ERROR;
    }

    if (enemy_get_health(game->enemy) > 0)
    {
        if(enemy_set_location(game->enemy, game_get_player_location(game) == OK))
        {
            if (rule_set_description(game->last_rule, "Monica persigue a Vanesa hasta alcanzarla"))
            {
                return OK;
            }
        }
    }

    return ERROR;
}

STATUS game_rule_off(Game *game) {

    int i = 0;
    if (!game)
    {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        
        if (space_get_id(game->spaces[i]) == game_get_player_location(game))
        {
            if (space_get_light(game->spaces[i]) == TRUE)
            {
                if(space_set_light(game->spaces[i], FALSE) == OK)
                {
                    if (rule_set_description(game->last_rule, "Una oscura bruma innunda la sala"))
                    {
                        return OK;
                    }
                }
            }
            
        }
    }
    

    return ERROR;
}

STATUS game_rule_drop(Game *game) {

    Id  *ids = NULL;
    Inventory * inv = NULL;
    Object * obj = NULL;

    if (!game)
    {
        return ERROR;
    }

    inv = player_get_inventory(game->player);

    if (inv == NULL) 
    {
        return ERROR;
    }

    ids = inventory_get_ids(inv);

    if (ids == NULL)
    {
        return ERROR;
    }
    
    obj = game_get_object(game, ids[0]);

    if (obj == NULL)
    {
        return ERROR;
    }
    
    
    if (player_inventory_is_empty(game->player) == FALSE)
    {
        if(game_command_drop(game, object_get_name(obj)) == OK)
        {
            if (rule_set_description(game->last_rule, "Se te ha caido un objeto"))
            {
                return OK;
            }
        }        
        
    }
    

    return ERROR;
}

STATUS game_rule_rock(Game *game) {

    int health = 0;
    if (!game)
    {
        return ERROR;
    }

    health = player_get_health(game->player);

    if (health > 1)
    {
        if (player_set_health(game->player, health - 1))
        {
            if (rule_set_description(game->last_rule, "Ha caido una roca del techo, el jugador pierde un punto de vida"))
            {
                return OK;
            }
        }
        
    }
    

    return ERROR;
}

STATUS game_rule_paralized(Game *game) {

    return OK;
}


/**
 * gets the objects in the game
*/
Object ** game_get_objects(Game *game)
{
    if (game == NULL) {
        return NULL;
    }

    return game->objects;
}

/**
 * checks if theres a turned on object in the inventory wich can iluminate a space
 */
BOOL game_inventory_objects_are_iluminated(Game *game)
{
    
    Object *object;
    int i=0;
    Id *objs_id;
    
    if(game == NULL){
        return FALSE;
    }
   
    if(player_inventory_is_empty(game_get_player(game)) == TRUE){
        return FALSE;
    }
    

    objs_id = set_get_ids(player_get_objects_inventory(game->player));
    
    
    for(i=0; objs_id[i] != NO_ID && i< MAX_OBJECTS; i++){
        
        object = game_get_object(game, objs_id[i]);

        if(object_get_iluminate(object) == TRUE){
            
            if(object_get_turnedon(object) == TRUE){
                return TRUE;
                
            }
        }

        
    }
    

    return FALSE;
}


/**
 * gets the spaces in the game 
*/
Space ** game_get_spaces(Game * game)
{
    if (game == NULL) {
        return NULL;
    }

    return game->spaces;
}

/**
 * gets the links in the game
*/
Link ** game_get_links(Game * game)
{
    if(game == NULL) 
    {
        return NULL;
    }

    return game->links;
}


/** 
 * gets the status of the connection of a determinated link
*/
BOOL game_get_connection_status(Game *game, Id space, DIRECTION dir)
{
    int i=0;
    Link **links = NULL;
    
    if(game == NULL || space == NO_ID || dir == NO_DIR){
        return FALSE;
    }

    links = game_get_links(game);
    if(links == NULL) {
        return FALSE;
    }

    for(i=0; i<MAX_LINKS; i++){
        if(link_get_origin(links[i]) == space){
            if(link_get_direction(links[i]) == dir){
                return link_get_open(links[i]);
            }
        }

    }

    return FALSE;    
}

/**
 * gets the destination of a determinated link
*/
Id game_get_connection(Game *game, Id space, DIRECTION dir)
{
    
    int i=0;
    Link **links = NULL;

    if(game== NULL || space == NO_ID || dir == NO_DIR) {
        return NO_ID;
    }

    links = game_get_links(game);
    if(links == NULL) {
        return NO_ID;
    }

    for(i=0; i<MAX_LINKS; i++){
        if(link_get_origin(links[i]) == space){
            if(link_get_direction(links[i]) == dir){
                return link_get_destination(links[i]);
            }
        }

    }

    return NO_ID;    
}
