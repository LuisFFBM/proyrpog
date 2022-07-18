/**
 * @brief Contains the functions for loading spaces in a game
 * 
 * 
 * @file GameReader.c
 * @author  Luis Fernandez
 * @version 1.0
 * @date 5-2-2022 
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_reader.h"


/**
 * reads a file and interpretates it as a space to include it in the pointer to Game (game)
 */
STATUS game_reader_load_spaces(Game *game, char *filename) {
  
  /* Initializes the pointers and the variables */
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  int i=0;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  /* Error control */
  if (!filename)
  {
    return ERROR;
  }

  /* opens the file to read it */
  file = fopen(filename, "r");
  
  /* Error control */
  if (!file)
  {
    return ERROR;
  }

  /*
   * Reads the file lineby line
   * take each line and separates it with "|"
   * it saves each part in one variable.
   * It uses the variables in the functions from space.c
   * 
   * Does the same for the objects
   */
  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      
      
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      /* Error control */
      if (space != NULL)
      {
        /*uses the functions to define the values of each part of the type Space*/
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        /*defines each line of the graphic description of the space*/
        for(i=0; i < N_LINES; i++){
          toks = strtok(NULL, "|");
          space_set_gdesc(space, toks, i);
        }
        /*adds everything to the current space in the game*/
        game_add_space(game, space);
      }
    }
   
  }


  /* Error control */
  if (ferror(file))
  {
    status = ERROR;
  }
  
  fclose(file);

  return status;
}

STATUS game_reader_load_objects(Game* game, char* filename){

  /* Initializes the pointers and the variables */
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char obj_name[WORD_SIZE] = "";
  char *toks = NULL;
  Id obj_id = NO_ID, obj_pos = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

   if (!filename)
  {
    return ERROR;
  }

  /* opens the file to read it */
  file = fopen(filename, "r");
  
  /* Error control */
  if (!file)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if(strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      obj_id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(obj_name, toks);
      toks = strtok(NULL, "|");
      obj_pos = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", obj_id, obj_name, obj_pos);
#endif
      object = object_create(obj_id);
      /*Error control*/
      if(!object)
      {
      status = ERROR;
      }
      /*uses the functions to define the values of each part of the type*/
      object_set_name(object, obj_name);
      /*adds the object id to the game space object set*/
      game_set_object_location(game, obj_pos, obj_id);
      /*adds everything to the object game*/
      game_add_object(game, object);
    }
  }

  /* Error control */
  if (ferror(file))
  {
    status = ERROR;
  }
  
  fclose(file);

  return status;
}