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
#include <string.h>
#include <strings.h>
#include "../include/command.h"
#include "../include/types.h"

#define CMD_LENGHT 40
#define MAX_LEN 300

char logfile[MAX_LEN];

/**
  * it interpretates a word or a letter given by the user 
  * to be used in cmd 
  */
char *cmd_to_str[N_CMD][N_CMDT] = 
      {{"", "No command"},
      {"", "Unknown"},
      {"e", "Exit"},
      {"m", "Move"},
      {"t", "Take"},
      {"d", "Drop"},
      {"a", "Attack"},
      {"i","Inspect"}};

/**
 * @brief Command
 *
 * This struct stores all the information of a Command.
 */
struct _Command{
    T_Command cmd;          /*!< Command reference*/
    char input[CMD_LENGHT]; /*!< Argument of the input*/
    STATUS status;
    char lastdescription[MAX_LEN];
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
  strcpy(newCmd->input,"");
  strcpy(newCmd->lastdescription,"No_description");
  newCmd->status = OK;
  
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
char *command_get_input(Command* cmd) {
    
    if(cmd == NULL)
    {
        return NULL;
    }

    return cmd->input;

}

/** It returns the status of Command
  */
STATUS command_get_status(Command* cmd) {
    
    if(cmd == NULL)
    {
        return NO_ID;
    }

    return cmd->status;
}

/** It returns the description of Command
  */
char *command_get_description(Command* cmd) {
    
    if(cmd == NULL)
    {
        return NULL;
    }

    return cmd->lastdescription;
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
STATUS command_set_input(Command* cmd_o, char *input) {

    if(!cmd_o || !input)
    {
        return ERROR;
    }

    strcpy(cmd_o->input,input);

    return OK;
}

/** It sets a new status for Command
  */
STATUS command_set_status(Command* cmd_o, STATUS status) {

    if(!cmd_o)
    {
        return ERROR;
    }

    cmd_o->status = status;

    return OK;
}


STATUS command_set_description(Command *cmd_o, char* desc) {
  if (!cmd_o || !desc) {
    return ERROR;
  }

  strcpy(cmd_o->lastdescription, desc);

  return OK;
}
/*holi joakin muxo animo*/

/** 
  * It initializes a char to interpretate the user input and
  * a corresponding int to modify the cmd output to the 
  * one given by the user, and taking a second argument for 
  * Take, Drop, Move and Inspect implementations
  */
Command * command_get_user_input() {
  char input[CMD_LENGHT] = "";
  char acction[CMD_LENGHT] = "";
  char object[CMD_LENGHT] = "";
  char *toks;
  int i = UNKNOWN - NO_CMD + 1;
  Command * cmd;
  FILE *fp = NULL;

  cmd = command_create();
  
  if (!cmd)
  {
    return NULL;
  }
  

  fgets(input, CMD_LENGHT, stdin);

  if (logfile[0] != '\0'){
    fp = fopen(logfile, "a");
    
    if (fp == NULL) {
      return NULL;
    }
    
    fprintf(fp, "%s", input);
    
    fclose(fp);
  }


  toks = strtok(input," \n");
  strcpy(acction, toks);
  toks = strtok(NULL, " \n");

  if (toks)
  {
    strcpy(object, toks);
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

  command_set_input(cmd, object);

  return cmd;
}

STATUS command_set_logfile(char *logfilename) {
  FILE *fp = NULL;
  
  if (logfilename == NULL) {
    logfile[0] = '\0';
    return OK;
  }

  strcpy(logfile, logfilename);

  fp = fopen(logfile, "w");

  if (fp == NULL) {
    return ERROR;
  }

  fclose(fp);

  return OK;
}