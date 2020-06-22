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
  VDNVUP_MUTE,
  PBKS_aa //P+Backspace 
  };

const uint16_t PROGMEM MU_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM pbks_combo[] = {KC_P, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [VDNVUP_MUTE] = COMBO(MU_combo, KC_MUTE),
  [PBKS_aa] = COMBO(pbks_combo, KC_LBRC)
};

// Timers for tap detection in process_record_user
uint16_t lsft_timer;
uint16_t lctl_timer;

// create some custom keycodes for your keymap
enum custom_keycodes {
  P_DESK = SAFE_RANGE,
  N_DESK
};

// define some useful send strings
#define SS_P_DESK SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT)))
#define SS_N_DESK SS_LCTRL(SS_LGUI(SS_TAP(X_RIGHT)))

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
    P_DESK,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, KC_ENT ,
    N_DESK,  KC_LEAD, KC_LGUI, KC_LALT, LOWER,   LT(_SPACE,KC_SPC), LT(_SPACE,KC_SPC), RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),


/* Space
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F13 |  F14 |  F15 |   7  |   8  |   9  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  F16 |  F17 |  F18 |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  F19 |  F20 |  F21 |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |   0  |   ,  |   ,  |   ,  |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F13,  KC_F14,  KC_F15,  KC_7, KC_8,    KC_9,    _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F16,  KC_F17,  KC_F18,  KC_4, KC_5,    KC_6,    XXXXXXX,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F19,  KC_F20,  KC_F21,  KC_1, KC_2,    KC_3,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_COMM, KC_COMM, KC_COMM
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
    KC_DEL,  _______, _______, _______, _______, _______, _______, _______, LCA(KC_EQL), NO_BSLS, NO_DIAE, NO_QUOT,
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
          SEND_STRING(",ok");
        }

        SEQ_ONE_KEY(KC_T) {
          register_code(KC_LCTL);
          register_code(KC_F24);
          unregister_code(KC_F24);
          unregister_code(KC_LCTL);
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

      SEQ_TWO_KEYS(KC_T, KC_W) {
          register_code(KC_LSFT);
          register_code(KC_F24);
          unregister_code(KC_F24);
          unregister_code(KC_LSFT);
        }

        SEQ_TWO_KEYS(KC_T, KC_C) {
          register_code(KC_LALT);
          register_code(KC_F24);
          unregister_code(KC_F24);
          unregister_code(KC_LALT);
        }

        SEQ_TWO_KEYS(KC_T, KC_T) {
          register_code(KC_LSFT);
          register_code(KC_LCTL);
          register_code(KC_F24);
          unregister_code(KC_F24);
          unregister_code(KC_LCTL);
          unregister_code(KC_LSFT);
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
  case P_DESK:
    if (record->event.pressed) {
      // Activate LSHIFT
      lsft_timer = timer_read();
      SEND_STRING(SS_DOWN(X_LSFT));
    } else {
      // Deactivate LSHIFT
      SEND_STRING(SS_UP(X_LSFT));
      // If the action was a tap
      if (timer_elapsed(lsft_timer) < TAPPING_TERM) {
      SEND_STRING(SS_P_DESK);
      }
    }
    return false;

  case N_DESK:
    if (record->event.pressed) {
      // Activate LALT
      lctl_timer = timer_read();
      SEND_STRING(SS_DOWN(X_LCTL));
    } else {
      // Deactivate LALT
      SEND_STRING(SS_UP(X_LCTL));
      // If the action was a tap
      if (timer_elapsed(lctl_timer) < TAPPING_TERM) {
      SEND_STRING(SS_N_DESK);
      }
    }
    return false;
  }
  return true;
}