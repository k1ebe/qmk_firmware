/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_norwegian.h"
#include "sendstring_norwegian.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPACE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum combos {
  TABQ_1,
  QW_2,
  WE_3,
  ER_4,
  RT_5,
  TY_6,
  YU_7,
  UI_8,
  IO_9,
  OP_0,
  PBKS_aa //P+Backspace
  };

const uint16_t PROGMEM tabq_combo[] = {KC_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM QW_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM WE_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM ER_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM RT_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM TY_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM YU_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM UI_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM IO_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM OP_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM pbks_combo[] = {KC_P, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [TABQ_1] = COMBO(tabq_combo, KC_1),
  [QW_2] = COMBO(QW_combo, KC_2),
  [WE_3] = COMBO(WE_combo, KC_3),
  [ER_4] = COMBO(ER_combo, KC_4),
  [RT_5] = COMBO(RT_combo, KC_5),
  [TY_6] = COMBO(TY_combo, KC_6),
  [YU_7] = COMBO(YU_combo, KC_7),
  [UI_8] = COMBO(UI_combo, KC_8),
  [IO_9] = COMBO(IO_combo, KC_9),
  [OP_0] = COMBO(OP_combo, KC_0),
  [PBKS_aa] = COMBO(pbks_combo, KC_LBRC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ø  |  Æ   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Leader| Gui  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSTR, NO_AE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, KC_ENT ,
    KC_LCTL, KC_LEAD, KC_LGUI, KC_LALT, LOWER,   LT(_SPACE,KC_SPC), LT(_SPACE,KC_SPC), RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),


/* Space
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F13 |  F14 |  F15 |   7  |   8  |   9  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  F16 |  F17 |  F18 |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  F19 |  F20 |  F21 |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |   0  |   ,  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  KC_F14,  KC_F15,  KC_7, KC_8,    KC_9,    _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F16,  KC_F17,  KC_F18,  KC_4, KC_5,    KC_6,    XXXXXXX,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F19,  KC_F20,  KC_F21,  KC_1, KC_2,    KC_3,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_COMM, XXXXXXX, XXXXXXX
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   @  |   !  |   "  |   #  |   ¤  |   %  |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |      |   `  |   +  |   ?  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   <  |   >  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    NO_AT,   NO_EXLM, NO_DQUO, NO_HASH, NO_CURR, NO_PERC, NO_AMPR, NO_SLSH, NO_LPRN,   NO_RPRN, NO_EQL,  KC_BSPC,
    KC_DEL,  _______, _______, _______, _______, _______, _______, _______, S(KC_EQL), NO_PLUS, NO_QUES, NO_ASTR,
    _______, _______, _______, _______, _______, _______, _______, NO_LABK, NO_RABK,   NO_LBRC, NO_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT,   KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   |  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |      |   '  |   \  |   "  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | End  |Pg Dn |Pg Up | Home |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    NO_PIPE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,        KC_9,    KC_0,    KC_DEL,
    KC_DEL,  _______, _______, _______, _______, _______, _______, _______, LCA(KC_EQL), NO_BSLS, NO_DIAE, NO_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,     NO_LCBR, NO_RCBR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_END,      KC_PGDN, KC_PGUP, KC_HOME
),


/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |TglCom|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______,  _______, CMB_TOG,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}*/

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

// Single key sequences

        SEQ_ONE_KEY(KC_F) { 
          SEND_STRING("QMK is awesome.");
        }

        SEQ_ONE_KEY(KC_A) {
          SEND_STRING(",ok ");
        }

// Double key sequences

      SEQ_TWO_KEYS(KC_A, KC_A) {  
        SEND_STRING("()");
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
      }  

      SEQ_TWO_KEYS(KC_S, KC_S) {  
        SEND_STRING("[]");
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
      }

       SEQ_TWO_KEYS(KC_D, KC_D) {  
        SEND_STRING("{}");
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
      }

    }    
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
