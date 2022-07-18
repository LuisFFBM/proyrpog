/**
 * @brief It implements the dialogue module
 *
 * @file dialogue.c
 * @author alex & luis
 * @version 1.0
 * @date 21-04-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/dialogue.h"



/***esto es lo que he hecho yo, luis; si quieres cambiar lo que sea hazlo, aunque si cambias lo del T_command avisa***/

/**
 * @brief Dialogue
 *
 * This struct stores all the information of the dialogue.
 */
struct _Dialogue
{
    int n_res_ok;                                               /*!< number of phrases for status OK and each cmd*/
    int n_res_err;                                              /*!< number of phrases for status ERROR and each cmd*/
    char frase[N_CMD][CMD_STATUS][MAX_CMD_RES][MAX_LENGHT];     /*!< phrases array with each answer for each command and status*/

};
/*public functions*/

/**
 * creates new dialogue
*/
Dialogue *dialogue_create() {

    Dialogue* d = NULL;

    d = (Dialogue*) malloc(sizeof(Dialogue));
    if(d == NULL) return NULL;

    
    d->n_res_err = 0;
    d->n_res_ok = 0;

    return d;
}

/** 
 * frees a dialogue structure
*/
void dialogue_destroy(Dialogue *d) {
    if(d == NULL){
        return;
    }


    free(d);
}

/**
 * set phrase in the array in the dialogue structure
*/
STATUS dialogue_set_frase(Dialogue *d, char* frase, T_Command t_cmd, STATUS cmd_st) {
    int n_res = 0;
    

    if(d == NULL || frase == NULL || t_cmd == NO_CMD || (cmd_st != OK && cmd_st != ERROR)){
        return ERROR;
    }

    if(cmd_st == OK)
    {
        n_res = d->n_res_ok;
        if(n_res >= MAX_CMD_RES){
            return ERROR;
        }

        d->n_res_ok++;

    }
    else
    {
        n_res = d->n_res_err;
        if(n_res >= MAX_CMD_RES){
            return ERROR;
        }

        d->n_res_err++;
    }
    n_res++;
    
    if(NULL != strcpy(d->frase[t_cmd][cmd_st][n_res], frase)){
        return ERROR;
    }

    
    return OK;
}

/**
 * gets a phrase from the dialogue structure
*/
char *dialogue_get_frase(Dialogue*d, T_Command t_cmd, STATUS cmd_st, int res) {

    
    if(d == NULL || t_cmd == NO_CMD || res >= MAX_CMD_RES || res<0){
        return NULL;
    }
    
    return d->frase[t_cmd][cmd_st][res];
}



