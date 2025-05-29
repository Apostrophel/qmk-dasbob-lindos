#include QMK_KEYBOARD_H

enum dasbob_layers {
  BASE,
  SYM,
  NAV,
  FUN
};

// Custom macros for shorter keycode mapping
#define G_A LGUI_T(KC_A)    // Gui key when held, A when pressed
#define G_C RGUI_T(KC_SCLN) // Gui key when held, : when pressed
#define A_S LALT_T(KC_S)    // ALT key when held, S when pressed
#define A_L RALT_T(KC_L)    // ALT key when held, L when pressed
#define S_D LSFT_T(KC_D)    // SHIFT key when held, D when pressed
#define S_K RSFT_T(KC_K)    // SHIFT key when held, K when pressed
#define C_F LCTL_T(KC_F)    // Control key when held, K when pressed
#define C_J RCTL_T(KC_J)    // Control key when held, J when pressed

// Symbol layer hold taps
#define G_H LGUI_T(KC_HASH) // Gui key when held, # when pressed
#define G_D RGUI_T(KC_DLR)  // Gui key when held, $ when pressed
#define A_P LALT_T(KC_PERC) // ALT key when held, % when pressed
#define A_6 RALT_T(KC_6)    // ALT key when held, 6 when pressed
#define S_M LSFT_T(KC_MINS) // SHIFT key when held, - when pressed
#define S_5 RSFT_T(KC_5)    // SHIFT key when held, 5 when pressed
#define C_P LCTL_T(KC_PLUS) // Control key when held, + when pressed
#define C_4 RCTL_T(KC_4)    // Control key when held, 4 when pressed

// Layer macros
#define SYM_SPC LT(SYM, KC_SPC)    // Layer 1 when held, Space when tapped
#define SYM_BSPC LT(SYM, KC_BSPC)    // Layer 1 when held, Space when tapped
#define NAV_TAB LT(NAV, KC_TAB)    // Layer 1 when held, Space when tapped
#define NAV_ENT LT(NAV, KC_ENT)    // Layer 1 when held, Space when tapped
#define FUN_ESC LT(FUN, KC_ESC)    // Layer 1 when held, Space when tapped
#define FUN_DEL LT(FUN, KC_DEL)    // Layer 1 when held, Space when tapped

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
        KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,          KC_Y,       KC_U,       KC_I,       KC_O,   KC_P,
        G_A,    A_S,    S_D,    C_F,     KC_G,          KC_H,       C_J,        S_K,        A_L,    G_C,
        KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,          KC_N,       KC_M,       KC_COMM,    KC_DOT, KC_SLSH,
                        KC_ESC, SYM_SPC, NAV_TAB,       NAV_ENT,    SYM_BSPC,   KC_DEL
    ),

    [SYM] = LAYOUT_split_3x5_3(
       KC_NO,  KC_NO,    KC_PIPE,   KC_CIRC,    KC_LT,          KC_GT,      KC_7,       KC_8,   KC_9,   KC_GRV,
       G_H,     A_P,     S_M,       C_P,        KC_EQL,         KC_0,       C_4,        S_5,    A_6,    G_D,
       CW_TOGG, KC_AMPR, KC_QUES,   KC_EXLM,    KC_ASTR,        KC_TILD,    KC_1,       KC_2,   KC_3,   KC_AT,
                         FUN_ESC,   KC_SPC,     KC_TAB,         KC_ENT,     KC_BSPC,    FUN_DEL
    ),

    [NAV] = LAYOUT_split_3x5_3(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_HOME, KC_PGDN, KC_PGUP,   KC_ENDO, KC_NO,
        KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_NO,          KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PSCR,        KC_PSCR, KC_NO,   KC_NO,     KC_NO,   KC_NO,
                                KC_ESC,     KC_SPC,     KC_TAB,         KC_ENT,  KC_BSPC, KC_DEL
    ),

    [FUN] = LAYOUT_split_3x5_3(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,  KC_F7, KC_F8, KC_F9, KC_F10,
        KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_NO,          KC_NO,  KC_F4, KC_F5, KC_F6, KC_F11,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,  KC_F1, KC_F2, KC_F3, KC_F12,
                                KC_ESC,     KC_SPC,     KC_TAB,         KC_ENT, KC_BSPC, KC_DEL
    ),



};
