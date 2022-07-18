/**
 * @brief It implements the command interpreter interface
 *
 * @file game_rules.h
 * @author Joaquin
 * @version 2.0
 * @date 25-04-2022
 * @copyright GNU Public License
 */

#ifndef RULES_H
#define RULES_H

#include <string.h>
#include "types.h"


typedef struct _Rule Rule;

#define N_RIG 7


/**
 * it enumerates the two posible types of inputs, the sort one and the long one
 */
typedef enum enum_Rules {
  NO_RULE = -1,     /*!< */ 
  LIGHT_ON,         /*!< */
  LIGHT_OFF,        /*!< */
  OPEN_R,           /*!< */
  CLOSE_R,          /*!< */
  OBJ_CH,           /*!< */
  ROCK              /*!< */
} T_Rules;

/**
  * @brief Initialization of a new Rule
  * @author Joaquin Abad
  *
  *  rule_create allocates memory for a new Rule
  *  and initializes its members
  * 
  * @return rule Rule
  */
Rule * rule_create();

/**
  * @brief It destroys a Rule
  * @author Joaquin Abad
  *
  * rule_destroy destroys a command
  * freeing the allocated memory for it
  * 
  * @param rule a pointer to Rule
  */
void rule_destroy(Rule* rule);

/**
  * @brief Returns the action of a Rule
  * @author Joaquin Abad
  *
  * 
  * @param rule a pointer to Rule
  * @return action related to T_Rules
  */
T_Rules rule_get_action(Rule* rule);

/**
  * @brief Returns the status of a Rule
  * @author Joaquin Abad
  *
  * 
  * @param rule a pointer to Rule
  * @return OK if the rules ejecutes correctly, if not returns ERROR
  */
STATUS rule_get_status(Rule* rule);

/**
  * @brief Returns the description of a Rule
  * @author Joaquin Abad
  *
  * 
  * @param rule a pointer to Rule
  * @return char desscription of Rule
  */
char *rule_get_description(Rule* rule);

/**
  * @brief It sets a new action for Rule
  * @author Joaquin Abad
  *
  * 
  * @param rule a pointer to Rule
  * @param action the new action
  * @return OK if the pointer and the new action are both valid, if not returns ERROR
  */
STATUS rule_set_acction(Rule* rule, T_Rules action);

/**
  * @brief It sets a new status for Rule
  * @author Joaquin Abad
  *
  * 
  * @param rule a pointer to Rule
  * @param status the new status
  * @return OK if the pointer and the new status are both valid, if not returns ERROR
  */
STATUS rule_set_status(Rule* rule, STATUS status);

/**
  * @brief It sets a new description for Rule
  * @author Joaquin Abad
  *
  * 
  * @param rule a pointer to Rule
  * @param description the new description
  * @return OK if the pointer and the new description are both valid, if not returns ERROR
  */
STATUS rule_set_description(Rule* rule, char *desciption);



#endif