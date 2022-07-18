/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Javii, Óskar, Álexx
 * @version 4.3
 * @date 17-03-2022
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/player.h"

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
struct _Player
{
    Id id;             /*!< Id number of the player, it must be unique */
    char *name;        /*!< Name of the player */
    Id location;       /*!< Location of the player */
    Inventory *rinyo;  /*!< The inventory (riñonera) with objects */
    int health;        /*!< The health of the player*/
};

/** player_create allocates memory for a new player and initializes
 *  its members with non null values
 */
Player *player_create(Id id, char *name, Id location, Inventory *rinyo, int health)
{
    Player *p = NULL;

    if (name == NULL || id == NO_ID)
    {
        return NULL;
    }

    p = (Player *)malloc(sizeof(Player));

    if (p == NULL)
    {
        return NULL;
    }

    p->name = NULL;

    if (player_set_id(p, id) == ERROR)
    {
        free(p);
        return NULL;
    }

    if (player_set_location(p, location) == ERROR)
    {
        free(p);
        return NULL;
    }

    if (player_set_inventory(p, rinyo) == ERROR)
    {
        free(p);
        return NULL;
    }

    if (player_set_name(p, name) == ERROR)
    {
        free(p);
        return NULL;
    }

    if (player_set_health(p, health) == ERROR)
    {
        free(p);
        return NULL;
    }

    return p;
}

/** player_destroy frees the previous memory allocation
 *  for a player
 */
STATUS player_destroy(Player *player)
{
    if (player == NULL)
    {
        return ERROR;
    }

    free(player->name);
    inventory_destroy(player->rinyo);
    free(player);
    player = NULL;

    return OK;
}

/** It sets the id of a player
 */
STATUS player_set_id(Player *player, Id id)
{
    if (player == NULL || id == NO_ID)
    {
        return ERROR;
    }

    player->id = id;

    return OK;
}

/** It sets the name of a player
 */
STATUS player_set_name(Player *player, char *name)
{
    char *newname = NULL;

    if (player == NULL || name == NULL)
    {
        return ERROR;
    }

    newname = (char *)realloc(player->name, strlen(name) + 1);

    if (newname != NULL)
    {
        player->name = newname;
    }
    else
    {
        return ERROR;
    }

    strcpy(player->name, name);
    return OK;
}

/** It sets the location of a player
 */
STATUS player_set_location(Player *player, Id location)
{
    if (player == NULL)
    {
        return ERROR;
    }

    player->location = location;
    return OK;
}

/** It sets the inventory of a player
 */
STATUS player_set_inventory(Player *player, Inventory *rinyo)
{
    if (player == NULL || rinyo == NULL)
    {
        return ERROR;
    }

    player->rinyo = rinyo;
    return OK;
}

/** Adds an object to La riño
 */
STATUS player_add_object_inventory(Player *player, Id object)
{
    if (player == NULL || object == NO_ID || inventory_is_full(player->rinyo) == TRUE)
    {
        return ERROR;
    }
    
    if (inventory_add_object(player->rinyo, object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/** Removes an object from La riño
 */
STATUS player_del_object_inventory(Player *player, Id object)
{
    if (player == NULL || object == NO_ID)
    {
        return ERROR;
    }
    
    if (inventory_remove_object(player->rinyo, object) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

/** It gets the objects set of La riño
 */
Set *player_get_objects_inventory(Player *player)
{
    if (!player)
    {
        return NULL;
    }

    return (inventory_get_objects(player->rinyo));
}

/** This function check if the id(input) is in La riño
 */
BOOL player_id_in_inventory(Player *player, Id object)
{   
    if (player == NULL || object == NO_ID)
    {
        return FALSE;
    }
    
    return inventory_find_object(player->rinyo, object);
}

/** It gets if the player's inventory is full
 */
BOOL player_inventory_is_full(Player *player)
{   
    if (!player)
    {
        return FALSE;
    }
    
    return inventory_is_full(player->rinyo);
}

/** It sets the health of a player
 */
STATUS player_set_health(Player *player, int health)
{
    if (player == NULL)
    {
        return ERROR;
    }

    player->health = health;
    return OK;
}

/** It gets the id of a player
 */
Id player_get_id(Player *player)
{
    if (player == NULL)
    {
        return NO_ID;
    }

    return player->id;
}

/** It gets the name of a player
 */
char *player_get_name(Player *player)
{
    char *name = NULL;

    if (player == NULL)
    {
        return NULL;
    }

    name = (char *)calloc(strlen(player->name) + 1, sizeof(char));

    if (name == NULL)
    {
        return NULL;
    }

    strcpy(name, player->name);
    return name;
}

/** It gets the location of a player
 */
Id player_get_location(Player *player)
{
    if (player == NULL)
    {
        return NO_ID;
    }

    return player->location;
}

/** It gets the inventory of a player
 */
Inventory *player_get_inventory(Player *player)
{
    if (player == NULL)
    {
        return NULL;
    }

    return player->rinyo;
}

/** It gets the health of a player
 */
int player_get_health(Player *player)
{
    if (player == NULL)
    {
        return -1;
    }

    return player->health;
}

/** It prints the player information
 */
STATUS player_print(Player *player)
{
    if (player == NULL)
    {
        return ERROR;
    }

    fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Health: %d)\n", player->id, player->name, player->location, player->health);
    inventory_print(player->rinyo);
    return OK;
}
