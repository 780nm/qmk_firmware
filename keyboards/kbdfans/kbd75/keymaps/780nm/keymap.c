#include QMK_KEYBOARD_H
#include "sleep_led.h"

//Names

enum layer_names {
    _QW,
    _FM,
    _FN,
    _FA
};


//Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //QWERTY Base
  [_QW] = LAYOUT_ansi_1u(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BRK,   KC_INS,   KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  //Arrows -> mouse (toggle)
  [_FM] = LAYOUT_ansi_1u(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_MS_U,  KC_BTN2,
    _______,  _______,  _______,                                _______,                                _______,  _______,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R
  ),

  //General-use functions
  [_FN] = LAYOUT_ansi_1u(
    KC_PWR,   KC_SLEP,  KC_WAKE,  XXXXXXX,  XXXXXXX,  KC_BRIU,  KC_BRID,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_PSCR,  KC_SLCK,  KC_NLCK,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  C(KC_B),            XXXXXXX,
    XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                   C(S(KC_B)),  XXXXXXX,
    XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_APP,   XXXXXXX,            KC_WH_U,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,                                KC_LOCK,                                TG(_FA),  XXXXXXX,  TG(_FM),  KC_BTN1,  KC_WH_D,  KC_BTN2
  ),

  //Administrative functions
  [_FA] = LAYOUT_ansi_1u(
    RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_TOG,  RGB_MOD,  RGB_RMOD, RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  EEP_RST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  DEBUG,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,
    XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  NK_ON,    NK_OFF,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  GUI_ON,   GUI_OFF,                                XXXXXXX,                                TG(_FA),  TG(_FA),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )

};


//RGB Layers

//Key Indicators
const rgblight_segment_t PROGMEM rgb_layer_capslock[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 0, 255, 150});
const rgblight_segment_t PROGMEM rgb_layer_scrllock[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, 0, 0, 150});
const rgblight_segment_t PROGMEM rgb_layer_numlock[] = RGBLIGHT_LAYER_SEGMENTS({2, 1, 0, 0, 150});

//Layer indicators
const rgblight_segment_t PROGMEM rgb_layer_FM[] = RGBLIGHT_LAYER_SEGMENTS({7, 1, 30, 218, 150});
const rgblight_segment_t PROGMEM rgb_layer_FN[] = RGBLIGHT_LAYER_SEGMENTS({7, 1, 0, 0, 150});
const rgblight_segment_t PROGMEM rgb_layer_FA[] = RGBLIGHT_LAYER_SEGMENTS({7, 1, 0, 255, 150});

//Build indicators
const rgblight_segment_t PROGMEM rgb_layer_aff[] = RGBLIGHT_LAYER_SEGMENTS({6, 1, 106, 255, 150});
const rgblight_segment_t PROGMEM rgb_layer_neg[] = RGBLIGHT_LAYER_SEGMENTS({6, 1, 30, 218, 150});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_FM,
    rgb_layer_capslock,
    rgb_layer_scrllock,
    rgb_layer_numlock,
    rgb_layer_FN,
    rgb_layer_FA,
    rgb_layer_aff,
    rgb_layer_neg
);


//Layer updates

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(4, layer_state_cmp(state, 2));
    rgblight_set_layer_state(5, layer_state_cmp(state, 3));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.scroll_lock);
    rgblight_set_layer_state(3, led_state.num_lock);
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C(S(KC_B)):
      rgblight_blink_layer(6, 3000);
      break;
    case C(KC_B):
      rgblight_blink_layer(7, 3000);
      break;
    case DEBUG:
      rgblight_blink_layer(debug_enable ? 6 : 7, 500);
      break;
    case NK_TOGG:
    case NK_ON:
    case NK_OFF:
        rgblight_blink_layer(keymap_config.nkro ? 6 : 7, 500);
        break;
    case GUI_ON:
    case GUI_OFF:
        rgblight_blink_layer(keymap_config.no_gui ? 6 : 7, 500);
        break;
  }
}

//Override backlight functions

void led_set_user(uint8_t usb_led) {
  //no backlighting
}

void matrix_init_user(void) {
  //no backlighting
}
