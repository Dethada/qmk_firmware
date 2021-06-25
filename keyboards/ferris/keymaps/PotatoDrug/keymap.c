// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// MACROS

enum custom_keycodes {
    M_INPUTSWITCH = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M_INPUTSWITCH:
        if (record->event.pressed) {
            // when keycode M_INPUTSWITCH is pressed
            register_code(KC_LWIN);
            register_code(KC_SPC);
        } else {
            // when keycode M_INPUTSWITCH is released
            unregister_code(KC_LWIN);
            unregister_code(KC_SPC);
        }
        break;
    }
    return true;
};

// LAYERS

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _BASE,
  _FUNC,
  _NAV,
  _SYM,
  _NUM
};

#define KC_GUISPC MT(MOD_LGUI, KC_SPC)
#define KC_SFTTAB MT(MOD_LSFT, KC_TAB)
#define KC_CTLBSPC MT(MOD_LCTL, KC_BSPC)
#define KC_ALTENT MT(MOD_LALT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* BASE */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,    KC_L,  KC_U,    KC_Y,   KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,            KC_H,    KC_N,  KC_E,    KC_I,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_K,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                              KC_GUISPC, KC_SFTTAB, KC_CTLBSPC, KC_ALTENT
  ),

  [_FUNC] = LAYOUT( /* FUNCTIONS */
    KC_F12,    KC_F7,    KC_F8,    KC_F9,    KC_CAPS,           KC_J,     KC_MUTE,       KC_VOLD, KC_VOLU,   KC_SCLN,
    KC_F11,    KC_F4,    KC_F5,    KC_F6,    KC_APP,            KC_H,     KC_MPRV,       KC_E,    KC_MPLY,   KC_MNXT,
    KC_F10,    KC_F1,    KC_F2,    KC_F3,    KC_INS,            KC_PSCR,  M_INPUTSWITCH, KC_COMM, KC_DOT,    KC_SLSH,
                                         KC_LWIN, KC_LSFT, KC_LCTL, KC_LALT
  ),

  [_NAV] = LAYOUT( /* NAVIGATION */
    KC_Q,      KC_W,   KC_F,    KC_P,     KC_G,            KC_J,    KC_L,     KC_U,      KC_Y,    KC_SCLN,
    KC_DELETE, KC_CUT, KC_COPY, KC_PASTE, KC_UNDO,         KC_ESC,  KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,
    KC_Z,      KC_X,   KC_C,    KC_V,     KC_B,            KC_K,    KC_HOME,  KC_PGDOWN, KC_PGUP, KC_END,
                              KC_GUISPC, KC_SFTTAB, KC_CTLBSPC, KC_ALTENT
  ),

  [_SYM] = LAYOUT( /* SYMBOLS */
    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_GRV,    KC_TILD,            KC_MINS, KC_DQUO,  KC_QUOT,    KC_PLUS,   KC_SCLN,
    KC_UNDS,    KC_MINS,    KC_LPRN,    KC_RPRN,   KC_EQL,             KC_PIPE, KC_LCBR,  KC_LCBR,    KC_LBRC,   KC_RBRC,
    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,            KC_BSLS, KC_M,     KC_COMM,    KC_DOT,    KC_SLSH,
                              KC_GUISPC, KC_SFTTAB, KC_CTLBSPC, KC_ALTENT
  ),

  [_NUM] = LAYOUT( /* NUMBERS */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,   KC_7,  KC_8,    KC_9,   KC_SCLN,
    KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,          KC_0,   KC_4,  KC_5,    KC_6,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_DOT, KC_1,  KC_2,    KC_3,   KC_SLSH,
                              KC_GUISPC, KC_SFTTAB, KC_CTLBSPC, KC_ALTENT
  )
};

// COMBOS

enum combo_events {
  TO_BASE_LAYER_0,
  TO_BASE_LAYER_1,
  // TO_BASE_LAYER_2,
  TO_BASE_LAYER_3,
  // TO_BASE_LAYER_4,
  TO_FUNC_LAYER,
  TO_NAV_LAYER,
  TO_SYM_LAYER,
  TO_NUM_LAYER
};

const uint16_t PROGMEM base_base_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM base_func_combo[] = {KC_F8, KC_F9, COMBO_END};
// const uint16_t PROGMEM base_nav_combo[] = {KC_COPY, KC_PASTE, COMBO_END};
const uint16_t PROGMEM base_sym_combo[] = {KC_ASTR, KC_GRV, COMBO_END};
// const uint16_t PROGMEM base_num_combo[] = {KC_ASTR, KC_SLSH, COMBO_END};
const uint16_t PROGMEM func_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM nav_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM sym_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM num_combo[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TO_BASE_LAYER_0] = COMBO_ACTION(base_base_combo),
  [TO_BASE_LAYER_1] = COMBO_ACTION(base_func_combo),
  // [TO_BASE_LAYER_2] = COMBO_ACTION(base_nav_combo),
  [TO_BASE_LAYER_3] = COMBO_ACTION(base_sym_combo),
  // [TO_BASE_LAYER_4] = COMBO_ACTION(base_num_combo),
  [TO_FUNC_LAYER] = COMBO_ACTION(func_combo),
  [TO_NAV_LAYER] = COMBO_ACTION(nav_combo),
  [TO_SYM_LAYER] = COMBO_ACTION(sym_combo),
  [TO_NUM_LAYER] = COMBO_ACTION(num_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case TO_BASE_LAYER_0:
      if (pressed) {
        layer_move(_BASE);
      }
      break;
    case TO_BASE_LAYER_1:
      if (pressed) {
        layer_move(_BASE);
      }
      break;
    case TO_BASE_LAYER_3:
      if (pressed) {
        layer_move(_BASE);
      }
      break;
    case TO_FUNC_LAYER:
      if (pressed) {
        layer_move(_FUNC);
      }
      break;
    case TO_NAV_LAYER:
      if (pressed) {
        layer_move(_NAV);
      }
      break;
    case TO_SYM_LAYER:
      if (pressed) {
        layer_move(_SYM);
      }
      break;
    case TO_NUM_LAYER:
      if (pressed) {
        layer_move(_NUM);
      }
      break;
  }
}

