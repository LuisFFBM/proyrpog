/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 40
#define COLUMNS 120
#define MAX_MAP_STRING 17
#define MAX_ENEMY 7

/**
 * @brief Game
 *
 * This struct stores all the information of a graphic_engine elements.
 */
struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback; /*!<pointers with information for the user interface*/
};

/** graphic_engine_create creates the visual interface for the game 
 */

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge)
  {
    return ge;
  }
  
  screen_init(ROWS, COLUMNS);

  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
  {
    return NULL;
  }
    
  ge->map = screen_area_init(3, 1, 62, 25);
  ge->descript = screen_area_init(67, 1, 45, 25);
  ge->banner = screen_area_init(65, 27, 20, 3);
  ge->help = screen_area_init(3, 27, 110, 4);
  ge->feedback = screen_area_init(3, 32, 110, 4);

  return ge;
}

/** graphic_engine_destroy destroys the interface and free 
 * the memory saved for it 
 */
void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge)
  {
    return;
  }
    

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/** Shows game interface on screen
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  int i = 0;
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_right = NO_ID, id_left = NO_ID, obj_loc = NO_ID, obj_id = NO_ID, *obj_ids = NULL;
  Space *space_act = NULL;
  char right[3] = "", left[3] = "", obj[MAX_MAP_STRING]= "", enemy[MAX_ENEMY] = "", com_er[10] = "", obj_aux[7] = "", obj_aux_aux[17]= "";
  char str[255] = "";
  
  Command * last_input = NULL;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_right = space_get_east(space_act);
    id_left = space_get_west(space_act);
    
    /*creates the string with the objects of each space and puts ... if they dont fit*/
    strcpy(obj, "");
    obj_ids = space_get_object_ids(game_get_space(game, id_back));
    if(obj_ids != NULL)
    {
      for(i=0; (i < MAX_SET_ELEMENTS) && (obj_ids[i] != NO_ID || obj_ids[i+1] != NO_ID) && (strlen(obj) < (MAX_MAP_STRING-5)); i++){
        obj_id = obj_ids[i]; 
        sprintf(obj_aux, "O%ld,", obj_id);
        strcat(obj, obj_aux);     
      }
      if(obj_ids[i] != NO_ID)
      {
        strcat(obj, "...");
        while(strlen(obj) < MAX_MAP_STRING){
          strcat(obj, " ");
        }
      }
      else{
        obj[strlen(obj)-1] = 0;
        while(strlen(obj) < MAX_MAP_STRING){
          strcat(obj, " ");
        }
      }
    } 
    /*-----------------------------------------------------------*/ 

    if (id_back != NO_ID)
    {
      if(game_get_enemy_location(game) == id_back && enemy_get_health(game->enemy) > 0)
      {
        sprintf(enemy, "/\\oo/\\");  
      }
      else
      {
        sprintf(enemy, "      ");
      }

      sprintf(str, "  |      %s  %3d|", enemy,(int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }

    
   /*left and right space indicators activation*/
    if (id_left != NO_ID) 
    {
      sprintf(left, "<<");
    }
    else 
    {
      sprintf(left, "  ");
    }

    if (id_right != NO_ID)
    {
      strcpy(right, ">>");
    }
    else 
    {
      sprintf(right, "  ");
    }

    
    
    /*creates the string with the objects of each space and puts ... if they dont fit*/
    strcpy(obj, "");
    obj_ids = space_get_object_ids(game_get_space(game, id_act));
    if(obj_ids != NULL)
    {
      for(i=0; (i < MAX_SET_ELEMENTS) && (obj_ids[i] != NO_ID || obj_ids[i+1] != NO_ID) && (strlen(obj) < (MAX_MAP_STRING-5)); i++){
        obj_id = obj_ids[i]; 
        sprintf(obj_aux, "O%ld,", obj_id);
        strcat(obj, obj_aux);     
      }
      if(obj_ids[i] != NO_ID)
      {
        strcat(obj, "...");
        while(strlen(obj) < MAX_MAP_STRING){
          strcat(obj, " ");
        }
      }
      else{
        obj[strlen(obj)-1] = 0;
        while(strlen(obj) < MAX_MAP_STRING){
          strcat(obj, " ");
        }
      }
    } 
    /*-----------------------------------------------------------*/ 

    

    if (id_act != NO_ID)
    { 
      if(game_get_enemy_location(game) == id_act && enemy_get_health(game->enemy) > 0)
      {
        sprintf(enemy, "/\\oo/\\");  
      }
      else
      {
        sprintf(enemy, "      ");
      }

      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);
      /*\\(\")/ CODIFICACION HORMIGA */
      sprintf(str, "  | m0^  %s  %3d|  ", enemy,(int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |  ", space_get_gdesc(game_get_space(game, id_act),0));
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |  ", space_get_gdesc(game_get_space(game, id_act),1));
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |  ", space_get_gdesc(game_get_space(game, id_act),2));
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |  ", space_get_gdesc(game_get_space(game, id_act),3));
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s        |  ", space_get_gdesc(game_get_space(game, id_act),4));
      screen_area_puts(ge->map, str);
      sprintf(str, "%s|%s|%s", left, obj, right);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);
    }

    /*creates the string with the objects of each space and puts ... if they dont fit*/
    strcpy(obj, "");
    obj_ids = space_get_object_ids(game_get_space(game, id_next));
    if(obj_ids != NULL)
    {
      for(i=0; (i < MAX_SET_ELEMENTS) && (obj_ids[i] != NO_ID || obj_ids[i+1] != NO_ID) && (strlen(obj) < (MAX_MAP_STRING-5)); i++){
        obj_id = obj_ids[i]; 
        sprintf(obj_aux, "O%ld,", obj_id);
        strcat(obj, obj_aux);     
      }
      if(obj_ids[i] != NO_ID)
      {
        strcat(obj, "...");
        while(strlen(obj) < MAX_MAP_STRING){
          strcat(obj, " ");
        }
      }
      else{
        obj[strlen(obj)-1] = 0;
        while(strlen(obj) < MAX_MAP_STRING){
          strcat(obj, " ");
        }
      }
    } 
    /*-----------------------------------------------------------*/ 

    if (id_next != NO_ID)
    {
      if(game_get_enemy_location(game) == id_next && enemy_get_health(game->enemy) > 0)
      {
        sprintf(enemy, "/\\oo/\\");  
      }
      else
      {
        sprintf(enemy, "      ");
      }

      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |       %s %3d|", enemy,(int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |%s|", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  
  /*prints the location for each object in the game*/
  sprintf(str, "Object location:");
  screen_area_puts(ge->descript, str);
  str[0]=0;
  obj_id = (Id) 00;
  for(i=0; i < MAX_OBJECTS && (obj_id != NO_ID); i++){
    obj_id = object_get_id(game->objects[i]);
    if((obj_loc = game_get_object_location(game, obj_id)) != NO_ID)
    {
      
      sprintf(obj_aux_aux, "O%ld: %ld, ", obj_id, obj_loc);
      strcat(str, obj_aux_aux);
    }

  }
  str[(strlen(str)-1)] = 0;
  screen_area_puts(ge->descript, str);

  /*prints the location, object and health of the player*/

  sprintf(str, "Player location: %ld", id_act);
  screen_area_puts(ge->descript, str);

  if(player_get_object_id(game->player) != NO_ID)
  {
    sprintf(str, "Player object: O%ld", player_get_object_id(game->player));
  }
  else
  {
    sprintf(str, "Player object: No object");
  }
  
  screen_area_puts(ge->descript, str);
  sprintf(str, "Player health: %d", player_get_health(game->player));
  screen_area_puts(ge->descript, str);

  /*prints the location and health of the enemy*/
  sprintf(str, "Enemy location: %ld", enemy_get_location(game->enemy));
  screen_area_puts(ge->descript, str);
  sprintf(str, "Enemy health: %ld", enemy_get_health(game->enemy));
  screen_area_puts(ge->descript, str);
  

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The game of the ant ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, left or l, right or r, take or t, drop or d, attack or a, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_input= game_get_last_command(game);
 
  if(command_get_cmd(last_input) == NO_CMD || command_get_cmd(last_input) == UNKNOWN)
  {
    sprintf(com_er, "ERROR");
  }
  else
  {
    sprintf(com_er, "OK");
  }

  sprintf(str, " %s (%s): %s", cmd_to_str[command_get_cmd(last_input) - NO_CMD][CMDL], cmd_to_str[command_get_cmd(last_input) - NO_CMD][CMDS], com_er);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
