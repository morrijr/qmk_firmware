#include QMK_KEYBOARD_H

#include "joystick.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        JS_BUTTON0, JS_BUTTON3, JS_BUTTON6, JS_BUTTON9,
        JS_BUTTON1, JS_BUTTON4, JS_BUTTON7, JS_BUTTON10,
        JS_BUTTON2, JS_BUTTON5, JS_BUTTON8, JS_BUTTON11
    )
};

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:  // JS_BUTTON12
            if (active) {
                joystick_status.buttons[(JS_BUTTON12 - JS_BUTTON0) / 8] |= 1 << (JS_BUTTON12 % 8);
            } else {
                joystick_status.buttons[(JS_BUTTON12 - JS_BUTTON0) / 8] &= ~(1 << (JS_BUTTON12 % 8));
            }
            joystick_status.status |= JS_UPDATED;
            break;
    }
}

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {[0] = JOYSTICK_AXIS_IN(JOYSTICK_X_PIN, JOYSTICK_MIN, JOYSTICK_CENTER, JOYSTICK_MAX), [1] = JOYSTICK_AXIS_IN(JOYSTICK_Y_PIN, JOYSTICK_MIN, JOYSTICK_CENTER, JOYSTICK_MAX)};
