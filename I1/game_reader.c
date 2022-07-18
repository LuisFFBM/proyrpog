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
  if (file == NULL)
  {
    return ERROR;
  }

  /*
   * Reads the file lineby line
   * take each line and separates it with "|"
   * it saves each part in one variable.
   * It uses the variables in the functions from space.c
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
        /*uses the functions to define the values of each part of the type */
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
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

