#include QMK_KEYBOARD_H
#include "velocikey.h"
#include "process_dynamic_macro.h"

//Names

enum custom_keycodes {
    DC_TVA = SAFE_RANGE,
    DC_TM,
    DC_TD,
    DC_TS,
    DUPL,
    VD_N,
    VD_L,
    VD_R,
    VD_C,
    WARNRST,
    CLEAN
};

enum tap_keycodes {
    BLD,
    VS,
    IDE,
    DM1,
    DM2,
    CLN
};

enum layer_names {
    _QW,
    _FM,
    _FD,
    _FN,
    _FA,
    _CLN
};


//Keymap

#define L_CAPS LT(_FN, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //QWERTY Base
  [_QW] = LAYOUT_ansi_1u(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   TD(VS),   TD(IDE),  TD(BLD),
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
    L_CAPS,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_END,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_INS,
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

  //Pg U/D -> Dynamic Macro(toggle)
  [_FD] = LAYOUT_ansi_1u(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  TD(DM1),  TD(DM2),  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    TD(DM1),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______
  ),

  //General-use functions
  [_FN] = LAYOUT_ansi_1u(
    KC_PWR,   KC_SLEP,  KC_WAKE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BRID,  KC_BRIU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_PSCR,  KC_PAUS,  KC_SLCK,
    DC_TVA,   DC_TM,    DC_TD,    DC_TS,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,            XXXXXXX,  KC_NLCK,
    XXXXXXX,  VD_L,     KC_MS_U,  VD_R,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_PGUP,
    XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  KC_PGDN,
    XXXXXXX,            VD_N,     VD_C,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_APP,   TG(_FA),            KC_WH_U,  XXXXXXX,
    DUPL,     XXXXXXX,  XXXXXXX,                                XXXXXXX,                                TG(_FD),  XXXXXXX,  TG(_FM),  KC_BTN1,  KC_WH_D,  KC_BTN2
  ),

  //Administrative functions
  [_FA] = LAYOUT_ansi_1u(
    WARNRST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    EEP_RST,  RGB_M_P,  RGB_M_SW, RGB_M_SN, RGB_HUD,  RGB_HUI,  RGB_SAD,  RGB_SAI,  RGB_VAD,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    RGB_TOG,  RGB_SPD,  RGB_VAI,  RGB_SPI,  RGB_HUI,  RGB_SAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    XXXXXXX,  RGB_RMOD, RGB_VAD,  RGB_MOD,  RGB_HUD,  RGB_SAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,
    XXXXXXX,            XXXXXXX,  XXXXXXX,  CLEAN,    VLK_TOG,  XXXXXXX,  NK_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  GUI_TOG,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  TG(_FA),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  //Administrative functions
  [_CLN] = LAYOUT_ansi_1u(
    TD(CLN),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,
    XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )

};


//RGB Layers

//Key Indicators
const rgblight_segment_t PROGMEM rgb_layer_capslock[] = RGBLIGHT_LAYER_SEGMENTS({15, 1, 0, 255, 150});
const rgblight_segment_t PROGMEM rgb_layer_scrllock[] = RGBLIGHT_LAYER_SEGMENTS({14, 1, 0, 0, 150});
const rgblight_segment_t PROGMEM rgb_layer_numlock[] = RGBLIGHT_LAYER_SEGMENTS({13, 1, 0, 0, 150});

//Layer indicators
const rgblight_segment_t PROGMEM rgb_layer_FM[] = RGBLIGHT_LAYER_SEGMENTS({8, 1, 30, 218, 150});
const rgblight_segment_t PROGMEM rgb_layer_FD[] = RGBLIGHT_LAYER_SEGMENTS({8, 1, 128, 200, 128});
const rgblight_segment_t PROGMEM rgb_layer_MIX[] = RGBLIGHT_LAYER_SEGMENTS({8, 1, 79, 200, 150});
const rgblight_segment_t PROGMEM rgb_layer_FN[] = RGBLIGHT_LAYER_SEGMENTS({8, 1, 0, 0, 150});
const rgblight_segment_t PROGMEM rgb_layer_FA[] = RGBLIGHT_LAYER_SEGMENTS({8, 1, 0, 255, 150});

//Logic indicators
const rgblight_segment_t PROGMEM rgb_layer_aff[] = RGBLIGHT_LAYER_SEGMENTS({9, 1, 106, 255, 150});
const rgblight_segment_t PROGMEM rgb_layer_neg[] = RGBLIGHT_LAYER_SEGMENTS({9, 1, 30, 218, 150});

const rgblight_segment_t PROGMEM rgb_layer_rst[] = RGBLIGHT_LAYER_SEGMENTS({0, 16, 0, 255, 50});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_aff,
    rgb_layer_neg,
    rgb_layer_capslock,
    rgb_layer_scrllock,
    rgb_layer_numlock,
    rgb_layer_FM,
    rgb_layer_FD,
    rgb_layer_MIX,
    rgb_layer_FN,
    rgb_layer_FA,
    rgb_layer_rst
);


