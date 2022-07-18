/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
#include "string.h"

typedef struct _Command Command;

#define N_CMDT 2
#define N_CMD 8

/**
 * it enumerates the two posible types of inputs, the sort one and the long one
 */
typedef enum enum_CmdType {
  CMDS,
  CMDL} T_CmdType;
/**
 * it enumerates the posible interpretations of the user input after the
 * inicial state, NO_CMD
 */
typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  MOVE,
  TAKE,
  DROP,
  ATTACK,
  INSPECT} T_Command;

  
/**
  * @brief It gets the input given by the user
  * @author Joaquin Abad
  *
  * It initializes a char to interpretate the user input and
  * a corresponding int to modify the cmd output to the
  * one given by the user 
  * 
  * @return a cmd command
  */
Command *command_get_user_input();

/**
  * @brief Initialization of a new Command
  * @author Joaquin Abad
  *
  * command_create allocates memory for a new Command
  *  and initializes its members
  * 
  * @return cmd command
  */
Command *command_create();

/**
  * @brief It destroys a Command
  * @author Joaquin Abad
  *
  * command_destroy destroys a command
  * freeing the allocated memory for it
  * 
  * @param cmd a pointer to Command
  * @return OK if the pointer is valid, if not returns ERROR
  */
STATUS command_destroy(Command* cmd);

/**
  * @brief Returns the cmd of a Command
  * @author Joaquin Abad
  *
  * 
  * @param cmd a pointer to Command
  * @return cmd Command
  */
T_Command command_get_cmd(Command* cmd);

/**
  * @brief It returns the input of Command
  * @author Joaquin Abad
  * 
  * It returns the input char of Command for Take, Drop and Move implementations
  *
  * @param cmd a pointer to Game
  * @return input char from Command
  */
char *command_get_input(Command* cmd);

/**
  * @brief It returns the status of Command
  * @author Joaquin Abad
  * 
  *
  * @param cmd a pointer to Game
  * @return OK if the command is valid or ERROR in any other case
  */
STATUS command_get_status(Command* cmd);

/**
  * @brief It returns the description of Command
  * @author Javi
  * 
  * It returns the description char of Command for Inspect implementations
  *
  * @param cmd a pointer to Game
  * @return description char from Command
  */
char *command_get_description(Command* cmd);

/**
  * @brief It sets a new cmd for Command
  * @author Joaquin Abad
  *
  * 
  * @param cmd_o a pointer to Command
  * @param cmd_d the new cmd
  * @return OK if the pointer and the cmd both valid, if not returns ERROR
  */
STATUS command_set_cmd(Command* cmd_o, T_Command cmd_d);

/**
  * @brief It sets a new input for Command
  * @author Joaquin Abad
  *
  * 
  * @param cmd_o a pointer to Command
  * @param input the new Input
  * @return OK if the pointer is valid, if not returns ERROR
  */
STATUS command_set_input(Command* cmd_o, char *input);

/**
  * @brief It sets a new status for Command
  * @author Joaquin Abad
  *
  * 
  * @param cmd_o a pointer to Command
  * @param status to set
  * @return STATUS OK on sucess ERROR on failure
  */
STATUS command_set_status(Command* cmd_o, STATUS status);

STATUS command_set_description(Command *cmd_o, char* desc);

/**
 * @brief Sets logfilename if no logfile is required, logfilename should
 * be NULL. logfile[0] will be '\0' if this happens.
 * 
 * @author Javi
 * 
 * @param logfilename file name or NULL if no file is required
 * @return STATUS OK on sucess ERROR on failure
 */
STATUS command_set_logfile(char *logfilename);

#endif
