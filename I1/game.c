/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @author Joaquin Abad
 * @author Luis Fernandez
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

/**
   Private functions
*/

/**
  * @brief Gets the id of the space located on a certain position
  * @author Profesores PPROG
  *
  * game_get_space_id_at returns the id of the space
  * located on a certain postion
  * 
  * @param game a pointer to  Game
  * @param position the number related to the space we want to check
  * @return the id number of the space ot NO_ID in case of void space or in case of an error
  */
Id game_get_space_id_at(Game *game, int position);

/**
  * @brief Sets a new player location id
  * @author Luis Fernandez
  *
  * game_set_player_location sets a new player's location
  * indicated by a certain id
  * 
  * @param game a pointer to  Game
  * @param id the new id to locate the player
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_player_location(Game *game, Id id);

/**
  * @brief Sets a new object location id
  * @author Joaquin Abad
  *
  * game_set_object_location sets a new object's location
  * indicated by a certain id
  * 
  * @param game a pointer to  Game
  * @param id the new id to locate the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_object_location(Game *game, Id id);

/**
  * @brief Implementation in case of unknown command
  * @author Profesores PPROG
  *
  * @param game a pointer to  Game
  */
void game_command_unknown(Game *game);

/**
  * @brief Implementation for "EXIT" command
  * @author Profesores PPROG
  *
  * @param game a pointer to  Game
  */
void game_command_exit(Game *game);

/**
  * @brief Implementation for "NEXT" command
  * @author Profesores PPROG
  *
  * @param game a pointer to  Game
  */
void game_command_next(Game *game);

/**
  * @brief Implementation for "BACK" command
  * @author Profesores PPROG
  *
  * @param game a pointer to  Game
  */
void game_command_back(Game *game);

/**
  * @brief Implementation for "TAKE" command
  * @author Joaquin Abad
  *
  * @param game a pointer to  Game
  */
 void game_command_take(Game *game);

 /**
  * @brief Implementation for "DROP" command
  * @author Joaquin Abad
  *
  * @param game a pointer to  Game
  */
 void game_command_drop(Game *game);

/**
   Game interface implementation
*/

/** It initializes the game elements
  */
STATUS game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) 
  {
    game->spaces[i] = NULL;
  }

  game->object = object_create(OBJECT_INITIAL_ID);
  game->player = player_create(PLAYER_INITIAL_ID);
  game->last_cmd = NO_CMD;

  return OK;
}
/** reads a file and interpretates it as a space
  * to initialize the elements of it
  */
STATUS game_create_from_file(Game *game, char *filename) {
  /*Error control*/
  if (game_create(game) == ERROR){
    return ERROR;
  }
    
  /*Error control*/  
  if (game_reader_load_spaces(game, filename) == ERROR){
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/**
  * It destroys the actual instace of the game
  */
STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  return OK;
}
/**
  * It adds a space to the game
  */
STATUS game_add_space(Game *game, Space *space) {
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}
/**
  * game_get_space_id_at gets de id of a certain space
  */
Id game_get_space_id_at(Game *game, int position) {

  if (!game || position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/**
  * It gets a pointer to a specific space
  */
Space *game_get_space(Game *game, Id id) {
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

/*It sets the location of game->player*/
STATUS game_set_player_location(Game *game, Id id) {
  /*Error control*/
  if (!game || id == NO_ID)
  {
    return ERROR;
  }
  /*Error control*/
  if(player_set_location_id(game->player,id) == ERROR)
  {
    return ERROR;
  }

  return OK;
}
/*it set drop or take of an object in the game depending on the id of the object in space and player*/
STATUS game_set_object_location(Game *game, Id id) {

  int i = 0;
  /*Error control*/
  if (!game || id == NO_ID)
  {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if(space_get_id(game->spaces[i]) == id)
    {
      if(space_get_object(game->spaces[i]) == NO_ID)
      {
        if(space_set_object(game->spaces[i], object_get_id(game->object) == ERROR))
        {
          return ERROR;
        }

        return OK;
      }

      return OK;
    }
  }

  return ERROR;
}


/*It returns the location_id of game->player*/
Id game_get_player_location(Game *game) {
  /*Error control*/
  if(!game)
  {
    return NO_ID;  
  }

  return player_get_location_id(game->player);
}

/*It returns the id of game->object*/
Id game_get_object_location(Game *game) {
  int i;

  if (!game)
  {
    return NO_ID;
  }

  for (i=0; game->spaces[i] != NULL && i < MAX_SPACES; i++) 
  {
    if (space_get_object(game->spaces[i]) != NO_ID) 
    {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

/** game_update reads the user input to update 
  * the game according to it
  */
STATUS game_update(Game *game, T_Command cmd) {
  game->last_cmd = cmd;
  
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    case TAKE:
      game_command_take(game);
      break;

    case DROP:
      game_command_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

/** It returns the last cmd command given by user
  */
T_Command game_get_last_command(Game *game) {
  return game->last_cmd;
}
/** It prints the data of the game
  */
void game_print_data(Game *game) {

  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %ld\n", game_get_object_location(game));
  printf("=> Player location: %ld\n", game_get_player_location(game));

}

BOOL game_is_over(Game *game) {

  return FALSE;
}

/**
   Calls implementation for each action 
*/

/** Implementation in case of unknown command
  */
void game_command_unknown(Game *game)
{
}
/** Implementation for "EXIT" command
  */
void game_command_exit(Game *game)
{ 
}
/** Implementation for "NEXT" command
  */
void game_command_next(Game *game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }
  /* Checks if its another space to move on */
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }

      return;
    }
  }
}

/** Implementation for "BACK" command
  */
void game_command_back(Game *game) {

  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }
  /* Checks if its space to go back */
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);

    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }

      return;
    }
  }
}

/** Implementation for "TAKE" command
  */
void game_command_take(Game *game)
{
  int i = 0;

  if (game == NULL)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == game_get_player_location(game))
    {
      /*Checks if there is already an object in the current space */
      if (space_get_object(game->spaces[i])!=NO_ID)
      {
        /*This eliminates the object in the current space*/
        if(space_set_object(game->spaces[i], NO_ID) == ERROR)
        {
          return;
        }
        /*This sets an object on player's possesions*/
        if(player_set_object_id(game->player, space_get_object(game->spaces[i]) == ERROR))
        {
          return;
        }
        
        return;
      }
    } 
  } 
}

/** Implementation for "TAKE" command
  */
void game_command_drop(Game *game) {
  int i = 0;

  if (game_get_player_location(game) == NO_ID || game == NULL)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == game_get_player_location(game))
    {
      /*Checks if there is already an object in the current space */
      if (space_get_object(game->spaces[i])== NO_ID && game_get_object_location(game) == NO_ID)
      {
        /*This sets an object on current space*/
        if(space_set_object(game->spaces[i], player_get_object_id(game->player) == ERROR))
        {
          return;
        }
        /*This eliminates the object possessed by the player*/
        if(player_set_object_id(game->player, NO_ID) == ERROR)
        {
          return;
        }
        
        return;
      }
    } 
  }  
}


