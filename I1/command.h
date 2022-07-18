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

#define N_CMDT 2
#define N_CMD 7
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
  NEXT,
  BACK,
  TAKE,
  DROP} T_Command;
/**
  * @brief It gets the input given by the user
  * @author Profesores PPROG
  *
  * It initializes a char to interpretate the user input and
  * a corresponding int to modify the cmd output to the
  * one given by the user 
  * 
  * @return a cmd command
  */
T_Command command_get_user_input();

#endif
