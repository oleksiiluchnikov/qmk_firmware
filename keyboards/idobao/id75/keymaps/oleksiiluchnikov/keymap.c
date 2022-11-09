#include QMK_KEYBOARD_H

bool is_macos  = 1;
bool menu_used  = 0;
bool vimvis_status  = 0;
uint16_t hold_timer = 0;
uint16_t current_layer = 0;

// Layers
#define _ENGRAMM 0
#define _NUMBERS 1
#define _SYMBOLS 2
#define _NAVIGATION 3
#define _ENGRAM 4
#define _MENU 5
#define _VIM 6
#define _OSTICK 7
#define _VIMVIS 8

// Left-hand home row mods
#define GUI_N LGUI_T(KC_N)
#define ALT_S LALT_T(KC_S)
#define SHFT_T LSFT_T(KC_T)
#define CTL_H LCTL_T(KC_H)

// Right-hand home row mods
#define CTL_A RCTL_T(KC_A)
#define SHFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_C RGUI_T(KC_C)

// Layer Triggers
#define TOREV DF(_ENGRAM)
#define TOSYM DF(_SYMBOLS)
#define TONUM DF(_NUMBERS)
#define INV_R LT(_ENGRAM, KC_R)
#define VIMVIS_V LT(_VIMVIS, KC_V)
#define NAV_P LT(_NAVIGATION, KC_P)
#define OSTICK OSL(_OSTICK)
#define OSMACRO OSL(_VIM)

#define OS_LG OSM(MOD_LGUI)

#define OS_RG OSM(MOD_RGUI)
#define OS_RS OSM(MOD_RSFT)

#define OS_RC OSM(MOD_RCTL)

#define OS_LA OSM(MOD_LALT)
#define OS_LAG OSM(MOD_LALT | MOD_LGUI)

#define OS_LS OSM(MOD_LSFT)
#define OS_LSA OSM( MOD_LSFT | MOD_LALT)
#define OS_LSG OSM( MOD_LSFT | MOD_LGUI)

#define OS_LC OSM(MOD_LCTL)
#define OS_LCA OSM(MOD_LCTL | MOD_LALT)
#define OS_LCAG OSM(MOD_LCTL | MOD_LALT | MOD_LGUI)
#define OS_LCG OSM(MOD_LCTL | MOD_LGUI)

#define OS_C_S_T OSM(MOD_LCTL | MOD_LSFT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define BACK TO(_ENGRAMM)
#define ___________ KC_LEAD



enum custom_keycodes {
  REPEAT = SAFE_RANGE,
  DOT_SPC,
  COMM_SPC,
  PICK,
  ALFRED,
  VIMHINT,
  QUES_SPC,
  LEADER,
  LINT,
  EXLM_SPC,
  SYMBOLS,
  VIMVIS_B,
  VIMVIS_E,
  OPENAPP,
  WIN
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _ENGRAMM
 +-----------+-----------+-----------+-----------+                                                                                   +-----------+-----------+-----------+-----------+
 |           |           |           |           |                                                                                   |           |           |           |           |
 |     v     |     w     |     d     |     l     |                                                                                   |     u     |     o     |     y     |     b     |
 |           |           |           |           |                                                                                   |           |           |           |           |
 |-----------+-----------+-----------+-----------|                                                                                   |-----------+-----------+-----------+-----------|
 |           |           |           |           |                                                                                   |           |           |           |           |
 |     n     |     s     |     t     |     h     |                               -шо там по русні?                              |     a     |     e     |     i     |     c     |
 |           |           |           |           |                                                                                   |           |           |           |           |
 |-----------+-----------+-----------+-----------|                                                                                   |-----------+-----------+-----------+-----------|
 |           |           |           |           |                                                                                   |           |           |           |           |
 |     p     |     f     |     m     |     r     |                                                                                   |     k     |     j     |     x     |     g     |
 |           |           |           |           |                                                                                   |           |           |           |           |
 +-----------+-----------+-----------+-----------+-----------+                                                           +-----------+-----------+-----------+-----------+-----------+
                                                 |           |                                                           |           |
                                                 |     n     |                                                           |     z     |
                                                 |           |                                                           |           |
                                                 +-----------+                                                           +-----------+
*/

