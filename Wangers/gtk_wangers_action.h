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
 @brief Constructs an `action_param` structure from a function pointer and its parameter.
 @discussion Initializes an `action_param` with the provided function pointer and associated parameter. This is useful for deferred execution or callback registration where both the action and its context need to be stored together.
 @param action_ptr A pointer to the function to be executed.
 @param action_parameter A `gpointer` representing the parameter to be passed to the function.
 @return An `action_param` structure containing the function and its parameter.
 */
action_param set_action_with_parameter(void (*action_ptr), gpointer action_parameter);

#endif
