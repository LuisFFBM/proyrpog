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
#include "time.h"

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
  * @brief Sets a new enemy location id
  * @author Luis Fernandez
  *
  * game_set_enemy_location sets a new enemy's location
  * indicated by a certain id
  * 
  * @param game a pointer to  Game
  * @param id the new id to locate the enemy
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS game_set_enemy_location(Game *game, Id id);


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
  * @brief Implementation for "LEFT" command
  * @author Joaquin Abad
  *
  * @param game a pointer to  Game
  */
void game_command_left(Game *game);

/**
  * @brief Implementation for "RIGTH" command
  * @author Joaquin Abad
  *
  * @param game a pointer to  Game
  */
void game_command_rigth(Game *game);

/**
  * @brief Implementation for "ATTACK" command
  * @author Joaquin Abad
  *
  * @param game a pointer to  Game
  */
void game_command_attack(Game *game);

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
 void game_command_take(Game *game, Id object);

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

  for (i = 0; i < MAX_SET_ELEMENTS; i++) 
  {
    game->objects[i] = NULL;
  }

  game->player = player_create(PLAYER_INITIAL_ID);
  game->enemy = enemy_create(ENEMY_INITIAL_ID);
  game->last_cmd = command_create();

  return OK;
}
/** reads a file and interpretates it as a space
  * to initialize the elements of it
  */
STATUS game_create_from_file(Game *game, char *filename) {

  if (!game)
  {
    return ERROR;
  }
  
  /*Error control*/
  if (game_create(game) == ERROR)
  {
    return ERROR;
  }
    
  /*Error control*/  
  if (game_reader_load_spaces(game, filename) == ERROR)
  {
    return ERROR;
  }

  /*Error control*/  
  if (game_reader_load_objects(game, filename) == ERROR)
  {
    return ERROR;
  }

  /* The player, enemy and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  /*game_set_object_location(game, game_get_space_id_at(game, 0), 0);*/
  game_set_enemy_location(game, game_get_space_id_at(game, 3));

  return OK;
}

/**
  * It destroys the actual instace of the game
  */
STATUS game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < MAX_SPACES; i++)
  {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    object_destroy(game->objects[i]);
  }

  player_destroy(game->player);

  enemy_destroy(game->enemy);

  command_destroy(game->last_cmd);

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
  * It adds an object to the game
  */
