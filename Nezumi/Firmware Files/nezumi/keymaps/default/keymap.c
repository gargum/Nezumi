// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _ARROW
};

typedef enum presses {
TD_NONE,
TD_UNKNOWN,
TD_SINGLE_TAP,
TD_SINGLE_HOLD,
TD_DOUBLE_TAP,
TD_DOUBLE_HOLD,
TD_DOUBLE_SINGLE_TAP, //send two single taps
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    ARROW_DANCE,
};

td_state_t cur_dance(tap_dance_state_t *state);

void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_nezumi(
    KC_WH_U, KC_BTN1,
    KC_WH_D, KC_BTN2
  ),
  [_ARROW] = LAYOUT_nezumi(
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS
  )
};

const uint16_t PROGMEM volume_up[]  =       {KC_BTN1, KC_WH_U, COMBO_END};
const uint16_t PROGMEM volume_down[]  =     {KC_BTN2, KC_WH_D, COMBO_END};
const uint16_t PROGMEM browser_forward[]  = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM browser_back[]  =    {KC_WH_U, KC_WH_D, COMBO_END};
const uint16_t PROGMEM arrow_combo[]  =     {KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D, COMBO_END};

combo_t key_combos [] = {
	COMBO(volume_up,        KC_VOLU),
	COMBO(volume_down,      KC_VOLD),
	COMBO(browser_forward,  KC_WFWD),
	COMBO(browser_back,     KC_WBAK),
	COMBO(arrow_combo,      TD(ARROW_DANCE))
};

td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return TD_SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return TD_SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed) return TD_DOUBLE_HOLD;
    else return TD_DOUBLE_TAP;
  } else return TD_UNKNOWN;
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static td_tap_t xtap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void x_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_MPLY); break;
    case TD_SINGLE_HOLD: layer_on(_ARROW); break;
    case TD_DOUBLE_TAP: register_code(KC_MPLY); unregister_code(KC_MPLY); register_code(KC_MPLY); break;
    case TD_DOUBLE_HOLD: layer_on(_ARROW); layer_off(_ARROW); layer_on(_ARROW); break;
    case TD_DOUBLE_SINGLE_TAP: register_code(KC_MPLY); unregister_code(KC_MPLY); register_code(KC_MPLY);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
};

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_MPLY); break;
    case TD_SINGLE_HOLD: layer_off(_ARROW); break;
    case TD_DOUBLE_TAP: unregister_code(KC_MPLY); break;
    case TD_DOUBLE_HOLD: layer_off(_ARROW); break;
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_MPLY);
    case TD_NONE: break;
    case TD_UNKNOWN: break;
    default: break;
  }
  xtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [ARROW_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SYRQ:
            if(record->event.pressed){
                layer_on(_ARROW);
            }else{
                layer_off(_ARROW);
            }
            return false;
        default:
            return true;
    }
}
