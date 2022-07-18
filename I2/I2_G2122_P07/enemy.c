/** 
 * @brief The Enemy module
 * 
 * @file enemy.c
 * @author Luis Fernandez
 * @version 1.0 
 * @date 23-02-2022
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "enemy.h"


/**
 * @brief Enemy
 * This struct stores all the information of the Enemy.
 */
struct _Enemy
{
    
    Id id;                      /*!< id of enemy */
    char name[WORD_SIZE + 1];   /*!< name of enemy*/
    Id location;                /*!< location of enemy*/
    long int health;            /*!< health of the enemy*/
};

/**  enemy_create allocates memory for a new Enemy
  *  and initializes its members
  */
Enemy* enemy_create(Id id) {

    Enemy *newEnemy=NULL;

    /*Error control*/
    if(id== NO_ID)
    {
        return NULL;
    }
    
    newEnemy = (Enemy*) malloc(sizeof(Enemy));

    if( !newEnemy )
    {
        return NULL;
    }

    /*Initialization of the members*/
    newEnemy->id = id;
    newEnemy->name[0] = '\0';
    newEnemy->location = NO_ID;
    newEnemy->health = ENEMY_HP;
    
    return newEnemy;
}

/** enemy_destroy frees the previous memory allocation 
  *  for the Enemy
  */
STATUS enemy_destroy(Enemy* enem) {

    if( !enem )
    {
        return ERROR;
    }

    free(enem);
    

    return OK;
}


/** It gets the id of the Enemy
  */
Id enemy_get_id(Enemy* enem) {

    if( !enem )
    {
        return NO_ID;
    }

    return enem->id;
}

/** It gets the name of the Enemy
  */
const char * enemy_get_name(Enemy* enem) {

    if( !enem )
    {
        return NULL;
    }

    return enem->name;
}

/** It gets the id of the location of Enemy
  */
Id enemy_get_location(Enemy* enem) {

    if( !enem )
    {
        return NO_ID;
    }

    return enem->location;
}

/* It gets the health value of Enemy */
long int enemy_get_health(Enemy* enem){

    if(!enem)
    {
        return -1;
    }

    return enem->health;
}


/* It sets the id of the Enemy */
STATUS enemy_set_id(Enemy* enem, Id id) {

    if( !enem || id == NO_ID)
    {
        return ERROR;
    }

    enem->id = id;

    return OK;
}

/* It sets the name of the Enemy */
STATUS enemy_set_name(Enemy* enem, char *name) {

    if( !enem || !name)
    {
        return ERROR;
    }

    if(!strcpy(enem->name, name))
    {
        return ERROR;
    };

    return OK;
}

/* It sets the id of the location of Enemy */
STATUS enemy_set_location(Enemy* enem, Id id) {

    if( !enem || id == NO_ID)
    {
        return ERROR;
    }

    enem->location = id;

    return OK;
}

/* It sets the health value of enemy */
STATUS enemy_set_health(Enemy* enem, long int hp) {
    
    if( !enem )
    {
        return ERROR;        
    }

    enem->health = hp;

    return OK;
}

/* It prints the Enemy information */ 
STATUS enemy_print(Enemy* enem) {

    /* Error control */
    if( !enem )
    {
        return ERROR;
    }
/* Prints de name and the id of the Enemy */
    
    fprintf(stdout,"--> Enemy (Id: %ld; Name: %s; Location id: %ld;)\n", enem->id, enem->name, enem->location);

   return OK;

}