 [_ENGRAMM] = LAYOUT_ortho_5x15(
     VIMVIS_V,       KC_W,       KC_D,       KC_L,___________,___________,___________,___________,___________,___________,___________,       KC_U,       KC_O,       KC_Y,       KC_B,
        GUI_N,      ALT_S,     SHFT_T,      CTL_H,___________,___________,___________,___________,___________,___________,___________,      CTL_A,     SHFT_E,      ALT_I,      GUI_C,
        NAV_P,       KC_F,       KC_M,      INV_R,___________,___________,___________,___________,___________,___________,___________,       KC_K,       KC_J,       KC_X,       KC_G,
  ___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,___________,     LEADER,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

 [_MENU] = LAYOUT_ortho_5x15(
       KC_ESC,       KC_Q,       KC_Z,     KC_TAB,___________,___________,___________,___________,___________,___________,___________,    KC_BTN1,    OPENAPP,     KC_GRV,       BACK,
      KC_BSPC,     KC_SPC,    DOT_SPC,      TOSYM,___________,___________,___________,___________,___________,___________,___________,    KC_COLN,   COMM_SPC,    KC_MINS,    KC_QUOT,
        TONUM,   KC_ENTER,   QUES_SPC,      TOREV,___________,___________,___________,___________,___________,___________,___________,    VIMHINT,   EXLM_SPC,       LINT,     ALFRED,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

[_NUMBERS] = LAYOUT_ortho_5x15(
  ___________,    KC_COMM,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     KC_DOT,     KC_DOT,       BACK,
         KC_9,       KC_5,       KC_0,       KC_3,___________,___________,___________,___________,___________,___________,___________,       KC_2,       KC_1,       KC_4,       KC_8,
      KC_MINS,    KC_TILD,___________,       KC_7,___________,___________,___________,___________,___________,___________,___________,       KC_6,___________,     KC_EQL,    KC_PLUS,
  ___________,___________,___________,___________,    SYMBOLS,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

[_OSTICK] = LAYOUT_ortho_5x15(
       OS_LSG,     OS_LSA,    OS_HYPR,   OS_C_S_T,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,       BACK,
        OS_LG,      OS_LA,      OS_LS,      OS_LC,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,
       OS_LCG,     OS_LAG,     OS_MEH,     OS_LCA,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

[_VIM] = LAYOUT_ortho_5x15(
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,       BACK,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

 [_VIMVIS] = LAYOUT_ortho_5x15(
  ___________,   VIMVIS_E,___________,   KC_RIGHT,___________,___________,___________,___________,___________,___________,___________,    QK_BOOT,___________,___________,   VIMVIS_B,
  ___________,___________,___________,    KC_LEFT,___________,___________,___________,___________,___________,___________,___________,___________,   VIMVIS_E,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,      KC_UP,    KC_DOWN,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

 [_NAVIGATION] = LAYOUT_ortho_5x15(
  ___________,___________,        WIN,   KC_RIGHT,___________,___________,___________,___________,___________,___________,___________,    QK_BOOT,___________,___________,       BACK,
  ___________,___________,___________,    KC_LEFT,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,      KC_UP,    KC_DOWN,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

  [_SYMBOLS] = LAYOUT_ortho_5x15(
      KC_PERC,    KC_LCBR,    KC_LPRN,    KC_LBRC,___________,___________,___________,___________,___________,___________,___________,    KC_RBRC,    KC_RPRN,    KC_RCBR,       BACK,
      KC_CIRC,    KC_UNDS,    KC_COLN,    KC_BSLS,___________,___________,___________,___________,___________,___________,___________,    KC_SLSH,    KC_SCLN,    KC_AMPR,     KC_DLR,
      KC_LABK,      KC_AT,    KC_QUOT,    KC_HASH,___________,___________,___________,___________,___________,___________,___________,    KC_ASTR,    KC_DQUO,    KC_PIPE,    KC_RABK,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________),

 [_ENGRAM] = LAYOUT_ortho_5x15(
         KC_B,       KC_Y,       KC_O,       KC_U,___________,___________,___________,___________,___________,___________,___________,       KC_L,       KC_D,       KC_W,       KC_V,
        GUI_C,      ALT_I,     SHFT_E,      CTL_A,___________,___________,___________,___________,___________,___________,___________,      CTL_H,     SHFT_T,      ALT_S,      GUI_N,
         KC_G,       KC_X,       KC_J,       KC_K,___________,___________,___________,___________,___________,___________,___________,       KC_R,       KC_M,       KC_F,       KC_P,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,     REPEAT,___________,___________,___________,___________,
  ___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________,___________)
 };


#ifdef REPEAT_KEY
// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
uint16_t pressed_keycode = KC_NO;
uint16_t prelast_keycode = KC_NO;
#endif

#ifdef REPEAT_KEY
void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
  if (keycode != REPEAT) {
    // Early return when holding down a pure layer key
    // to retain modifiers
    switch (keycode) {
      case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
      case QK_MOMENTARY ... QK_MOMENTARY_MAX:
      case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
      case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
      case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
      case QK_TO ... QK_TO_MAX:
      case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
      case QK_MODS ... QK_MODS_MAX:
      return;
    }
    if (record->event.pressed) {
      last_modifier = get_mods() | get_oneshot_mods();
      switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
          last_keycode = GET_TAP_KC(keycode);
          break;
        default:
          last_keycode = keycode;
          break;
      }
    }
  } 
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t hold_timer;
  #ifdef REPEAT_KEY
      process_repeat_key(keycode, record);
  #endif
  switch (keycode) {
    case KC_ESC:
      if (record->event.pressed) {
        if (is_macos) {
          // Enter normal mode in https://github.com/dbalatero/VimMode.spoon
          SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_9)))));
        }
      }
      return true;
    case LEADER:
      if (record->event.pressed) {
        hold_timer = timer_read();
        layer_move(_NUMBERS);
      }
      else {
        if (layer_state_is(_NUMBERS)) {
          layer_move(_ENGRAMM);
        }
        if (timer_elapsed(hold_timer) < 200) {
          qk_leader_start(); // 
        }
      }
      return false;
    case REPEAT:
      if (record->event.pressed) {
        prelast_keycode = last_keycode;
        hold_timer = timer_read();
        layer_move(_MENU);
      }
      else {
        if (layer_state_is(_MENU)) {
          layer_move(_ENGRAMM);
        } 
        if ((timer_elapsed(hold_timer) < 140)
          && (prelast_keycode == last_keycode)) {
          pressed_keycode = last_keycode;
          register_mods(last_modifier);
          register_code16(pressed_keycode);
          unregister_code16(pressed_keycode);
          unregister_mods(last_modifier);
        }
      }
      return false;
    case VIMVIS_E:
      if (record->event.pressed) {
        hold_timer = timer_read();
        register_code(KC_LALT);
        register_code(KC_RIGHT);
        unregister_code(KC_RIGHT);
        unregister_code(KC_LALT);
      }
      else {
        if (timer_elapsed(hold_timer) < 100) {
        }
      }
      return true;
    case VIMVIS_B:
      if (record->event.pressed) {
        hold_timer = timer_read();
        register_code(KC_LALT);
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
        unregister_code(KC_LALT);
      }
      else {
        if (timer_elapsed(hold_timer) < 100) {
        }
      }
      return true;
    case OPENAPP:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_LGUI(SS_TAP(X_A))))));
      }
      return false;
    case WIN:
      if (record->event.pressed) {
        if (is_macos) {
          is_macos = 0;
        }
        else {
          is_macos = 1;
        }
      }
      return false;
    case SYMBOLS:
      if (record->event.pressed) {
        hold_timer = timer_read();
        layer_move(_SYMBOLS);
      }
      else {
        if (layer_state_is(_SYMBOLS)) {
          layer_move(_ENGRAMM);
        }
        if (timer_elapsed(hold_timer < 100)) {
        }
      }
      return false;
    case DOT_SPC:  //
      if (record->event.pressed) {  // Key is being held.
        hold_timer = timer_read();
        SEND_STRING(".");
      }
      else {
        if (timer_elapsed(hold_timer) > 100) {
          SEND_STRING(" ");
          add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift
        }
      }
      return false;  // Continue default handling.
    case LINT:  
      register_code(KC_LCTL);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LCTL);
      wait_ms(800);
      register_code(KC_LCTL);
      register_code(KC_R);
      unregister_code(KC_R);
      unregister_code(KC_LCTL);
      wait_ms(800);
      register_code(KC_MS_BTN1);
      unregister_code(KC_MS_BTN1);
      return false;
    case EXLM_SPC:  //
      if (record->event.pressed) {  // Key is being held.
        hold_timer = timer_read();
        SEND_STRING("!");
      }
      else {
        if (timer_elapsed(hold_timer) > 100) {
          SEND_STRING(" ");
          add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.          
        }
      }
      return false;  // Continue default handling.
    case QUES_SPC:  //
      if (record->event.pressed) {  // Key is being held.
        hold_timer = timer_read();
        SEND_STRING("?");
      }
      else {
        if (timer_elapsed(hold_timer) > 100) {
          SEND_STRING(" ");
          add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.          
        }
      }
      return false;  // Continue default handling.
    case COMM_SPC:  //
      if (record->event.pressed) {  // Key is being held.
        hold_timer = timer_read();
        SEND_STRING(",");
      }
      else {
        if (timer_elapsed(hold_timer) > 100) {
          SEND_STRING(" ");  // Set one-shot mod for shift.          
        }
      }
      return false;  // Continue default handling.
    case PICK:  // Pick color in Photoshop
      if (record->event.pressed) {
        register_code(KC_LALT);
      }
      else {
        register_code(KC_BTN1);
        unregister_code(KC_BTN1);
        unregister_code(KC_LALT);
      }
      return false;
    case ALFRED:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_S);
        unregister_code(KC_S);
        unregister_code(KC_LGUI);
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(1);
      }
      return false;
    case VIMHINT:
      if (record->event.pressed) {
          tap_code16(HYPR(KC_SPC));
      }
      return false;
  }
  return true;
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_V) {
      //
    }
    SEQ_ONE_KEY(KC_W) {
      register_code(KC_LALT);

      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);

      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);

      register_code(KC_LEFT);
      unregister_code(KC_LEFT);

      unregister_code(KC_LALT);
    }
    SEQ_ONE_KEY(KC_D) {
      //
    }
    SEQ_THREE_KEYS(KC_D, KC_A, KC_W) {
      SEND_STRING(
        SS_LALT(SS_TAP(X_RIGHT))
        SS_LSFT(SS_LALT(SS_TAP(X_LEFT)))
        SS_TAP(X_BSPC)
      );
    }
    SEQ_ONE_KEY(KC_L) {
      SEND_STRING(SS_LCTL(SS_TAP(X_C))
        "[["
        SS_LCTL(SS_TAP(X_V))
        SS_DELAY(100)
        "]]"
      );
    }
    SEQ_ONE_KEY(KC_N) {
      //
    }
    SEQ_TWO_KEYS(KC_N, KC_L) {
      //
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_N))) SS_TAP(X_ENT));
    }
    SEQ_ONE_KEY(KC_S) {
      //
    }
    SEQ_ONE_KEY(KC_T) {
      //
    }
    SEQ_ONE_KEY(KC_H) {
      //
    }
    SEQ_ONE_KEY(KC_P) {
      //
      SEND_STRING(SS_LCTL(SS_TAP(X_V)));
    }
    SEQ_ONE_KEY(KC_F) {
      //
    }
    SEQ_ONE_KEY(KC_M) {
      //
    }
    SEQ_ONE_KEY(KC_R) {
      //
    }
    SEQ_ONE_KEY(KC_U) {
      // undo
      SEND_STRING(SS_LCTL(SS_TAP(X_Z)));
    }
    SEQ_ONE_KEY(KC_O) {
      //
      SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_LGUI(SS_TAP(X_O))))));
    }
    SEQ_ONE_KEY(KC_Y) {
      //
      SEND_STRING(SS_LCTL(SS_TAP(X_C)));
    }
    SEQ_ONE_KEY(KC_B) {
      // 
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
    }
    SEQ_ONE_KEY(KC_A) {
      //
    }
    SEQ_ONE_KEY(KC_E) {
      // 
      SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
    }
    SEQ_ONE_KEY(KC_I) {
      //
    }
    SEQ_ONE_KEY(KC_C) {
      //
    }
    SEQ_ONE_KEY(KC_K) {
      //
    }
    SEQ_ONE_KEY(KC_J) {
      //
    }
    SEQ_ONE_KEY(KC_X) {
      //
    }
    SEQ_ONE_KEY(KC_G) {
      //
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT))) {
      // 
        SEND_STRING(SS_LCTL(SS_TAP(X_DOWN)));
      }
      else {}
    }
    SEQ_TWO_KEYS(KC_G, KC_G) {
      //
      SEND_STRING(SS_LCTL(SS_TAP(X_UP)));
    }
    SEQ_TWO_KEYS(KC_LEAD, KC_M) {
      // 
      set_oneshot_layer(_MENU, ONESHOT_START);
      clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    SEQ_TWO_KEYS(KC_W, KC_W) {
      // obsidian jump next cursor
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_LALT);
      register_code(KC_W);
      unregister_code(KC_W);
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
    }
    SEQ_TWO_KEYS(KC_O, KC_O) {
      //
      SEND_STRING(SS_LCTL(" ") SS_DELAY(150));
      SEND_STRING("' Op" SS_DELAY(1000));
      SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_TWO_KEYS(KC_O, KC_T) {
      //
      SEND_STRING(SS_LCTL(" ") SS_DELAY(510));
      SEND_STRING("' Tel .app" SS_DELAY(1000));
      SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_TWO_KEYS(KC_O, KC_F) {
      //
      SEND_STRING(SS_LCTL(" ") SS_DELAY(150));
      SEND_STRING("' Fin .app" SS_DELAY(1000));
      SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_TWO_KEYS(KC_O, KC_P) {
      //
      SEND_STRING(SS_LCTL(" ") SS_DELAY(150));
      SEND_STRING("' Ph .app" SS_DELAY(1000));
      SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_TWO_KEYS(KC_O, KC_B) {
      //
      SEND_STRING(SS_LCTL(" ") SS_DELAY(150));
      SEND_STRING("' Ble .app" SS_DELAY(1000));
      SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) {
      // 
      SEND_STRING(SS_TAP(X_ENT));
    }
    SEQ_TWO_KEYS(KC_Q, KC_Q) {
      //
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_LALT)) SS_LSFT(SS_TAP(X_TAB) SS_TAP(X_LALT))));
    }
    SEQ_TWO_KEYS(KC_I, KC_E) {
      //
      SEND_STRING("oleksiiluchnikov@gmail.com");
    }
  }
};


