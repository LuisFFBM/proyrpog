/**
 * @brief It implements the structure related to the game_rules
 *
 * @file game_rules.c
 * @author Joaquin
 * @version 2.0
 * @date 22-04-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/game_rules.h"
#include "../include/game.h"


#define CMD_LENGHT 40
#define MAX_LEN 300


/**
 * @brief Rule
 *
 * This struct stores all the information of a Rule.
 */
struct _Rule {
    T_Rules action;                   /*!< Rule ejecuted*/
    STATUS status;                    /*!< Status of the rule*/
    char lastdescription[MAX_LEN];    /*!< Description related to the rule*/
};

/**  rule_create allocates memory for a new Rule
  *  and initializes its members
  */
Rule * rule_create() {
    Rule *rule = NULL;

    rule = (Rule*)malloc(sizeof(Rule));

    if (!rule)
    {
        return NULL;
    }

    strcpy(rule->lastdescription,"No rule description");
    rule->status = OK;

    return rule;
}

/** rule_destroy frees the previous memory allocation 
  *  for a rule
  */
void rule_destroy(Rule* rule) {
    
  free(rule);

}

/** It gets the action of the Rule
  */
T_Rules rule_get_action(Rule* rule) {

    if (!rule)
    {
        return NO_RULE;
    }
    
    return rule->action;
}

/** It gets the status of the Rule
  */
STATUS rule_get_status(Rule* rule) {

    if (!rule)
    {
        return ERROR;
    }
    
    return rule->status;
}

/** It gets the description of the Rule
  */
char *rule_get_description(Rule* rule) {

    if (!rule)
    {
        return NULL;
    }
    
    return rule->lastdescription;
}

/** It sets the action for Rule
  */
STATUS rule_set_acction(Rule* rule, T_Rules action) {
    
    if (!rule)
    {
        return ERROR;
    }
    
    rule->action = action;

    return OK;
}

/** It sets the action for Rule
  */
STATUS rule_set_status(Rule* rule, STATUS status) {
    
    if (!rule)
    {
        return ERROR;
    }
    
    rule->status = status;

    return OK;
}

/** It sets the description for Rule
  */
STATUS rule_set_description(Rule* rule, char *desciption) {
    
    if (!rule)
    {
        return ERROR;
    }
    
    strcpy(rule->lastdescription, desciption);

    return OK;

}

T_Rules rule_selection(int n) {

  if (n < 11)
  {
    return NO_RULE;
  }
  else if (n == 11)
  {
    return NO_RULE;
  }
  else if (n == 12)
  {
    return NO_RULE;
  }
  else if (n == 13)
  {
    return ROCK;
  }
  else if (n == 14)
  {
    return OBJ_OFF;
  }
  else if (n == 15)
  {
    return OBJ_DROP;
  }
  else
  {
    return NO_RULE;
  }

  return NO_RULE;
}



