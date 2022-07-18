/** 
 * @brief It declares the tests for the enemy module
 * 
 * @file enemy_test.h
 * @author Luis Fernandez
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef ENEMY_TEST_H
#define ENEMY_TEST_H

#include "enemy.h"
#include "test.h"

/**
 * @test Test Enemy creation
 * @pre Enemy ID 
 * @post Non NULL pointer to Enemy 
 */
void test1_enemy_create();

/**
 * @test Test Enemy creation
 * @pre Enemy ID 
 * @post Enemy_ID == Supplied Enemy Id 
 */
void test2_enemy_create();

/**
 * @test Test functiion for geting enemy Id 
 * @pre pointer to Enemy 
 * @post 
 */
void test1_enemy_get_id();
void test2_enemy_get_id();
void test1_enemy_get_name();
void test2_enemy_get_name();
void test1_enemy_set_name();
void test2_enemy_set_name();
void test3_enemy_set_name();
void test1_enemy_get_location();
void test2_enemy_get_location();
void test1_enemy_set_location();
void test2_enemy_set_location();
void test1_enemy_get_health();
void test2_enemy_get_health();
void test1_enemy_set_health();
void test2_enemy_set_health();
#endif