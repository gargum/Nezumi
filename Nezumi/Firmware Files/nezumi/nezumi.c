/*
This file exists primarily to allow for more advanced Cirque/Pointer configuration options.
*/

#include "nezumi.h"

bool set_arrow = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_arrow == true) {
        if (mouse_report.x > 1023) {
            mouse_report.x = 0;
            
            unregister_code(KC_LEFT);
            register_code(KC_RGHT);
        }
        else if (mouse_report.x < 1023) {
            mouse_report.x = 0;
            
            unregister_code(KC_RGHT);
            register_code(KC_LEFT);
        }
        else {
            unregister_code(KC_LEFT);
            unregister_code(KC_RGHT);
        }
        
        if (mouse_report.y > 767) {
            mouse_report.y = 0;
            
            unregister_code(KC_DOWN);
            register_code(KC_UP);
        }
        else if (mouse_report.y < 767) {
            mouse_report.y = 0;
            
            unregister_code(KC_UP);
            register_code(KC_DOWN);
        }
        else {
            unregister_code(KC_UP);
            unregister_code(KC_DOWN);
        }
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_SYRQ && record->event.pressed) {
        set_arrow = !set_arrow;
    }
    return true;
}
