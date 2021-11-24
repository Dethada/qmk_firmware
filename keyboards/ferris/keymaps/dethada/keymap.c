#include QMK_KEYBOARD_H

// MACROS

enum custom_keycodes {
    M_INPUTSWITCH = SAFE_RANGE,
    M_UNDO,
    M_CUT,
    M_COPY,
    M_PASTE
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
        case M_UNDO:
          if (record->event.pressed) {
              register_code(KC_LCTL);
              register_code(KC_Z);
          } else {
              unregister_code(KC_LCTL);
              unregister_code(KC_Z);
          }
          break;
        case M_CUT:
          if (record->event.pressed) {
              register_code(KC_LCTL);
              register_code(KC_X);
          } else {
              unregister_code(KC_LCTL);
              unregister_code(KC_X);
          }
          break;
        case M_COPY:
          if (record->event.pressed) {
              register_code(KC_LCTL);
              register_code(KC_C);
          } else {
              unregister_code(KC_LCTL);
              unregister_code(KC_C);
          }
          break;
        case M_PASTE:
          if (record->event.pressed) {
              register_code(KC_LCTL);
              register_code(KC_V);
          } else {
              unregister_code(KC_LCTL);
              unregister_code(KC_V);
          }
          break;
    }
    return true;
};

// LAYERS

enum ferris_layers {
  _BASE,
  _FUNC,
  _NAVSYM,
  _NUM
};

#define KC_GUISPC MT(MOD_LGUI, KC_SPC)
#define KC_ALTENT MT(MOD_LALT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Q___ , ___W___ , ___F___ , ___P___ , ___G___     ,     ___J___ , ___L___ , ___U___ , ___Y___ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___A___ , ___R___ , ___S___ , ___T___ , ___D___     ,     ___H___ , ___N___ , ___E___ , ___I___ , ___O___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Z___ , ___X___ , ___C___ , ___V___ , ___B___     ,     ___K___ , ___M___ , ___,___ , ___.___ , ___/___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               WIN/SPC , __SFT__     ,     _CTRL__ , ALTENTR
//                              ---------+---------+---+---+---------+---------                              //
  [_BASE] = LAYOUT( /* BASE */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,    KC_L,  KC_U,    KC_Y,   KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,            KC_H,    KC_N,  KC_E,    KC_I,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_K,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                              KC_GUISPC, KC_LSFT, KC_LCTL, KC_ALTENT
  ),


//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// __F12__ , __F7___ , __F8___ , __F9___ , __CAPS_     ,     ___J___ , _MUTE__ , _VOLD__ , _VOLU__ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// __F11__ , __F4___ , __F5___ , __F6___ , __APP__     ,     ___H___ , _MPRV__ , ___E___ , _MPLY__ , _MNXT__ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// __F10__ , __F1___ , __F2___ , __F3___ , __INS__     ,     __PSCR_ , _MACRO_ , ___,___ , ___.___ , ___/___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               WIN/SPC , __SFT__     ,     _CTRL__ , ALTENTR
//                              ---------+---------+---+---+---------+---------                              //
  [_FUNC] = LAYOUT( /* FUNCTIONS */
    KC_F12,    KC_F7,    KC_F8,    KC_F9,    KC_CAPS,           KC_J,     KC_MUTE,       KC_VOLD, KC_VOLU,   KC_SCLN,
    KC_F11,    KC_F4,    KC_F5,    KC_F6,    KC_APP,            KC_H,     KC_MPRV,       KC_E,    KC_MPLY,   KC_MNXT,
    KC_F10,    KC_F1,    KC_F2,    KC_F3,    KC_INS,            KC_PSCR,  M_INPUTSWITCH, KC_COMM, KC_DOT,    KC_SLSH,
                                      KC_LWIN, KC_LSFT, KC_LCTL, KC_LALT
  ),


//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___^___ , ___&___ , ___*___ , ___`___ , ___~___     ,     ___J___ , ___L___ , ___|___ , ___\___ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// _MACRO_ , _MACRO_ , _MACRO_ , _MACRO_ , __DEL__     ,     __ESC__ , ___←___ , ___↓___ , ___↑___ , ___→___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___!___ , ___@___ , ___#___ , ___$___ , ___%___     ,     ___K___ , _HOME__ , __PGD__ , __PGU__ , __END__ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               WIN/SPC , __SFT__     ,     _CTRL__ , ALTENTR
//                              ---------+---------+---+---+---------+---------                              //
  [_NAVSYM] = LAYOUT( /* NAVIGATION & SYMBOLS */
    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_GRV,    KC_TILD,            KC_J,    KC_L,  KC_PIPE,   KC_BSLS,  KC_SCLN,
    M_UNDO,     M_CUT,      M_COPY,     M_PASTE,   KC_DELETE,          KC_ESC,  KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT,
    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,    KC_PERC,            KC_K,    KC_HOME,  KC_PGDOWN, KC_PGUP,  KC_END,
                              KC_GUISPC, KC_LSFT, KC_LCTL, KC_ALTENT
  ),


