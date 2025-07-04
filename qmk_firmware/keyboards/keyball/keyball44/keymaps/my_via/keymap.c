#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_dvorak.h"

#define MOUSEKEY_SCROLL_DIVISOR 350

enum layers {
  _JIS,
  _DVORAK = 4
};

enum custom_keycodes {
  TO_JIS = SAFE_RANGE,
  TO_DVORAK,
  NEXT_ITERM,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,      KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS   ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,      KC_H     , KC_J     , KC_K     , KC_L     , LT(3,KC_SCLN)  , KC_ENT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,      KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , LT(KC_RSFT,KC_BSLS)  ,
              KC_LALT,TO_DVORAK,   KC_LGUI,LT(1,KC_SPC),LT(3,KC_ENT),        LT(2,KC_BSPC),KC_RGUI, _______,  _______  , KC_ESC
  ),

  [1] = LAYOUT_universal(
    SSNP_FRE ,  KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,       KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SSNP_VRT ,  KC_LEFT , KC_DOWN  , KC_UP   , KC_RGHT  , _______   ,       KC_PGUP  , KC_LEFT  , KC_DOWN    , KC_UP  , KC_RGHT  , KC_F12   ,
    SSNP_HOR ,  _______ , _______  , _______ , _______  , _______  ,       KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
              _______  , _______ , _______  ,  _______  , _______  ,         _______  , _______  , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),               S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  , _______  ,
    _______  , KC_1,    KC_2,   KC_3,     KC_4,     KC_5,                 KC_6    , KC_7      , KC_8     , KC_9     , KC_0      , _______,
    _______  , _______,  _______   , _______   ,_______    ,_______,      _______,_______,_______ ,_______,_______,_______,
                  KC_0     , KC_DOT  , _______, _______  , _______  ,          KC_DEL   , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , KBC_SAVE  ,       _______  ,  KC_LAUNCHPAD  , KC_MISSION_CONTROL  , _______ ,  _______ ,  _______  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,      _______  , KC_BTN1  , KC_BTN3  , KC_BTN2 , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,      CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
             QK_BOOT  , KBC_RST  , KC_VOLD  , KC_MPLY  , KC_VOLU  ,         KC_BTN5  , KC_BTN4  , _______       , _______  , QK_BOOT
  ),



  [4] = LAYOUT_universal(
  KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,       KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , DV_SLSH   ,
  KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,       KC_H     , KC_J     , KC_K     , KC_L     , LT(7,DV_S)  , DV_MINS  ,
  KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,       KC_N     , KC_M     , DV_W  , DV_V   , DV_Z , LT(KC_RSFT,DV_TILD)  ,
            KC_LALT, TO_JIS, KC_LGUI   , LT(5,KC_SPC), LT(7,KC_ENT),     LT(6,KC_BSPC), KC_RGUI, _______, _______ , KC_ESC
),
// dvorak > 1
  [5] = LAYOUT_universal(
  SSNP_FRE ,  KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,       KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SSNP_VRT ,  KC_LEFT , KC_DOWN  , KC_UP   , KC_RGHT  , _______   ,       KC_PGUP  , KC_LEFT  , KC_DOWN    , KC_UP  , KC_RGHT  , KC_F12   ,
    SSNP_HOR ,  _______ , _______  , _______ , _______  , _______  ,       KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
              _______  , _______ , _______  ,  _______  , _______  ,         _______  , NEXT_ITERM  , _______       , _______  , _______
),
// dvorak > 2
  [6] = LAYOUT_universal(
  _______  , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),               S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  , _______  ,
    _______  , KC_1,    KC_2,   KC_3,     KC_4,     KC_5,                 KC_6    , KC_7      , KC_8     , KC_9     , KC_0      , DV_BSLS,
    _______  , DV_COLN,  _______   , _______   ,_______    ,_______,      _______, DV_LBRC , DV_RBRC, DV_LCBR, DV_RCBR, DV_GRV,
                  KC_0     , KC_DOT  , DV_PLUS , DV_EQL  , _______  ,          KC_DEL   , _______  , _______       , _______  , _______
),
// dvorak > 3
  [7] = LAYOUT_universal(
  RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , KBC_SAVE  ,       _______  ,  KC_LAUNCHPAD  , KC_MISSION_CONTROL  , _______ ,  _______ ,  _______  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,      _______  , KC_BTN1  , KC_BTN3  , KC_BTN2 , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,      CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
             QK_BOOT  , KBC_RST  , KC_VOLD  , KC_MPLY  , KC_VOLU  ,         KC_BTN5  , KC_BTN4  , _______       , _______  , QK_BOOT
),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3 || get_highest_layer(state) == 7);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TO_JIS:
            if (record->event.pressed) {
                default_layer_set(1UL << _JIS);
                tap_code(KC_LNG1);
            }
            return false;

        case TO_DVORAK:
            if (record->event.pressed) {
                default_layer_set(1UL << _DVORAK);
                tap_code(KC_LNG2);
            }
            return false;

        case NEXT_ITERM:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(DV_LCBR);
                unregister_code(KC_LGUI);
            }
            return false;
    }
    return true;
}
