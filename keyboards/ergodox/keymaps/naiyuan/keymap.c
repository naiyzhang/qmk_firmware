#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // Default Layer
#define BAFN 1 // Fn Actions
#define MCLR 2 // Mac layer
#define MCFN 3 // Mac Fn Actions
#define GAME 4 // Gaming Layer
#define GAFN 5 // Gaming Fn Actions
#define MSLR 6 // Maplestory Gaming Layer
#define MSFN 7 // Maplestory Gaming Fn Actions

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Ins  |           |  FN2 |   6  |   7  |   8  |   9  |   0  | Bcksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Esc  |           |  "   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | F10    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| -/_  |           |  =/+ |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  Gui | LAlt | Left | Right|                                       |  Up  | Down |   [  |   ]  | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | FN1  | Home |       | PgUp | FN1    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | FN1  | Alt  |------|       |------|   `    |Space/|
 *                                 |      |      | Alt  |       | `    |        |RCtrl |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_INS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        KC_F10,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,
        KC_LCTL,        KC_LGUI,      KC_LALT,KC_LEFT,KC_RGHT,
                                              KC_FN1, KC_HOME,
                                                              KC_END,
                                              KC_FN1, KC_LALT,KC_LALT,
        // right hand
        KC_FN2,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_QUOT,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_ENT,
        KC_EQL,      KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                             KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_DELT,
        KC_PGUP,     KC_FN1,
        KC_PGDN,
        KC_GRV,      KC_GRV, CTL_T(KC_SPC)
    ),
/* Keymap 1: Base Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  FN5    |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  FN8    |      |      | VolD | VolU | Mute |      |           |      |      |      |      |      |      | Pause  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS   |      |      |      |      |      |------|           |------| Home | PgUp | PgDn | End  |      |  Prt   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Stop | Play | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[BAFN] = KEYMAP(
       // left hand
       KC_FN5 ,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
       KC_FN8 ,KC_TRNS,KC_TRNS,KC_VOLD,KC_VOLU,KC_MUTE,KC_TRNS,
       KC_CAPS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS,
                KC_HOME, KC_PGDN,KC_PGUP, KC_END,  KC_TRNS, KC_PSCR,
       KC_TRNS, KC_MSTP, KC_MPLY,KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_HOME,KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Mac layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Ins  |           |  FN4 |   6  |   7  |   8  |   9  |   0  | Bcksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Esc  |           |  "   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | F10    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| -/_  |           |  =/+ |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LAlt |  Gui | Left | Right|                                       |  Up  | Down |   [  |   ]  | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | FN3  | Home |       | PgUp | FN3    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | FN3  | Gui  |------|       |------|   `/   |Space/|
 *                                 |      |      | Alt  |       | `    |   Alt  |RCtrl |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[MCLR] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_INS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        KC_F10,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,
        KC_LCTL,        KC_LALT,      KC_LGUI,KC_LEFT,KC_RGHT,
                                              KC_FN3, KC_HOME,
                                                              KC_END,
                                              KC_FN3, KC_LGUI,KC_LALT,
        // right hand
        KC_FN4,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_QUOT,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_ENT,
        KC_EQL,      KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                             KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_DELT,
        KC_PGUP,     KC_FN3,
        KC_PGDN,
        KC_GRV,      ALT_T(KC_GRV), CTL_T(KC_SPC)
    ),
/* Keymap 3: Mac Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      | VolD | VolU | Mute |      |           |      |      |      |      |      |      | Pause  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS   |      |      |      |      |      |------|           |------| Home | PgUp | PgDn | End  |      |  Prt   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Stop | Play | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[MCFN] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLD,KC_VOLU,KC_MUTE,KC_TRNS,
       KC_CAPS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS,
                KC_HOME, KC_PGDN,KC_PGUP, KC_END,  KC_TRNS, KC_PSCR,
       KC_TRNS, KC_MSTP, KC_MPLY,KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_HOME,KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Ins  |           |  FN7 |   6  |   7  |   8  |   9  |   0  | Bcksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Esc  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | F10    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| -/_  |           |  =/+ |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  Gui | RAlt | RCtrl| LAlt |                                       |  Up  | Down |   [  |   ]  | Del  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | FN6  | Home |       | PgUp | FN6    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 |Space | FN6  |------|       |------| RCtrl  |Space |
 *                                 |      |      | Alt  |       | `    |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[GAME] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_INS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        CTL_T(KC_F10),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   RALT_T(KC_MINS),
        KC_LCTL,        KC_LGUI,      KC_RALT,KC_RCTL,KC_LALT,
                                              KC_FN6, KC_HOME,
                                                              KC_END,
                                              KC_SPC, KC_FN6, KC_LALT,
        // right hand
        KC_FN7,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_QUOT,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_ENT,
        KC_EQL,      KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                             KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          KC_DELT,
        KC_PGUP,     KC_FN6,
        KC_PGDN,
        KC_GRV,      KC_RCTL,CTL_T(KC_SPC)
    ),
