#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"
#include "sendstring_norwegian.h"
// Custom keycodes for mod-tap compatibility and for norwegian letters
enum custom_keycodes {
    SYM_HASH = SAFE_RANGE,  // #
    SYM_PERC,               // %
    SYM_DLR,                // $
    SYM_PLUS,               // +
    // NO_AE,                  // æ/Æ
    // NO_OE,                  // ø/Ø
    // NO_AA,                  // å/Å
    CTRL_PLUS,
    CTRL_MINUS,
};

enum dasbob_layers {
  BASE,
  SYM,
  NAV,
  FUN
};

// symbol definitions
#define SYM_EXLM NO_EXLM//S(KC_1)    // !
#define SYM_AT   NO_AT//S(KC_2)    // @
//#define SYM_HASH S(KC_3)    // #
//#define SYM_DLR  S(KC_4)    // $
//#define SYM_PERC S(KC_5)    // %
#define SYM_CIRC NO_CIRC//S(KC_6)    // ^
#define SYM_AMPR NO_AMPR//S(KC_7)    // &
#define SYM_ASTR NO_ASTR//S(KC_8)    // *
#define SYM_LPRN NO_LPRN//S(KC_9)    // (
#define SYM_RPRN NO_RPRN//S(KC_0)    // )
#define SYM_MINS NO_MINS//KC_MINS    // -
#define SYM_UNDR NO_UNDS//S(KC_MINS) // _
#define SYM_EQL  NO_EQL//KC_EQL     // =
//#define SYM_PLUS S(KC_EQL)  // +
#define SYM_LBRC NO_LBRC//KC_LBRC    // [
#define SYM_RBRC NO_RBRC//KC_RBRC    // ]
#define SYM_LCBR NO_LCBR//S(KC_LBRC) // {
#define SYM_RCBR NO_RCBR//S(KC_RBRC) // }
#define SYM_BSLS NO_BSLS//KC_BSLS    //  backslash
#define SYM_SLSH S(NO_7)             //  forward slash
#define SYM_PIPE NO_PIPE//S(KC_BSLS) // |
#define SYM_SCLN NO_SCLN//KC_SCLN    // ;
#define SYM_COLN NO_COLN//S(KC_SCLN) // :
#define SYM_QUOT NO_QUOT//KC_QUOT    // '
#define SYM_DQUO NO_DQUO//S(KC_QUOT) // "
#define SYM_COMM NO_COMM//KC_COMM    // ,
#define SYM_LT   NO_LABK//S(KC_COMM) // <
#define SYM_DOT  NO_DOT//KC_DOT     // .
#define SYM_GT   NO_RABK//S(KC_DOT)  // >
#define SYM_QUES NO_QUES//S(KC_SLSH) // ?
#define SYM_GRV  NO_GRV//KC_GRV     // `
#define SYM_TILD NO_TILD//S(KC_GRV)  // ~

#define NO_AA NO_ARNG //AA
#define NO_OO NO_OSTR //OO
//#define NO_AE NO_AE //AE

// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_HASH:
            if (record->event.pressed) {
                SEND_STRING("#");
            }
            return false;
        case SYM_PERC:
            if (record->event.pressed) {
                SEND_STRING("%");
            }
            return false;
        case SYM_PLUS:
            if (record->event.pressed) {
                SEND_STRING("+");
            }
            return false;
        case SYM_DLR:
            if (record->event.pressed) {
                SEND_STRING("$");
            }
            return false;
        case CTRL_PLUS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_EQUAL)))); // Ctrl + Shift + =
            }
            return false;
        case CTRL_MINUS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_MINUS))); // Ctrl + -
            }
            return false;
    }
    return true;
}

// Custom macros for shorter keycode mapping
#define G_A LGUI_T(KC_A)    // Gui key when held, A when pressed
#define G_C LGUI_T(SYM_COLN) // Gui key when held, : when pressed
#define A_S LALT_T(KC_S)    // ALT key when held, S when pressed
#define A_L RALT_T(KC_L)    // ALT key when held, L when pressed
#define S_D LSFT_T(KC_D)    // SHIFT key when held, D when pressed
#define S_K RSFT_T(KC_K)    // SHIFT key when held, K when pressed
#define C_F LCTL_T(KC_F)    // Control key when held, K when pressed
#define C_J RCTL_T(KC_J)    // Control key when held, J when pressed

