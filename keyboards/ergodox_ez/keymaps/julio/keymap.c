#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define BASE 0
#define FKEY 1
#define SYMB 2
#define MDIA 3

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

#define HSV_JULIO_BLACK {  0,   0,   0}
#define HSV_JULIO_GOLD  { 35, 255, 255}
#define HSV_JULIO_GREEN {105, 255, 255}
#define HSV_JULIO_RED   {249, 228, 255}

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  EPRM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
        KC_EQL,          KC_1,        KC_2,         KC_3,      KC_4,   KC_5,KC_ESC,
        KC_TAB,          KC_Q,        KC_W,         KC_E,      KC_R,   KC_T,TG(SYMB),
        LALT_T(KC_APP),  KC_A,        KC_S,         KC_D,      KC_F,   KC_G,
        KC_LSFT,         LCTL_T(KC_Z),KC_X,         KC_C,      KC_V,   KC_B,KC_SPC,
        LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT),KC_LEFT,   KC_RGHT,
                                                                                   KC_LCMD,KC_LALT,
                                                                                           KC_HOME,
                                                                            KC_SPC,KC_ENT, KC_END,
 
            KC_RGHT, KC_6,KC_7, KC_8,   KC_9,   KC_0,            KC_MINS,
            TG(SYMB),KC_Y,KC_U, KC_I,   KC_O,   KC_P,            KC_BSLS,
                     KC_H,KC_J, KC_K,   KC_L,   LT(MDIA,KC_SCLN),RALT_T(KC_QUOT),
            KC_SPC  ,KC_N,KC_M, KC_COMM,KC_DOT, RCTL_T(KC_SLSH), RSFT_T(KC_ENTER),
                          KC_UP,KC_DOWN,KC_LBRC,KC_RBRC,         MO(SYMB),
        KC_RALT,KC_RCMD,
        KC_PGUP,
        KC_PGDN,KC_DEL, KC_BSPC
        ),

[FKEY] = LAYOUT_ergodox(
        _______, KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,_______,
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,
                                                                _______,_______,
                                                                                _______,
                                                                _______,_______,_______,

            _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,
            _______,_______,_______,_______,_______,_______, KC_F12,
                    _______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,_______,_______,_______,
                            _______,_______,_______,_______,_______,
        _______,_______,
        _______,
        _______,_______,_______
        ),


[SYMB] = LAYOUT_ergodox(
        KC_ESC, KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,_______,
        _______,KC_EXLM,  KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,_______,
        _______,KC_HASH, KC_DLR,KC_LPRN,KC_RPRN,KC_GRV,
        _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,_______,
        _______,_______,_______,_______,_______,
                                                                RGB_MOD,_______,
                                                                                _______,
                                                                RGB_VAD,RGB_VAI,_______,

            _______,KC_F6,    KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,
            _______,KC_UP,     KC_7,   KC_8,   KC_9,KC_ASTR, KC_F12,
                    KC_DOWN,   KC_4,   KC_5,   KC_6,_______,_______,
            _______,KC_AMPR,   KC_1,   KC_2,   KC_3,KC_BSLS,_______,
                            _______, KC_DOT,   KC_0, KC_EQL,_______,
        RGB_TOG,RGB_SLD,
        _______,
        _______,RGB_HUD,RGB_HUI
        ),

[MDIA] = LAYOUT_ergodox(
        _______,_______,_______,_______,   _______,_______,_______,
        _______,_______,_______,KC_MS_U,   _______,_______,_______,
        _______,_______,KC_MS_L,KC_MS_D,   KC_MS_R,_______,
        _______,_______,_______,_______,   _______,_______,_______,
        _______,_______,_______,KC_MS_BTN1,KC_MS_BTN2,
                                                                   _______,_______,
                                                                                   _______,
                                                                   _______,_______,_______,

            _______,_______,_______,_______,_______,_______,_______,
            _______,_______,_______,_______,_______,_______,_______,
                    _______,_______,_______,_______,_______,KC_MPLY,
            _______,_______,_______,KC_MPRV,KC_MNXT,_______,_______,
                            KC_VOLU,KC_VOLD,KC_MUTE,_______,_______,
        _______,_______,
        _______,
        _______,_______,KC_WBAK
        ),

};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
[FKEY] = {
    // Right hand
    // 6                7                8                9                0
    HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
                     HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,

    // Left hand
    // 5                4                3                2                1
    HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
                     HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK
},

[SYMB] = {
    // Right hand
    // 6                7                8                9                0
    HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,
    HSV_JULIO_BLACK, HSV_JULIO_GREEN, HSV_JULIO_GREEN, HSV_JULIO_GREEN, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_GREEN, HSV_JULIO_GREEN, HSV_JULIO_GREEN, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_GREEN, HSV_JULIO_GREEN, HSV_JULIO_GREEN, HSV_JULIO_BLACK,
                     HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,

    // Left hand
    // 5                4                3                2                1
    HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,  HSV_JULIO_GOLD,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
                     HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK
},

[MDIA] = {
    // Right hand
    // 6                7                8                9                0
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_RED,   HSV_JULIO_RED,   HSV_JULIO_BLACK,
                     HSV_JULIO_RED,   HSV_JULIO_RED,   HSV_JULIO_RED,   HSV_JULIO_BLACK,

    // Left hand
    // 5                4                3                2                1
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_RED,   HSV_JULIO_BLACK, HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_RED,   HSV_JULIO_RED,   HSV_JULIO_RED,   HSV_JULIO_BLACK,
    HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK, HSV_JULIO_BLACK,
                     HSV_JULIO_RED,   HSV_JULIO_RED,   HSV_JULIO_BLACK, HSV_JULIO_BLACK
},

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case RGB_TOG:
  if (record->event.pressed) {
    if (rgb_matrix_config.val) {
      rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 0);
    } else {
      rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 255);
    }
  }
  return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
