/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author Joaquín Abad Díaz
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "command.h"
#include "types.h"

#define CMD_LENGHT 30

/**
 * @brief Command
 *
 * This struct stores all the information of a Command.
 */
struct _Command{
    T_Command cmd;      /*!< Command reference*/
    Id object;          /*!< Id of the object*/
};

/** command_create allocates memory for a new Command
  *  and initializes its members
  */
Command* command_create() {
  Command *newCmd=NULL;
  
  newCmd = (Command*) malloc(sizeof(Command));

  if(newCmd==NULL)
  {
    return NULL;
  }

  /*Initialization of the members*/
  newCmd->cmd = UNKNOWN;
  newCmd->object = NO_ID;
  
  return newCmd;
}

/** command_destroy frees the previous memory allocation 
  *  for a command
  */
STATUS command_destroy(Command* cmd) {
    
  if(cmd == NULL)
  {
    return ERROR;
  }

  free(cmd);

  return OK;
}

/** It gets the cmd of the Command
  */
T_Command command_get_cmd(Command* cmd) {
    
    if(cmd == NULL)
    {
        return NO_CMD;
    }

    return cmd->cmd;
}

/** It gets the id of the given Command
  */
Id command_get_id(Command* cmd) {
    
    if(cmd == NULL)
    {
        return NO_ID;
    }

    return cmd->object;
}

/** It set the cmd of a Command
  */
STATUS command_set_cmd(Command* cmd_o, T_Command cmd_d) {

    if( !cmd_o|| cmd_d == NO_CMD)
    {
        return ERROR;
    }

    cmd_o->cmd = cmd_d;

    return OK;
}

/** It set the id associated to Command
  */
STATUS command_set_id(Command* cmd_o, Id object) {

    if( !cmd_o)
    {
        return ERROR;
    }

    cmd_o->object = object;

    return OK;
}



/**
  * it interpretates a word or a letter given by the user 
  * to be used in cmd 
  */
char *cmd_to_str[N_CMD]
[N_CMDT] = {{"", "No command"},
      {"", "Unknown"},
      {"e", "Exit"},
      {"n", "Next"},
      {"b", "Back"},
      {"l", "Left"},
      {"r", "Rigth"},
      {"t", "Take"},
      {"d", "Drop"},
      {"a", "Attack"}};

/** 
  * It initializes a char to interpretate the user input and
  * a corresponding int to modify the cmd output to the     Take O14
  * one given by the user, returning UNKNOWN if invalid 
  */
Command * command_get_user_input() {
  char input[CMD_LENGHT] = "";
  char acction[CMD_LENGHT] = "";
  char object[CMD_LENGHT] = "";
  char *toks;
  int i = UNKNOWN - NO_CMD + 1;
  Command * cmd;
  cmd = command_create();
  
  if (!cmd)
  {
    return NULL;
  }
  

  fgets(input, CMD_LENGHT, stdin);
  toks = strtok(input," \n");
  strcpy(acction, toks);
  toks = strtok(NULL, " \n");

  if (toks)
  {
    strcpy(object,toks + 1);
  }

  if (acction != NULL)
  {
    
    command_set_cmd(cmd, UNKNOWN);
    while (command_get_cmd(cmd) == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(acction, cmd_to_str[i][CMDS]) || !strcasecmp(acction, cmd_to_str[i][CMDL]))
      {
        if (command_set_cmd(cmd, i + NO_CMD) == ERROR)
        {
          return NULL;
        }
      }
      else
      {
        i++;
      }
    }
  }

  if (command_set_id(cmd, atol(object)) == ERROR)
  {
    cmd->object = NO_ID;
    return NULL;
  }
    
  return cmd;
}