STATUS game_add_object(Game *game, Object *object) {
  int i = 0;

  if (object == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SET_ELEMENTS && game->objects[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SET_ELEMENTS)
  {
    return ERROR;
  }
  /*sets the object pointer in the array of objects of game*/
  game->objects[i] = object;
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

/*It sets the location of game->enemy*/
STATUS game_set_enemy_location(Game *game, Id id) {
  /*Error control*/
  if (!game || id == NO_ID)
  {
    return ERROR;
  }
  /*Error control*/
  if(enemy_set_location(game->enemy,id) == ERROR)
  {
    return ERROR;
  }

  return OK;
}

/*it set drop or take of an object in the game depending on the id of the object in space*/
STATUS game_set_object_location(Game *game,  Id space, Id object) {

  int i = 0;
  /*Error control*/
  if (!game || object == NO_ID || space == NO_ID )
  {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if(space_get_id(game->spaces[i]) == space)
    {
      if(space_add_object(game->spaces[i], object) == OK)
      {
        return OK;
      }
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

/*DOCUMENTAR ESTA*/
/*It returns the location_id of game->enemy*/
Id game_get_enemy_location(Game *game) {
  /*Error control*/
  if(!game)
  {
    return NO_ID;  
  }

  return enemy_get_location(game->enemy);
}

/*It returns the id of game->object*/
Id game_get_object_location(Game *game, Id object) {
  int i;

  if (!game || object == NO_ID)
  {
    return NO_ID;
  }

  for (i=0; game->spaces[i] != NULL && i < MAX_SPACES; i++) 
  {
    if(space_find_object(game->spaces[i], object) == TRUE)
    {
      return space_get_id(game->spaces[i]);
    }
  }
  return NO_ID;
}

/** game_update reads the user input to update 
  * the game according to it
  */
STATUS game_update(Game *game, Command *cmd) {
  if(command_set_cmd(game->last_cmd, command_get_cmd(cmd)) == ERROR)
  {
    return ERROR;
  }
  if(command_set_id(game->last_cmd, command_get_id(cmd)) == ERROR)
  {
    return ERROR;
  }
  
  switch (command_get_cmd(game->last_cmd))
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
    
    case LEFT:
      game_command_left(game);
      break;

    case RIGTH:
      game_command_rigth(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    case TAKE:
      game_command_take(game, command_get_id(cmd));
      break;

    case DROP:
      game_command_drop(game);
      break;
    case ATTACK:
      game_command_attack(game);
      break;

    default:
      break;
  }
  return OK;
}

/** It returns the last cmd command given by user
  */
Command * game_get_last_command(Game *game) {
  if (!game)
  {
    return NULL;
  }
  
  return game->last_cmd;
}
/** It prints the data of the game
  */
void game_print_data(Game *game) {

  int i = 0, j = 0;
  Id *obj_ids = NULL;

  obj_ids = (Id*) calloc(MAX_SET_ELEMENTS, sizeof(Id));
  if(obj_ids == NULL)
  {
    return;
  }

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);

    obj_ids = space_get_object_ids(game->spaces[i]);

    for(j = 0; j < MAX_SET_ELEMENTS && obj_ids[j] != NO_ID; j++) {
      if(object_get_id(game->objects[j]) == obj_ids[j])
      {
        printf("=> Object %s with id %ld in location: %ld ", object_get_name(game->objects[j]), obj_ids[j], space_get_id(game->spaces[i])); 
      }
      
    }

  }

  printf("=> Player location: %ld\n", game_get_player_location(game));
  printf("=> Enemy location: %ld\n", game_get_enemy_location(game));

  free(obj_ids);
}

BOOL game_is_over(Game *game) {

  if (player_get_health(game->player) <= 0)
  { 
    return TRUE;
  }
  
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

/** Implementation for "LEFT" command
  */
void game_command_left(Game *game) {
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
      current_id = space_get_west(game->spaces[i]);

      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }

      return;
    }
  }
}

/** Implementation for "RIGTH" command
  */
void game_command_rigth(Game *game) {
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
      current_id = space_get_east(game->spaces[i]);

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
void game_command_take(Game *game, Id object)
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
      if (space_get_object_ids(game->spaces[i])!=NULL)
      {
        /*Checks if the object is in the space*/
        if(space_find_object(game->spaces[i], object) == TRUE)
        {
          /*Checks if the player already has an object*/
          if(player_get_object_id(game->player) == NO_ID)
          {
            /*Sets player's object to the indicated one*/
            if(player_set_object_id(game->player, object) == OK)
            {
              /*Deletes that object from the space*/
              space_del_object(game->spaces[i], object);
            }
          }
        }
      }
    return;
    } 
  } 
}

/** Implementation for "DROP" command
  */
void game_command_drop(Game *game) {
  int i = 0;

  if (game_get_player_location(game) == NO_ID || game == NULL)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    /*Checks that the player is in the actual space*/
    if (space_get_id(game->spaces[i]) == game_get_player_location(game))
    {
      /*Checks that the player has an object to drop*/
      if (player_get_object_id(game->player) != NO_ID)
      {
        /*Adds the player's object to the actual space*/
        if (space_add_object(game->spaces[i], player_get_object_id(game->player)) != ERROR)
        {
          /*Sets the player's object to NO_ID*/
          player_set_object_id(game->player, NO_ID);
        }
      }
              
      return;
    }
  } 
}

void game_command_attack(Game *game) {
  int i, h = 0;
  srand(time(NULL));

  if (game == NULL)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_get_id(game->spaces[i]) == game_get_player_location(game))
    {    
      if (game_get_enemy_location(game) == game_get_player_location(game))
      {
        if(player_get_health(game->player) > 0 && enemy_get_health(game->enemy) > 0)
        {
          h = rand() % 10;
          if (h >= 0 && h < 5)
          {
            enemy_set_health(game->enemy,enemy_get_health(game->enemy)-1);
          }
          else if (h >= 5 && h < 9)
          {
            player_set_health(game->player,player_get_health(game->player)-1);
          }
          else
          {
            return;
          }
        }
        if (player_get_health(game->player) <= 0)
        {
          game_is_over(game);
        }
        else
        {
          return;
        }
      }
    }
  }
}


