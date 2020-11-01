#include QMK_KEYBOARD_H

#include "joystick.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_Q, KC_W, KC_E, KC_R,
        KC_A, KC_S, KC_D, KC_F,
        KC_Z, KC_X, KC_C, KC_V
    )
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {LAYOUT_ortho_1x1(JS_BUTTON0)};

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:  // ENC0_SW
            if (active) {
                // tap_code(JS_BUTTON0);
                tap_code(KC_M);
            } else {
                // do nothing
            }
            break;
    }
}

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(JOYSTICK_X_PIN, JOYSTICK_MIN, JOYSTICK_CENTER, JOYSTICK_MAX),
    [1] = JOYSTICK_AXIS_IN(JOYSTICK_Y_PIN, JOYSTICK_MIN, JOYSTICK_CENTER, JOYSTICK_MAX)};
