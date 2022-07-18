/**
 * @brief It implements the enemy module
 *
 * @file enemy.c
 * @author Oscar
 * @version 1.0
 * @date 10-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/enemy.h"

/**
 * @brief Enemy
 *
 * This struct stores all the information of an enemy.
 */
struct _Enemy
{
    Id id;       /*!< Id number of the enemy, it must be unique */
    char *name;  /*!< Name of the enemy */
    Id location; /*!< Location of the enemy */
    int health;  /*!< Health of the enemy*/
};

/**
 * enemy_create allocates memory for a new enemy and initializes
 *  its members with non null values (except of the object that can be null)
 */

Enemy *enemy_create(Id id, char *name, Id location, int health)
{
    Enemy *maligno = NULL;

    if (name == NULL || id == NO_ID)
    {
        return NULL;
    }

    maligno = (Enemy *)malloc(sizeof(Enemy));

    if (maligno == NULL)
    {
        return NULL;
    }

    if (enemy_set_id(maligno, id) == ERROR)
    {
        free(maligno);
        return NULL;
    }

    if (enemy_set_location(maligno, location) == ERROR)
    {
        free(maligno);
        return NULL;
    }

    maligno->name = NULL;
    if (enemy_set_name(maligno, name) == ERROR)
    {
        free(maligno);
        return NULL;
    }
    if (enemy_set_health(maligno, health) == ERROR)
    {
        free(maligno);
        return NULL;
    }

    return maligno;
}

/**
 * enemy_destroy frees the previous memory allocation
 *  for an enemy
 */
STATUS enemy_destroy(Enemy *enemy)
{
    if (enemy == NULL)
    {
        return ERROR;
    }

    free(enemy->name);
    free(enemy);
    enemy = NULL;

    return OK;
}

/*It sets the id of an enemy*/

STATUS enemy_set_id(Enemy *enemy, Id id)
{
    if (enemy == NULL || id == NO_ID)
    {
        return ERROR;
    }

    enemy->id = id;

    return OK;
}

/**
* enemy_set_name allocates memory for the name of
*  the new enemy
-*/

STATUS enemy_set_name(Enemy *enemy, char *name)
{
    char *newname = NULL;

    if (enemy == NULL || name == NULL)
    {
        return ERROR;
    }

    newname = (char *)realloc(enemy->name, strlen(name) + 1);

    if (newname != NULL)
    {
        enemy->name = newname;
    }
    else
    {
        return ERROR;
    }

    strcpy(enemy->name, name);
    return OK;
}

/**
 * It sets the location of an enemy
 */

STATUS enemy_set_location(Enemy *enemy, Id location)
{
    if (enemy == NULL)
    {
        return ERROR;
    }

    enemy->location = location;
    return OK;
}

/**
 * It sets the health of an enemy
 **/

STATUS enemy_set_health(Enemy *enemy, int health)
{
    if (enemy == NULL)
    {
        return ERROR;
    }

    enemy->health = health;
    return OK;
}

/**
 * It gets the id of an enemy
 **/

Id enemy_get_id(Enemy *enemy)
{
    if (enemy == NULL)
    {
        return NO_ID;
    }

    return enemy->id;
}

/**
 * It gets the name of an enemy
 */

char *enemy_get_name(Enemy *enemy)
{
    char *name = NULL;

    if (enemy == NULL)
    {
        return NULL;
    }

    name = (char *)calloc(strlen(enemy->name) + 1, sizeof(char));

    if (name == NULL)
    {
        return NULL;
    }

    strcpy(name, enemy->name);
    return name;
}

/**
 * It gets the location of an enemy
 */
Id enemy_get_location(Enemy *enemy)
{
    if (enemy == NULL)
    {
        return NO_ID;
    }

    return enemy->location;
}

/**
 * It gets the health of an enemy
 */

int enemy_get_health(Enemy *enemy)
{
    if (enemy == NULL)
    {
        return NO_ID;
    }

    return enemy->health;
}
/**
 * It prints the enemy information
 */

STATUS enemy_print(Enemy *enemy)
{
    if (enemy == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Enemy (Id: %ld; Name: %s; Location: %ld; Helath: %d)\n", enemy->id, enemy->name, enemy->location, enemy->health);
    return OK;
}