// Symbol layer hold taps
#define G_H LGUI_T(SYM_HASH)    // Gui when held, # when pressed
#define G_D LGUI_T(SYM_DLR)     // Gui when held, $ when pressed
#define A_P LALT_T(SYM_PERC)    // ALT when held, % when pressed
#define A_6 RALT_T(KC_6)        // ALT when held, 6 when pressed
#define S_M LSFT_T(SYM_MINS)    // SHIFT when held, - when pressed
#define S_5 RSFT_T(KC_5)        // SHIFT when held, 5 when pressed
#define C_P LCTL_T(SYM_PLUS)    // Control when held, + when pressed
#define C_4 RCTL_T(KC_4)        // Control when held, 4 when pressed

// Layer macros
#define SYM_SPC LT(SYM, KC_SPC)    // Symbol layer when held, Space when tapped
#define SYM_BSPC LT(SYM, KC_BSPC)  // Symbol layer when held, Backspace when tapped
#define NAV_TAB LT(NAV, KC_TAB)    // Navigation layer when held, tab when tapped
#define NAV_ENT LT(NAV, KC_ENT)    // Navigation layer when held, enter when tapped
#define FUN_ESC LT(FUN, KC_ESC)    // Function layer when held, escape when tapped
#define FUN_DEL LT(FUN, KC_DEL)    // Function layer when held, delete when tapped

