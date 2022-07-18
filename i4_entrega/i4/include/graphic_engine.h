/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG, Óskar, Álexx
 * @version 4.0
 * @date 12-03-2022
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Graphic_engine gets intialized allocating the necessary
 * memory
 * @author Álexx
 *
 * @return a pointer to the Graphic_engine structure
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief Frees the Graphic_engine structure
 * @author Profesores PPROG
 *
 * @param ge pointer to Graphic_engine
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It prints all the screen areas with the game information
 * @author Óskar
 *
 * @param ge a pointer to the Graphic_engine
 * @param game a pointer to the game structure
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
 * @brief ***it does not exist***
 * @author None
 *
 * @param ge a pointer to Graphic_engine
 * @param str a pointer to a string
 */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
