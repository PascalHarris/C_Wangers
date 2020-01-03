//
//  gtk_wangers_action.h
//
//  Created by Pascal Harris on 23/05/2018.
//  Copyright (c) 2018 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef ACTION_H_
#define ACTION_H_
#include "gtk_wangers.h"

/**
 * Structure containing a function pointer and a pointer to the function parameters, if relevant
 */
typedef struct action_param {
    void (*action_ptr)(); /**< @action_ptr: (type void*) Pointer to the function.  */
    gpointer parameter;   /**< @parameter:  (type void*) Pointer to the function parameters.  */
} action_param;

/**
 * set_action_with_parameter:
 * @action_ptr: (type void*) a pointer to the function for the action.
 * @action_parameter: (nullable) (type void*) pointer to the function parameter.
 *
 * @action_ptr must not be %NULL.
 *
 * Sets up the struct containing the function pointer and its parameters.
 *
 * Returns: struct action_param
 */
action_param set_action_with_parameter(void (*action_ptr), gpointer action_parameter);

#endif
