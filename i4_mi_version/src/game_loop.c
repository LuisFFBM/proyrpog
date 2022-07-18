/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 3.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <strings.h>
#include "../include/graphic_engine.h"
#include "../include/game.h"
#include "../include/command.h"


/**
 * @brief A new game is created from a file and a graphics engine
 *
 * @param game a pointer to the game struct
 * @param gengine a double pointer to the graphic engine
 * @param file_name a string with the file name
 * @return int with success/error code
 */
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name);

/**
 * @brief this functions run the game_loop
 *
 * A loop is created until an exit condition or game over condition is met.
 * As long as these conditions are not met, the necessary calls to functions are made to update the game.
 *
 * @param game a pointer to game struct
 * @param gengine a pointer to the graphic engine struct
 */
void game_loop_run(Game *game, Graphic_engine *gengine);

/**
 * @brief this function cleanup the game loop
 *
 * The functions responsible for freeing the memory of the different
 * structures that make up the game are called
 * @param game a pointer game struct
 * @param gengine a pointer to the graphic engine struct
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

int main(int argc, char *argv[])
{
    Game *game = NULL;
    Graphic_engine *gengine;

    if (argc < 2)
    {
        fprintf(stderr, "Use: %s <game_data_file> [(optional) -l <logfile>]\n", argv[0]);
        return 1;
    }
    
    if(argc == 4){
        if (0 == strcasecmp("-l", argv[2]))
        {
            command_set_logfile(argv[3]);
        }
        else
        {
            command_set_logfile(NULL);
        }
    }
    else
    {
        command_set_logfile(NULL);
    }

    if (!game_loop_init(&game, &gengine, argv[1]))
    {
        game_loop_run(game, gengine);
        game_loop_cleanup(game, gengine);
    }

    return 0;
}

/**
 * A new game is created from a file and a graphics engine
 *
 */
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name)
{
    srand(time(NULL));

    if (game_load_from_file(game, file_name) == ERROR)
    {
        fprintf(stderr, "Error while initializing game.\n");
        
        return 1;
    }  

    if ((*gengine = graphic_engine_create()) == NULL)
    {
        fprintf(stderr, "Error while initializing graphic engine.\n");
        game_destroy(*game);
        return 1;
    }

    return 0;
}

/**
 * A loop is created until an exit condition or game over condition is met.
 * As long as these conditions are not met, the necessary calls to functions are made to update the game.
 */
void game_loop_run(Game *game, Graphic_engine *gengine)
{
    Command *command;
    command = command_create();

    while ((command_get_cmd(command) != EXIT) && !game_is_over(game))
    {
        command_destroy(command);
        graphic_engine_paint_game(gengine, game);
        command = command_get_user_input();
        game_update(game, command);
    }

    command_destroy(command);

    if (game_is_over(game))
    {
        printf("Game over\n");
    }
    else
    {
        printf("Game exited\n");
    }
}

/**
 * The functions responsible for freeing the memory of the different
 * structures that make up the game are called
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine)
{
    game_destroy(game);
    graphic_engine_destroy(gengine);
}
