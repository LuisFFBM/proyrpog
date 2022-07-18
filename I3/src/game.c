/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG, Joaquin, Javii, Oskar y Alexx
 * @version 3.0
 * @date 17-02-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../include/game.h"
#include "../include/game_reader.h"


/**
 * @brief Structure that contains the different data of the game
 */
struct _Game
{
    Player *player;                 /*!< player in the game*/
    Enemy *enemy;                   /*!< enemy in the game*/
    Object *objects[MAX_OBJECTS];   /*!< objects in the game*/
    Space *spaces[MAX_SPACES];      /*!< spaces in the game*/
    Command *last_cmd;              /*!< last command in the game*/
    Link *links[MAX_LINKS];         /*!< link between spaces in the game*/
};


/*declaraciones de valores default*/
#define DEFAULT_PLAYER_ID 1
#define DEFAULT_PLAYER_NAME "Jose Pintos y Vanesssa"

#define DEFAULT_OBJECT_ID 1
#define DEFAULT_OBJECT_NAME "Grano"

#define DEFAULT_ENEMY_ID 1
#define DEFAULT_ENEMY_NAME "Monica"

#define DEFAULT_INVENTORY_SIZE 4

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
 * @brief Operations are performed to advance one space
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_next(Game *game);


/**
 * @brief Operations are performed to move back one space
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_back(Game *game);

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
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_take(Game *game, char *object);

/**
 * @brief The item is removed from the player's inventory and assigned to the space
 *
 * @author Joaquin
 *
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_drop(Game *game, char *object);

/**
 * @brief Operations are performed to move one space to the left
 * @author Alexx
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_left(Game *game);

/**
 * @brief Operations are performed to move one space to the right
 * @author Alexx
 * @param game pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_right(Game *game);

/**
 * @brief The player attack the enemy
 * @author Oskar
 * @param game  a pointer to the game struct
 * @return returns ERROR if something fails and OK if everything runs fine
 */
STATUS game_command_attack(Game *game);

/**
 * @brief It finds an object Id trough a name
 * @author Joaquin
 *
 * @param game pointer to the game structure
 * @param name of the object to find
 * @return the object id
 */
Id game_find_object_byname(Game *game, char *name);

Id game_find_space_byname(Game *game, char *name);

STATUS game_command_inspect(Game *game, char *name);

/**
   Game interface implementation
*/
/*
 *it creates the game and reserve memory for it
 */
Game *game_create()
{
    Game *game = NULL;
    Inventory *rinyo;
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

    rinyo=inventory_create(DEFAULT_INVENTORY_SIZE);
    
    game->player = player_create(DEFAULT_PLAYER_ID, DEFAULT_PLAYER_NAME, NO_ID, rinyo, 3);
    game->enemy = enemy_create(DEFAULT_ENEMY_ID, DEFAULT_ENEMY_NAME, 123, 3);
    game->last_cmd = command_create();

    return game;
}

/**
 * This function creates the game from the file information
 */

STATUS game_create_from_file(Game **game, char *filename)
{
    
    *game = game_create();

    if(*game == NULL)
    {
        return ERROR;
    }
    
    
    if (game_reader_load_spaces(*game, filename) == ERROR)
        return ERROR;

    if (game_reader_load_objects(*game, filename) == ERROR)
        return ERROR;
    if (game_reader_load_player(*game, filename) == ERROR)
        return ERROR;
    if (game_reader_load_link(*game,filename)==ERROR)
        return ERROR;

    /* The player and the object are located in the first space */
    game_set_player_location(*game, game_get_space_id_at(*game, 0));

    return OK;
}

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

/**gets a space id according to its position in the array of game spaces
 *
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

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
        if (oldlocation == space_get_id(game->spaces[i]))
        {
            space_remove_object(game->spaces[i], object);
        }
    }

    if (location != NO_ID)
    {
        for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
        {
            if (space_get_id(game->spaces[i]) == location)
            {
                space_add_object(game->spaces[i], object);
            }
        }
    }

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
  if(command_set_status(game->last_cmd, command_get_status(cmd)) == ERROR)
  {
    return ERROR;
  }

  if(command_set_description(game->last_cmd, command_get_description(cmd)) == ERROR)
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
    Id current_id = NO_ID;
    Id player_location = NO_ID;
    int i;

    if (game == NULL || input == NULL) {
        return ERROR;
    }

    if (strcmp(input, "next") == 0 || strcmp(input, "n") == 0) {
        direction = S;
    } else if (strcmp(input, "back")  == 0 || strcmp(input, "b") == 0) {
        direction = N;
    } else if (strcmp(input, "right")  == 0 || strcmp(input, "r") == 0) {
        direction = E;
    } else if (strcmp(input, "left")  == 0 || strcmp(input, "l") == 0) {
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


    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++){
        current_id = space_get_id(game->spaces[i]);

        if (current_id == player_location)
        {
            if(game_get_connection_status(game, current_id, direction) == OK)
            {
                if(game_set_player_location(game, game_get_connection(game, current_id, direction)) == OK)
                {
                    return OK;
                }
            }

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
            /*Sets player's object to the indicated one*/
            if(player_add_object_inventory(game->player,object_id) == OK)
            {
              /*Deletes that object from the space*/
              space_remove_object(game->spaces[i], object_id);
              return OK;
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
    Space * space = NULL;
    Object * object = NULL;

    if (!game) {
        return ERROR;
    } 

    id = game_find_object_byname(game, name);

    if (id != NO_ID) {
        object = game_get_object(game, id);
        return command_set_description(game->last_cmd, object_get_description(object));
    } else {
        id = game_find_space_byname(game, name);
        space = game_get_space(game, id);
        return command_set_description(game->last_cmd, space_get_description(space));
    }
}

/**
 * The player attack the enemy
 */
STATUS game_command_attack(Game *game)
{
    int n;
    if (!game)
        return ERROR;

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
STATUS game_get_connection_status(Game *game, Id space, DIRECTION dir)
{
    int i=0;
    Link **links = NULL;
    
    if(game == NULL || space == NO_ID || dir == NO_DIR){
        return ERROR;
    }

    links = game_get_links(game);
    if(links == NULL) {
        return ERROR;
    }

    for(i=0; i<MAX_LINKS; i++){
        if(link_get_origin(links[i]) == space){
            if(link_get_direction(links[i]) == dir){
                return link_get_status(links[i]);
            }
        }

    }

    return ERROR;    
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