/* Keymap 5: Game Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  6   |  7   |  8   |  9   |  0   |      |           |      | VolD | VolU | Mute |      |      | Pause  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS   |  [   |  ]   |      |      |      |------|           |------| Home | PgUp | PgDn | End  |      |  Prt   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Stop | Play | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[GAFN] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
       KC_TRNS,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_TRNS,
       KC_CAPS,KC_LBRC,KC_RBRC,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU,KC_MUTE, KC_TRNS, KC_TRNS, KC_PAUS,
                KC_HOME, KC_PGDN,KC_PGUP, KC_END,  KC_TRNS, KC_PSCR,
       KC_TRNS, KC_MSTP, KC_MPLY,KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_HOME,KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 6: Maplestory Gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Ins  |           |  FN10|   6  |   7  |   8  |   9  |   0  | Bcksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Esc  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | F10    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| -/_  |           |  =/+ |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  Gui | RAlt | RCtrl| LAlt |                                       |  Up  | Down | Right|  Up  | Down  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | FN9  | Home |       | PgUp | FN9    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 |Space | FN9  |------|       |------| RCtrl  |Space |
 *                                 |      |      | Alt  |       | `    |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[MSLR] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_INS,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        CTL_T(KC_F10),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,
        KC_LCTL,        KC_LGUI,      KC_RALT,KC_RCTL,KC_LALT,
                                              KC_FN9, KC_HOME,
                                                              KC_END,
                                              KC_SPC, KC_FN9, KC_LALT,
        // right hand
        KC_FN10,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_QUOT,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_ENT,
        KC_EQL,      KC_N,   KC_M,  KC_COMM,KC_DOT, KC_UP,            KC_RSFT,
                             KC_SLSH,KC_SLSH,KC_LEFT,KC_DOWN,         KC_RGHT,
        KC_PGUP,     KC_FN9,
        KC_PGDN,
        KC_GRV,      KC_RCTL,CTL_T(KC_SPC)
    ),
/* Keymap 7: Maplestory Game Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  6   |  7   |  8   |  9   |  0   |      |           |      | VolD | VolU | Mute |      |      | Pause  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS   |  [   |  ]   |      |      |      |------|           |------| Home | PgUp | PgDn | End  |      |  Prt   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Stop | Play | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[MSFN] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,
       KC_TRNS,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_TRNS,
       KC_CAPS,KC_LBRC,KC_RBRC,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU,KC_MUTE, KC_TRNS, KC_TRNS, KC_PAUS,
                KC_HOME, KC_PGDN,KC_PGUP, KC_END,  KC_TRNS, KC_PSCR,
       KC_TRNS, KC_MSTP, KC_MPLY,KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_HOME,KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(BAFN),                // FN1  - Momentary Layer 1 (Base Functions)
    [2] = ACTION_LAYER_SET(MCLR, ON_PRESS),            // FN2  - Switch to Layer 2 (Mac Layer)
    [3] = ACTION_LAYER_MOMENTARY(MCFN),                // FN3  - Momentary Layer 3 (MacLayer Functions)
    [4] = ACTION_LAYER_SET(BASE, ON_PRESS),            // FN4  - Reset to Base Layer
    [5] = ACTION_LAYER_SET(GAME, ON_PRESS),            // FN5  - Switch to Layer 4 (Game Layer)
    [6] = ACTION_LAYER_MOMENTARY(GAFN),                // FN6  - Momentary Layer 5 (Game Layer Functions)
    [7] = ACTION_LAYER_SET(BASE, ON_PRESS),            // FN7  - Reset to Base Layer
    [8] = ACTION_LAYER_SET(MSLR, ON_PRESS),            // FN8  - Switch to Layer 6 (Maplestory Game Layer)
    [9] = ACTION_LAYER_MOMENTARY(MSFN),                // FN9  - Momentary Layer 7 (Maplestory Game Layer Functions)
    [10] = ACTION_LAYER_SET(BASE, ON_PRESS)            // FN10 - Reset to Base Layer
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

};
