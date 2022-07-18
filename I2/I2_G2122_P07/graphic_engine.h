/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief It creates a map inteface
  * @author Profesores PPROG
  *
  * graphic_engine_create allocates memory for the interface the player interacts with
  * and stablish the dimensions and caracteristics of it trough screen related functions 
  *
  * @return a pointer to Graphic_engine
  */
Graphic_engine *graphic_engine_create();
/**
  * @brief It destroys the interfaz
  * @author Profesores PPROG
  *
  * it destroys the interface and free the memory saved for it
  *
  * @param ge a pointer to Graphic_engine
  */
void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief Shows game interface on screen
  * @author Profesores PPROG
  *
  * it paints on screen individualy the diferent elements that
  * form the game
  *
  * @param ge a pointer to Graphic_engine
  * @param game a pointer to Game
  */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
  * @brief Shows game interface on screen
  * @author Profesores PPROG
  *
  * it paints on screen individualy the diferent elements that
  * form the game
  *
  * @param ge a pointer to Graphic_engine
  * @param str a pointer to char
  */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
