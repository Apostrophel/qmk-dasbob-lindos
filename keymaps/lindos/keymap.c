#include QMK_KEYBOARD_H

enum dasbob_layers {
  BASE,
  SYM,
  NAV,
  FUN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ : │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ _ │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤DEL│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───│TAB│   │RET├───┘
      *                   └───┘   └───┘
      */


    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,              KC_E,            KC_R,                 KC_T,               KC_Y,            KC_U,              KC_I,              KC_O,           KC_P,
        LGUI_T(KC_A), LALT_T(KC_S),      LSFT_T(KC_D),    LCTL_T(KC_F),         KC_G,               KC_H,            RCTL_T(KC_J),     LSFT(KC_K),        RALT_T(KC_L),   RGUI_T(KC_SCLN),
        KC_Z,         KC_X,              KC_C,            KC_V,                 KC_B,               KC_N,            KC_M,              KC_COMM,           KC_DOT,         KC_SLSH,
                                         KC_DEL,          LT(SYM, KC_SPC),      LT(NAV, KC_TAB),    LT(NAV, KC_ENT), LT(SYM, KC_BSPC),  KC_DEL
    ),

    [SYM] = LAYOUT_split_3x5_3(
       KC_1,     KC_2,              KC_3,            KC_4,            KC_5,               KC_6,         KC_7,             KC_8,            KC_9,              KC_0,
       CK_RST,  RALT_T(XXXXXXX),   LCTL_T(XXXXXXX), LSFT_T(XXXXXXX), KC_PSCR,           KC_MINS,      LSFT_T(KC_EQL),   LCTL_T(KC_GRV),  RALT_T(KC_QUOT),    KC_BSLS,
       CK_TOGG,  CK_UP,           CK_DOWN,         LCTL(KC_C),      LCTL(KC_V),         KC_TAB,      XXXXXXX,          XXXXXXX,         XXXXXXX,           XXXXXXX,
                                    KC_TRNS,         KC_TRNS,         KC_TAB,             KC_ENT,       KC_TRNS,          KC_TRNS
    ),

    [NAV] = LAYOUT_split_3x5_3(
        KC_ESC,   KC_UP,           XXXXXXX,         XXXXXXX,         CK_TOGG,             KC_NUM_LOCK,  KC_KP_7,          KC_KP_8,         KC_KP_9,           KC_KP_MINUS,
        KC_LEFT,  RALT_T(KC_DOWN), LCTL_T(KC_RGHT), LSFT_T(XXXXXXX), KC_LGUI,             XXXXXXX,      LSFT_T(KC_KP_4),  LCTL_T(KC_KP_5), RALT_T(KC_KP_6),   KC_KP_PLUS,
        KC_MPRV,  KC_MSTP,         KC_MPLY,         KC_MNXT,         KC_PSCR,             XXXXXXX,      KC_KP_1,          KC_KP_2,         KC_KP_3,           KC_KP_0,
                                   KC_TRNS,         KC_TRNS,         KC_TAB,              KC_ENT,       KC_TRNS,          KC_TRNS
    ),


};
