/**
 * @brief It defines the dialogue interface
 *
 * @file dialogue.h
 * @author luis
 * @version 1.0
 * @date 21-04-2022
 */


#ifndef DIALOGUE_H
#define DIALOGUE_H

#define MAX_CMD_RES 5
#define CMD_STATUS 2
#define MAX_LENGHT 127

#include "command.h"

typedef struct _Dialogue Dialogue;

/**
 * @brief creates new dialogue
 * @author Luis
 * 
 * @return dialogue structure or NULL if there was an error
*/
Dialogue *dialogue_create();


/**
 * @brief frees dialogue structure 
 * @author Luis
 * 
 * @param d dialogue structure to destroy
 * @return dialogue structure or NULL if there was an error
*/
void dialogue_destroy(Dialogue *d);



STATUS dialogue_set_frase(Dialogue *d, char* frase, T_Command t_cmd, STATUS cmd_st);

/**
 * @brief frees dialogue structure 
 * @author Luis
 * 
 * @param d dialogue structure to destroy
 * @return dialogue structure or NULL if there was an error
*/
char *dialogue_get_frase(Dialogue *d, T_Command t_cmd, STATUS cmd_st, int res);

#endif