//Layer updates

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    bool layer_FM = layer_state_cmp(state, _FM);
    bool layer_FD = layer_state_cmp(state, _FD);

    if (layer_FM && layer_FD){
        rgblight_set_layer_state(5, false);
        rgblight_set_layer_state(6, false);
        rgblight_set_layer_state(7, true);
    }
    else {
        rgblight_set_layer_state(5, layer_FM);
        rgblight_set_layer_state(6, layer_FD);
        rgblight_set_layer_state(7, false);
    }

    rgblight_set_layer_state(8, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(9, layer_state_cmp(state, _FA));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    rgblight_set_layer_state(3, led_state.scroll_lock);
    rgblight_set_layer_state(4, led_state.num_lock);
    return true;
}

//Process keystrokes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t macro_kc = (keycode == MO(_FN) ? DYN_REC_STOP : keycode);

    if (!process_dynamic_macro(macro_kc, record)) {
        rgblight_blink_layer(0, 500);
        layer_on(_FD);
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case DC_TVA:
                SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_GRV)))));
                return false;
            case DC_TM:
                SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT("1"))));
                return false;
            case DC_TD:
                SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT("2"))));
                return false;
            case DC_TS:
                SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT("3"))));
                return false;
            case DUPL:
                SEND_STRING(SS_LCTL("cv"));
                return false;
            case VD_N:
                SEND_STRING(SS_LGUI(SS_LCTL("d")));
                return false;
            case VD_L:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
                return false;
            case VD_R:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
                return false;
            case VD_C:
                SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_F4))));
                return false;
            case WARNRST:
                rgblight_set_layer_state(10, true);
                reset_keyboard();
                return false;
            case CLEAN:
                layer_off(_FA);
                layer_on(_CLN);
                rgblight_set_layer_state(10, true);
                return false;
        }
    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /*
        case DEBUG:
            rgblight_blink_layer(debug_enable ? 0 : 1, 500);
            break;
        */
        case NK_TOGG:
            rgblight_blink_layer(keymap_config.nkro ? 0 : 1, 500);
            break;
        case GUI_TOG:
            rgblight_blink_layer(keymap_config.no_gui ? 1 : 0, 500);
            break;
        case VLK_TOG:
            rgblight_blink_layer(velocikey_enabled() ? 0 : 1, 500);
            break;
    }
}

void dance_build (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING(SS_LCTL(SS_TAP(X_B)));
            rgblight_blink_layer(1, 10000);
            break;
        case 2:
            SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_B))));
            rgblight_blink_layer(0, 10000);
            break;
        default:
            SEND_STRING(SS_LCTL(SS_TAP(X_PAUSE)));
            rgblight_blink_layer(10, 500);
            break;
    }
    return;
}

void dance_vs (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING(SS_LCTL("kc"));
            break;
        default:
            SEND_STRING(SS_LCTL("ku"));
            break;
    }
    return;
}

void dance_ide (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING(SS_TAP(X_LGUI)SS_DELAY(200)"Visual Studio 2019"SS_DELAY(200)SS_TAP(X_ENT));
            rgblight_blink_layer(0, 500);
            break;
        case 2:
            SEND_STRING(SS_TAP(X_LGUI)SS_DELAY(200)"Visual Studio Code"SS_DELAY(200)SS_TAP(X_ENT));
            rgblight_blink_layer(0, 500);
            break;
        default:
            SEND_STRING(SS_TAP(X_LGUI)SS_DELAY(200)"Git Extensions"SS_DELAY(200)SS_TAP(X_ENT));
            rgblight_blink_layer(1, 500);
            break;
    }
    return;
}

static keyrecord_t KEYREC = {{{0,0},false,0}, {0,0,0,0,0}};

void dance_DM1 (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        process_dynamic_macro(DYN_MACRO_PLAY1, &KEYREC);
        layer_on(_FD); //Refreshes layer state
    } else {
        process_dynamic_macro(DYN_REC_START1, &KEYREC);
        rgblight_blink_layer(1, 500);
    }
    return;
}

void dance_DM2 (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        process_dynamic_macro(DYN_MACRO_PLAY2, &KEYREC);
        layer_on(_FD);
    } else {
        process_dynamic_macro(DYN_REC_START2, &KEYREC);
        rgblight_blink_layer(1, 500);
    }
    return;
}

void dance_CLN (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        layer_off(_CLN);
        rgblight_set_layer_state(10, false);
    }
    return;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [BLD] = ACTION_TAP_DANCE_FN(dance_build),
    [VS] = ACTION_TAP_DANCE_FN(dance_vs),
    [IDE] = ACTION_TAP_DANCE_FN(dance_ide),
    [DM1] = ACTION_TAP_DANCE_FN(dance_DM1),
    [DM2] = ACTION_TAP_DANCE_FN(dance_DM2),
    [CLN] = ACTION_TAP_DANCE_FN(dance_CLN)
};


//Override backlight functions

void led_set_user(uint8_t usb_led) {
  //no backlighting
}

void matrix_init_user(void) {
  //no backlighting
}
