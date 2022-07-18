/**
 * @brief Tests for game module
 *
 * @file game_test.h
 * @author Luis, Oskar, Joaquin, Javi
 * @date 06-05-2022
 */

#ifndef GAME_TEST_H
#define GAME_TEST_H

/**
 * Manual tests
 * 
 * void slot_destroy(Slot * slot);
 * Testesd by running valgrind 
 * 
 * STATUS game_load_from_file(Game **game, char *filename);
 * Create a level file and run the game with it and look if it does generate correctly
 * 
 * Commands (with all of these you have to watch out for the right behavior)
 * - move: try to execute legal and illegal movements and watch
 * out for your games behaviour.
 * 
 * - take: You try to pick up an item inside and outside the room also you try to pick
 *  with something up with full inventory
 * 
 * - drop: You try to drop an item that is not in your inventory and to drop an item inside 
 * your inventory
 * 
 * - attack: walk up to an enemy and fight it. Repeat in a room without an enemy
 * 
 * - save/load: save your games state, change it and fetch it later
 * 
 * - on/off: take a luminescent object and one that isn't and try to turn it on and off
 * 
 * - inspect: look if the description you are asking for shows up correctly 
 * 
 * - exit: run your game with valgrind and check if it finishes correctly
 */

/**
 * Funciones que quedan por probar
 * 
 * slot_create();
 * int slot_get_n_slots(Slot *slot);
 * STATUS slot_set_n_slots(Slot *slot, int n);
 * char **slot_get_slot(Slot *slot);
 * STATUS slot_set_slot(Slot *slot, char **new_slot);
 * 
 * 
 * STATUS game_add_object(Game *game, Object *object, Id location, char *name);
 * STATUS game_add_link(Game *game, Link *link);
 * STATUS game_add_slots(Game *game, Slot *slots);
 * 
 * STATUS game_update(Game *game, Command *cmd);
 * STATUS game_destroy(Game *game);
 * BOOL game_is_over(Game *game);
 * void game_print_data(Game *game);

 * Command *game_get_last_command(Game *game);
 * STATUS game_set_last_command(Game *game, Command *cmd);
 * Object **game_get_objects(Game *game);
 * BOOL game_inventory_objects_are_iluminated(Game *game);
 * Space ** game_get_spaces(Game *game);
 * Link **game_get_links(Game * game);
 * Slot *game_get_slots(Game *game);
 * STATUS game_set_slot(Game *game, Slot *slot);
 * STATUS game_add_slot(Game *game, char *filename);
 * BOOL game_get_connection_status(Game *game, Id space, DIRECTION dir);
 * Object *game_get_object(Game *game, Id id);
 * Id game_get_player_location(Game *game);
 * Id game_get_enemy_location(Game *game);
 * Id game_get_object_location(Game *game, Id object);
 * Id game_get_connection(Game *game, Id space, DIRECTION dir);
 */
    void test1_game_create();
    void test1_game_add_space();
    void test2_game_add_space();
    void test3_game_add_space();
    void test1_game_player_add_space();
    void test2_game_player_add_space();
    void test3_game_player_add_space();
    void test1_game_enemy_add_space();
    void test2_game_enemy_add_space();
    void test3_game_enemy_add_space();
    void test1_game_get_space();
    void test1_game_get_player();
    void test2_game_get_player();
    void test1_game_get_enemy();
    void test2_game_get_enemy();

#endif
