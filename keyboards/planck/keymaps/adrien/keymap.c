// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


// I don't think starting variable name with _ is good practice because
// of name mangling interference, so I renamed the layer with L_ prefix
enum planck_layers {
  L_QWERTY,
  L_0, // Number
  L_1, // Symbol
  L_2, // Parenthesis
  L_3, // Navigation / Media
  L_4, // C++/VIM/TMUX macro
  L_Lx, // Latex macro
  L_F, // F-keys
  L_Ms// Mouse
};

// Key for layer switch are labelled using KL_ prefix (KeyLayer)
// Key for Macro labelled with prefix:
// MC  = general text macro
// MCC = C++
// MCV = VIM
// MCT = TMUX
// MCL = Latex
enum planck_keycodes {
  KL_QWERTY = SAFE_RANGE,
  KL_BL,   // The BL Key
  MC_PAR,  // Parenthesis
  MC_CUR,  // Curly bracket
  MC_SQR,  // square bracket
  MCC_TYP, // C++ type <>
  MCC_FOR, // C++ for loop
  MCC_LIN, // C++ Line of / for separation of function
  MCC_NSP, // C++ namespace separator
  MC_QT1, // ""
  MC_QT2, // ''
  MC_QT3, // `'
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | KL0  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | KL0  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | KL1  | KL2  |Esc   |    Space    |ENT   | KL3  | KL4  |  OS  |BL    |
 * `-----------------------------------------------------------------------------------'
 */
[L_QWERTY] = {
  {KC_TAB ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC  },
  {MO(L_0),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  MO(L_0)  },
  {KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT  },
  {KC_LCTL,  KC_LALT, MO(L_1), MO(L_2), KC_ESC,  KC_SPC,  KC_SPC,  KC_ENT,  MO(L_3), MO(L_4), KC_LGUI,  KL_BL    }

},
/* Number and math symbol
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | KL0  |      |      |      |   !  |      |      |      |      |      |   ;  | KL0  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  +   |  -   |   *  |   =  |   <  |   >  |  %   |   ,  |   .  |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |      |      |Esc   |    Space    |ENT   |      |      |  OS  |      |
 * `-----------------------------------------------------------------------------------'
 */

[L_0] = {
  {KC_TAB ,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC   },
  {MO(L_0),  XXXXXXX, XXXXXXX, XXXXXXX, KC_EXLM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, MO(L_0)   },
  {XXXXXXX,  KC_PLUS, KC_MINS, KC_ASTR, KC_EQL,   KC_LABK, KC_RABK,  KC_PERC, KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX  },
  {KC_LCTL,  KC_LALT, XXXXXXX, XXXXXXX, KC_ESC,   KC_SPC,  KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX, KC_LGUI,  XXXXXXX  }

},
/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   <  |   >  |   :  |   ?  |      |      |      |      |   _  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  <>  |  <>  |   :: |      |      |      |      |   ,  |   .  |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  KL1 |      |Esc   |    Space    |ENT   |      |      |  OS  |      |
 * `-----------------------------------------------------------------------------------'
 */

[L_1] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {XXXXXXX, KC_LABK, KC_RABK, KC_COLN, KC_QUES, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_MINS, KC_PLUS, XXXXXXX},
  {XXXXXXX, MCC_TYP, MCC_TYP, MCC_NSP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX},
  {KC_LCTL,  KC_LALT, MO(L_1), XXXXXXX, KC_ESC, KC_SPC,  KC_SPC,  KC_ENT,   XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX}
},
 /* Parenthesis and bracket
 * ,-----------------------------------------------------------------------------------.
 * | tab  |   (  |   )  |   {  |   }  |   [  |   ]  |   "  |   '  |   `  |   |  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ()  |  ()  |  {}  |  {}  |  []  |  []  |  ""  |  ''  |  `'  |   \  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  <>  |  <>  |   :: |      |      |      |      |      |      |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  KL1 |      |Esc   |    Space    |ENT   |      |      |  OS  |      |
 * `-----------------------------------------------------------------------------------'
 */

[L_2] = {
  { KC_TAB, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,  KC_LBRC, KC_RBRC, KC_DQT,  KC_QUOT, KC_GRV,  KC_PIPE, KC_BSPC},
  {XXXXXXX, MC_PAR,  MC_PAR,  MC_CUR,  MC_CUR,   MC_SQR,  MC_SQR,  MC_QT1,  MC_QT2,  MC_QT3,  KC_BSLASH, XXXXXXX},
  {XXXXXXX, MCC_TYP, MCC_TYP, MCC_NSP, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, XXXXXXX},
  {KC_LCTL, KC_LALT, MO(L_1), XXXXXXX, KC_ESC,   KC_SPC,  KC_SPC,  KC_ENT,  XXXXXXX, XXXXXXX, KC_LGUI, XXXXXXX}
}


};
////////////////////////////////////////////////////////////////////////////////
#ifdef AUDIO_ENABLE
float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif
////////////////////////////////////////////////////////////////////////////////
void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
////////////////////////////////////////////////////////////////////////////////
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Macros //
    // Parenthesis
    case MC_PAR:
      send_string("()");
      send_word(KC_LEFT);
      return false;
      break;
    
    case MC_CUR:
      send_string("{}");
      send_word(KC_LEFT);
      return false;
      break;
    
    case MC_SQR:
      send_string("[]");
      send_word(KC_LEFT);
      return false;
      break;
    
    // C++
    case MCC_TYP:
      send_string("<>");
      send_word(KC_LEFT);
      return false;
      break;

    case MCC_FOR:
      send_string("for(unsigned int i = 0 ; i < size ; i++){}");
      send_word(KC_LEFT);
      return false;
      break;

    case MCC_LIN:
      send_string("////////////////////////////////////////////////////////////////////////////////");
      send_word(KC_ENT);
      return false;
      break;
    
    case MCC_NSP:
      send_string("::");
      return false;
      break;
  }
  return true;
}
////////////////////////////////////////////////////////////////////////////////
void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}
////////////////////////////////////////////////////////////////////////////////
#ifdef AUDIO_ENABLE
void startup_user(){
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}
////////////////////////////////////////////////////////////////////////////////
void shutdown_user(){
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}
////////////////////////////////////////////////////////////////////////////////
void music_on_user(void){
    music_scale_user();
}
////////////////////////////////////////////////////////////////////////////////
void music_scale_user(void){
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