void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (vimvis_status) {
      del_mods(MOD_MASK_SHIFT);
      }
    vimvis_status = false;
    switch (get_highest_layer(state)) {
      case _ENGRAMM:
          SEND_STRING(SS_TAP(X_F13));
          rgblight_sethsv_noeeprom(HSV_GREEN);
          rgblight_mode_noeeprom(1);
        break;
      case _ENGRAM:
          SEND_STRING(SS_TAP(X_F17));
          rgblight_sethsv_noeeprom(HSV_GREEN);
          rgblight_mode_noeeprom(1);
        break;
      case _MENU:
        SEND_STRING(SS_TAP(X_F16));
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(1);
        break;
      case _SYMBOLS:
        SEND_STRING(SS_TAP(X_F15));
        rgblight_sethsv_noeeprom(HSV_ORANGE);
        rgblight_mode_noeeprom(1);
        break;
      case _VIMVIS:
        SEND_STRING(SS_TAP(X_F19));
        vimvis_status = true;
        if (vimvis_status){
          add_mods(MOD_MASK_SHIFT);
          }
        break;
      case _NUMBERS:
        SEND_STRING(SS_TAP(X_F14));
        rgblight_sethsv_noeeprom(HSV_BLUE);
        rgblight_mode_noeeprom(1);
        SEND_STRING(SS_TAP(X_F14));
        break;
      case _VIM:
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        rgblight_mode_noeeprom(1);
        break;
      case _NAVIGATION:
        SEND_STRING(SS_TAP(X_F18));
        rgblight_sethsv_noeeprom(HSV_CYAN);
        rgblight_mode_noeeprom(1);
        break;
      default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(HSV_YELLOW);
        rgblight_mode_noeeprom(1);
        break;
    }
  return state;
}

