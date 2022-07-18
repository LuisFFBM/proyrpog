/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game.h"
#include "command.h"

/**
  * @brief Prepares a new game
  * @author Profesores PPROG
  *
  * It creates the spaces and puts them on the interface.
  * 
  * @param game a pointer to Game
  * @param gengine a pointer to a pointer from Graphic_engine
  * @param file_name a pointer to char
  * @return 1 in case of any error, if not returns 0
  */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
  * @brief Principal loop of the game
  * @author Profesores PPROG
  *
  * Constantly checks the user input to update the game accordingly
  * until the command "EXIT" is given, moment when the game is considered over
  * 
  * @param game a pointer to Game
  * @param gengine a pointer to Graphic_engine
  * @return 1 in case of any error, if not returns 0
  */
void game_loop_run(Game game, Graphic_engine *gengine);

/**
  * @brief Frees memory alocated for the game and interface
  * @author Profesores PPROG
  *
  * @param game a pointer to Game
  * @param gengine a pointer to Graphic_engine
  */
void game_loop_cleanup(Game game, Graphic_engine *gengine);

/** Main program
  */
int main(int argc, char *argv[]) {

  Game game;
  Graphic_engine *gengine;

  if (argc < 2)
  {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
 
  if (0 == game_loop_init(&game, &gengine, argv[1]))
  {
    game_loop_run(game, gengine);
    game_loop_cleanup(game, gengine);
  }

  return 0;
}

/** It creates the spaces and puts them on the interface.
  */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name) {
  
  if (game_create_from_file(game, file_name) == ERROR)
  {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL)
  {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

/** Principal loop of the game
  */
void game_loop_run(Game game, Graphic_engine *gengine) {
  Command * command = NULL;
  command = command_create();
  
  while ((command_get_cmd(command) != EXIT) && (game_is_over(&game) == FALSE))
  {
    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();
    game_update(&game, command);
  }
  command_destroy(command);
  
}

/** Frees memory alocated for the game and interface
  */
void game_loop_cleanup(Game game, Graphic_engine *gengine) {
 
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