const uint16_t PROGMEM open_parentasis[] = {A_S, C_F, COMBO_END};
const uint16_t PROGMEM close_parentasis[] = {C_J, A_L, COMBO_END};
const uint16_t PROGMEM open_bracket[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM close_bracket[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM open_curl_bracket[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM close_curl_bracket[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM double_quote[] = {S_D, C_F, COMBO_END};
const uint16_t PROGMEM single_quote[] = {C_J, S_K, COMBO_END};
const uint16_t PROGMEM forward_slash[] = {G_A, C_F, COMBO_END};
const uint16_t PROGMEM back_slash[] = {C_J, SYM_COLN, COMBO_END};
const uint16_t PROGMEM less_than[] = {KC_Q, KC_R, COMBO_END};
const uint16_t PROGMEM greater_than[] = {KC_U, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(open_parentasis, SYM_LPRN),
    COMBO(close_parentasis, SYM_RPRN),
    COMBO(open_bracket, SYM_LBRC),
    COMBO(close_bracket, SYM_RBRC),
    COMBO(open_curl_bracket, SYM_LCBR),
    COMBO(close_curl_bracket,SYM_RCBR),
    COMBO(double_quote, SYM_DQUO),
    COMBO(single_quote, SYM_QUOT),
    COMBO(back_slash, SYM_BSLS),
    COMBO(forward_slash, SYM_SLSH),
    COMBO(less_than, SYM_LT),
    COMBO(greater_than, SYM_GT)
};

const key_override_t colon_to_semi = ko_make_basic(MOD_MASK_SHIFT, SYM_COLN, SYM_SCLN);
const key_override_t space_to_backspace = ko_make_basic(MOD_MASK_SHIFT, SYM_SPC, KC_BSPC);
const key_override_t open_to_close_parentasis = ko_make_basic(MOD_MASK_SHIFT, SYM_RPRN, SYM_LPRN);
const key_override_t open_to_close_bracket = ko_make_basic(MOD_MASK_SHIFT, SYM_LBRC, SYM_RBRC);
const key_override_t open_to_close_curl = ko_make_basic(MOD_MASK_SHIFT, SYM_LCBR, SYM_RCBR);
const key_override_t double_to_single_quote = ko_make_basic(MOD_MASK_SHIFT, SYM_DQUO, SYM_QUOT);


const key_override_t *key_overrides[] = {
    &space_to_backspace,
    &colon_to_semi,
    &open_to_close_parentasis,
    &open_to_close_curl,
    &open_to_close_bracket,
    &double_to_single_quote
};



// Set per key tapping term and flavour. keycodes set to return true, will have hold-preferred, false is tap-preferred
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_SPC:
            return true;
        case SYM_BSPC:
            return true;
        case NAV_TAB:
            return true;
        case NAV_ENT:
            return true;
        case FUN_ESC:
            return true;
        case FUN_DEL:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*  When tapped:                                          When held:
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐     ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │     │   │   │   │   │   │       │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ : │     │WIN│ALT│SHF│CTR│   │       │   │CRT│SHF│ALT│WIN│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤     ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ _ │     │   │   │   │   │   │       │   │   │   │   │   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘     └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐                         ┌───┐                   ┌───┐
      *           │ESC├───┐           ┌───┤DEL│                         │FUN├───┐           ┌───┤FUN│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘                         └───┤SYM├───┐   ┌───┤SYM├───┘
      *               └───│TAB│   │RET├───┘                                 └───│NAV│   │NAV├───┘
      *                   └───┘   └───┘                                         └───┘   └───┘
      */


    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,   KC_W,   KC_E,   KC_R,    KC_T,          KC_Y,       KC_U,       KC_I,       KC_O,    KC_P,
        G_A,    A_S,    S_D,    C_F,     KC_G,          KC_H,       C_J,        S_K,        A_L,     SYM_COLN,
        KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,          KC_N,       KC_M,       SYM_COMM,   SYM_DOT, NO_MINS,//KC_MINS,
                        FUN_ESC, SYM_SPC, NAV_TAB,      NAV_ENT,    SYM_BSPC,   FUN_DEL
    ),

  /*
  *   ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
  *   │ @ │ ~ │ | │ ^ │ < │       │BCP│ 7 │ 8 │ 9 │ ` │
  *   ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
  *   │ # │ % │ - │ + │ = │       │ 0 │ 4 │ 5 │ 6 │ $ │
  *   ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
  *   │c.w│ & │ ? │ ! │ * │       │ , │ 1 │ 2 │ 3 │ . │
  *   └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  *             ┌───┐                   ┌───┐
  *             │FUN├───┐           ┌───┤FUN│
  *             └───┤SYM├───┐   ┌───┤SYM├───┘
  *                 └───│NAV│   │NAV├───┘
  *                     └───┘   └───┘
  */
    [SYM] = LAYOUT_split_3x5_3(
       SYM_AT,   SYM_TILD, SYM_PIPE, SYM_CIRC, KC_NO,          KC_BSPC,    KC_7,       KC_8,   KC_9,   SYM_GRV,
       SYM_HASH, SYM_PERC, SYM_MINS, SYM_PLUS, SYM_EQL,        KC_0,       C_4,        S_5,    A_6,    SYM_DLR,
       CW_TOGG,  SYM_AMPR, SYM_QUES, SYM_EXLM, SYM_ASTR,       SYM_COMM,   KC_1,       KC_2,   KC_3,   SYM_DOT,
                            KC_ESC,  KC_SPC,   KC_TAB,         KC_ENT,     KC_BSPC,    KC_DEL
    ),
    [NAV] = LAYOUT_split_3x5_3(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_KB_VOLUME_UP,     KC_HOME, KC_PGDN, KC_PGUP,   KC_END,  KC_AUDIO_VOL_UP,
        KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_KB_VOLUME_DOWN,   KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, KC_AUDIO_VOL_DOWN,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_KB_MUTE,          KC_PSCR, KC_NO,   KC_NO,     KC_MEDIA_PLAY_PAUSE,   KC_AUDIO_MUTE,
                                KC_ESC,     KC_SPC,     KC_TAB,              KC_ENT,  KC_BSPC, KC_DEL
    ),

    [FUN] = LAYOUT_split_3x5_3(
        KC_NO,      KC_NO,      NO_AE,       NO_OO,       KC_NO,          KC_NO,  KC_F7, KC_F8, KC_F9, KC_F10,
        NO_AA,      KC_NO,      CTRL_MINUS, CTRL_PLUS,    LALT(KC_F4),    KC_NO,  KC_F4, KC_F5, KC_F6, KC_F11,
        KC_NO,      KC_NO,      KC_NO,       KC_NO,       UC_NEXT,        KC_NO,  KC_F1, KC_F2, KC_F3, KC_F12,
                                KC_ESC,      KC_SPC,      KC_TAB,         KC_ENT, KC_BSPC, KC_DEL
    ),



};
