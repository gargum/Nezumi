/*
This file exists primarily to allow for more advanced Cirque/Pointer configuration options.
*/

#include "nezumi.h"
#include "keyboard.h"
#include "drivers/sensors/cirque_pinnacle.h"
 
 layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        break;
    case 1:
        pinnacle_data_t absolute_coordinates = cirque_pinnacle_read_data();
        
        if(absolute_coordinates.xValue > 1700){
            register_code(KC_RGHT);
            unregister_code(KC_LEFT);
            unregister_code(KC_DOWN);
            unregister_code(KC_UP);
        }else if(absolute_coordinates.xValue < 400 && absolute_coordinates.xValue > 0){
            register_code(KC_LEFT);
            unregister_code(KC_RGHT);
            unregister_code(KC_DOWN);
            unregister_code(KC_UP);
        }else if(absolute_coordinates.yValue > 1200){
            register_code(KC_DOWN);
            unregister_code(KC_UP);
            unregister_code(KC_RGHT);
            unregister_code(KC_LEFT);
        }else if(absolute_coordinates.yValue < 400 && absolute_coordinates.yValue > 0){
            register_code(KC_UP);
            unregister_code(KC_DOWN);
            unregister_code(KC_RGHT);
            unregister_code(KC_LEFT);
        }else{
            unregister_code(KC_RGHT);
            unregister_code(KC_LEFT);
            unregister_code(KC_DOWN);
            unregister_code(KC_UP);
        }
        
        unregister_code(KC_RGHT);
        unregister_code(KC_LEFT);
        unregister_code(KC_DOWN);
        unregister_code(KC_UP);
        break;
    default:
        break;
    }
  return state;
}
