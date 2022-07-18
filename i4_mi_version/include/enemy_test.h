/**
 * @brief It declares the tests for the enemy module
 *
 * @file enemy_test.h
 * @author Javii, Álexx
 * @version 3.0
 * @date 10-03-2022
 */

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

/**
 * @test Test enemy creation
 * @pre new enemy info (id, name, location, object)
 * @post Non NULL pointer to enemy
 */
void test1_enemy_create();

/**
 * @test Test enemy creation and all getters
 * @pre new enemy info (id, name, location, object)
 * @post Non NULL pointer to enemy, and all enemy info provided
 */
void test2_enemy_create();

/**
 * @test Test function for enemy_id setting and getting
 * @pre pointer to enemy initialized and new enemy ID
 * @post enemy_get_id = last ID set
 */
void test1_enemy_set_id();

/**
 * @test Test function for enemy_id setting
 * @pre pointer to enemy = NULL; enemy ID
 * @post Output==ERROR
 */
void test2_enemy_set_id();

/**
 * @test Test function for enemy_name setting and getting
 * @pre pointer to enemy initialized and new enemy name
 * @post enemy_get_name = last name set
 */
void test1_enemy_set_name();

/**
 * @test Test function for enemy_name setting
 * @pre pointer to enemy = NULL; enemy name
 * @post Output==ERROR
 */
void test2_enemy_set_name();

/**
 * @test Test function for enemy_location setting and getting
 * @pre pointer to enemy initialized and new enemy location
 * @post enemy_get_location = last location set
 */
void test1_enemy_set_location();

/**
 * @test Test function for enemy_location setting
 * @pre pointer to enemy = NULL; enemy location
 * @post Output==ERROR
 */
void test2_enemy_set_location();

/**
 * @test Test function for enemy_health setting and getting
 * @pre pointer to enemy initialized and new enemy health
 * @post enemy_get_health = last health set
 */
void test1_enemy_set_health();

/**
 * @test Test function for enemy_health setting
 * @pre pointer to enemy = NULL; enemy health
 * @post Output==ERROR
 */
void test2_enemy_set_health();

#endif