//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Q___ , ___W___ , ___F___ , ___P___ , ___G___     ,     ___J___ , ___7___ , ___8___ , ___9___ , ___;___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___+___ , ___-___ , ___*___ , ___/___ , ___=___     ,     ___0___ , ___4___ , ___5___ , ___6___ , ___O___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
// ___Z___ , ___X___ , ___C___ , ___V___ , ___%___     ,     ___K___ , ___1___ , ___2___ , ___3___ , ___.___ ,
//---------+---------+---------+---------+---------         ---------+---------+---------+---------+---------//
//                               WIN/SPC , __SFT__     ,     _CTRL__ , ALTENTR
//                              ---------+---------+---+---+---------+---------                              //
  [_NUM] = LAYOUT( /* NUMBERS */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,            KC_J,   KC_7,  KC_8,    KC_9,   KC_SCLN,
    KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,          KC_0,   KC_4,  KC_5,    KC_6,   KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_PERC,         KC_K,   KC_1,  KC_2,    KC_3,   KC_DOT,
                              KC_GUISPC, KC_LSFT, KC_LCTL, KC_ALTENT
  )
};

// COMBOS

enum combo_events {
  TO_BASE_LAYER_0,
  TO_BASE_LAYER_1,
  TO_BASE_LAYER_3,
  TO_FUNC_LAYER,
  TO_NAVSYM_LAYER,
  TO_SYM_LAYER,
  TO_NUM_LAYER
};

// layer combos
const uint16_t PROGMEM base_base_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM base_func_combo[] = {KC_F8, KC_F9, COMBO_END};
const uint16_t PROGMEM base_navsym_combo[] = {KC_ASTR, KC_GRV, COMBO_END};
const uint16_t PROGMEM navsym_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM num_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM func_combo[] = {KC_L, KC_Y, COMBO_END};

// key combos
const uint16_t PROGMEM esc_combo[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM backspace_combo_num[] = {KC_J, KC_7, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM underscore_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM dash_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM dquote_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM squote_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM lsquare_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM rsquare_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM lcurly_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM carrot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TO_BASE_LAYER_0] = COMBO_ACTION(base_base_combo),
  [TO_BASE_LAYER_1] = COMBO_ACTION(base_func_combo),
  [TO_BASE_LAYER_3] = COMBO_ACTION(base_navsym_combo),
  [TO_FUNC_LAYER] = COMBO_ACTION(func_combo),
  [TO_NAVSYM_LAYER] = COMBO_ACTION(navsym_combo),
  [TO_NUM_LAYER] = COMBO_ACTION(num_combo),
  COMBO(esc_combo, KC_ESC),
  COMBO(lparen_combo, KC_LPRN),
  COMBO(rparen_combo, KC_RPRN),
  COMBO(underscore_combo, KC_UNDS),
  COMBO(dash_combo, KC_MINS),
  COMBO(equals_combo, KC_EQL),
  COMBO(dquote_combo, KC_DQUO),
  COMBO(squote_combo, KC_QUOT),
  COMBO(lsquare_combo, KC_LBRC),
  COMBO(rsquare_combo, KC_RBRC),
  COMBO(lcurly_combo, KC_LCBR),
  COMBO(rcurly_combo, KC_RCBR),
  COMBO(delete_combo, KC_DELETE),
  COMBO(backspace_combo, KC_BSPC),
  COMBO(backspace_combo_num, KC_BSPC),
  COMBO(tab_combo, KC_TAB),
  COMBO(carrot_combo, KC_CIRC),
  COMBO(dollar_combo, KC_DLR),
  COMBO(hash_combo, KC_HASH),
  COMBO(plus_combo, KC_PLUS)
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
    case TO_NAVSYM_LAYER:
      if (pressed) {
        layer_move(_NAVSYM);
      }
      break;
    case TO_NUM_LAYER:
      if (pressed) {
        layer_move(_NUM);
      }
      break;
  }
}

