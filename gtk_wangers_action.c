#include "gtk_wangers_action.h"

action_param set_action_with_parameter(void (*action_ptr), gpointer action_parameter) {
    action_param action;
    action.action_ptr = action_ptr;
    action.parameter = action_parameter;
    return action;
}
