/**
 * @brief It declares the tests for the player module
 *
 * @file player_test.h
 * @author Alexx
 * @version 2.0
 * @date 05-04-2022
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Test player creation
 * @pre Player information
 * @post Non NULL pointer to player
 */
void test1_player_create();

/**
 * @test Test player creation
 * @pre Player information (NULL inventory)
 * @post NULL pointer to player
 */
void test2_player_create();

/**
 * @test Test player creation and getters
 * @pre Player information
 * @post Correct information checking getters after player creation
 */
void test3_player_create();

/**
 * @test Test player id setter and getter
 * @pre Player initialized and a new id to set
 * @post player_get_id == new id setted
 */
void test1_player_set_id();

/**
 * @test Test player id setter
 * @pre NULL player a new id to set
 * @post player_set_id == ERROR
 */
void test2_player_set_id();

/**
 * @test Test player name setter and getter
 * @pre Player initialized and a new name to set
 * @post player_get_name == new name setted
 */
void test1_player_set_name();

/**
 * @test Test player name setter
 * @pre NULL player a new name to set
 * @post player_set_name == ERROR
 */
void test2_player_set_name();

/**
 * @test Test player location setter and getter
 * @pre Player initialized and a new location to set
 * @post player_get_location == new location setted
 */
void test1_player_set_location();

/**
 * @test Test player location setter
 * @pre NULL player a new location to set
 * @post player_set_location == ERROR
 */
void test2_player_set_location();

/**
 * @test Test player inventory setter
 * @pre Player initialized and a new inventory (initialized) to set
 * @post player_set_inventory == OK
 */
void test1_player_set_inventory();

/**
 * @test Test player inventory setter
 * @pre Player initialized and a new inventory (NULL) to set
 * @post player_set_inventory == ERROR
 */
void test2_player_set_inventory();

/**
 * @test Test player add object inventory
 * @pre Player initialized and an id to add
 * @post player_add_object_inventory == OK
 */
void test1_player_add_object_inventory();

/**
 * @test Test player add object inventory
 * @pre NULL player and an id to add
 * @post player_add_object_inventory == ERROR
 */
void test2_player_add_object_inventory();

/**
 * @test Test player del object inventory
 * @pre Player initialized with an object in La riño
 *       and the correct id to remove from La riño
 * @post player_del_object_inventory == OK
 */
void test1_player_del_object_inventory();

/**
 * @test Test player del object inventory
 * @pre Player initialized with an object in La riño
 *       and an incorrect id to remove from La riño
 * @post player_del_object_inventory == ERROR
 */
void test2_player_del_object_inventory();

/**
 * @test Test player get objects inventory
 * @pre Player initialized with an object in La riño
 * @post Non NULL objects set
 */
void test1_player_get_objects_inventory();

/**
 * @test Test player get objects inventory
 * @pre NULL player
 * @post Output == NULL
 */
void test2_player_get_objects_inventory();

/**
 * @test Test player id in inventory
 * @pre Player initialized with an object in La riño,
 *       and its id
 * @post player_id_in_inventory == TRUE
 */
void test1_player_id_in_inventory();

/**
 * @test Test player id in inventory
 * @pre Player initialized with an object in La riño,
 *       and "NO_ID"
 * @post player_id_in_inventory == FALSE
 */
void test2_player_id_in_inventory();

/**
 * @test Test player id in inventory
 * @pre NULL player and a random id
 * @post player_id_in_inventory == FALSE
 */
void test3_player_id_in_inventory();

/**
 * @test Test player inventory is full
 * @pre Player with a full inventory
 * @post player_inventory_is_full == TRUE
 */
void test1_player_inventory_is_full();

/**
 * @test Test player inventory is full
 * @pre Player with a non full inventory
 * @post player_inventory_is_full == FALSE
 */
void test2_player_inventory_is_full();

/**
 * @test Test player inventory is full
 * @pre NULL player
 * @post player_inventory_is_full == FALSE
 */
void test3_player_inventory_is_full();

/**
 * @test Test player health setter and getter
 * @pre Player initialized and a new health value to set
 * @post player_set_health == OK && player_get_health == health setted
 */
void test1_player_set_health();

/**
 * @test Test player health setter
 * @pre NULL player a new health value to set
 * @post player_set_health == ERROR
 */
void test2_player_set_health();

/**
 * @test Test player id getter
 * @pre NULL player
 * @post Output==NO_ID
 */
void test1_player_get_id();

/**
 * @test Test player name getter
 * @pre NULL player
 * @post Output==NULL
 */
void test1_player_get_name();

/**
 * @test Test player location getter
 * @pre NULL player
 * @post Output==NO_ID
 */
void test1_player_get_location();

/**
 * @test Test player inventory getter
 * @pre NULL player
 * @post Output==NULL
 */
void test1_player_get_inventory();

/**
 * @test Test player health getter
 * @pre NULL player
 * @post Output==-1
 */
void test1_player_get_health();


#endif