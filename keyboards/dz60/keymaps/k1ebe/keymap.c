#include QMK_KEYBOARD_H

#define _BASE 0
#define _SPACEBAR 1 // Hold Spacebar
#define _MENU 2 // Hold Menu key
#define	_CAPSLOCK 3 // Hold Caps Lock
#define	_UPARROW 4 // Tap key to the right of Right Shift

// Timers for tap detection in process_record_user
uint16_t lalt_timer;
uint16_t ralt_timer;

// create some custom keycodes for your keymap
enum custom_keycodes { 
  PREV_DESKTOP = SAFE_RANGE,
  NEXT_DESKTOP
};

// define some useful send stringsqmk flash ghfgh
#define SS_PREV_DESKTOP SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT)))
#define SS_NEXT_DESKTOP SS_LCTRL(SS_LGUI(SS_TAP(X_RIGHT)))

//Tap Dance Declarations
enum {
  TD_PGUP_HOME = 0,
  TD_PGDN_END
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Page up, twice for Home
  [TD_PGUP_HOME]  = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
  [TD_PGDN_END] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_60_ansi_split_space_rshift(
	KC_ESC, 	KC_1, 		KC_2, 			KC_3, 			KC_4, 			KC_5, 			KC_6, 			KC_7, 			KC_8, 			KC_9, 			KC_0, 		KC_MINS, 		KC_EQL, 	KC_BSPC, \
	KC_TAB, 	KC_Q, 		KC_W, 			KC_E, 			KC_R, 			KC_T, 			KC_Y, 			KC_U, 			KC_I, 			KC_O, 			KC_P, 		KC_LBRC, 		KC_RBRC, 	KC_BSLS, \
	LT(3, KC_BSPC), 		KC_A, 		KC_S, 			KC_D, 			KC_F, 			KC_G, 			KC_H, 			KC_J, 			KC_K, 			KC_L, 			KC_SCLN, 	KC_QUOT, 					KC_ENT, \
	KC_LSFT, 	KC_Z, 		KC_X, 			KC_C, 			KC_V, 			KC_B, 			KC_N, 			KC_M, 			KC_COMM, 		KC_DOT, 		KC_SLSH, 	RSFT_T(KC_UP), 				TT(4), \
	KC_LCTL, 	KC_LGUI, 	PREV_DESKTOP, 	LT(1,KC_SPC), 	LT(1,KC_SPC), 	LT(1,KC_SPC), 														NEXT_DESKTOP, 		KC_LEFT, 	LT(2,KC_DOWN), 	RCTL_T(KC_RGHT)),
	
	[_SPACEBAR] = LAYOUT_60_ansi_split_space_rshift(
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 	_______, 		_______, 	KC_BSPC, \
	TD(TD_PGUP_HOME), 	KC_F1, 		KC_F2, 			KC_F3, 			KC_F4, 			_______, 		_______, 		XXXXXXX, 		XXXXXXX, 			KC_7, 			KC_8, 		KC_9, 		XXXXXXX, 	XXXXXXX, \
	TD(TD_PGDN_END), 	KC_F5, 		KC_F6, 			KC_F7, 			KC_F8, 			_______, 		_______, 		XXXXXXX, 		XXXXXXX, 			KC_4, 			KC_5, 		KC_6, 					_______, \
	_______, 	KC_F9, 		KC_F10, 		KC_F11, 		KC_F12, 		_______, 		_______, 		XXXXXXX, 		KC_1, 			KC_2, 			KC_3, 		_______, 					_______, \
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 																KC_0, 				_______, 		_______, 	_______),
		
	[_MENU] = LAYOUT_60_ansi_split_space_rshift(
	RESET, 	 KC_F1, 		KC_F2, 			KC_F3, 			KC_F4, 			KC_F5, 			KC_F6, 			KC_F7, 			KC_F8, 			KC_F9, 			KC_F10, 	KC_F11, 		KC_F12, 	KC_DEL, \
	_______, 	RGB_TOG, 	RGB_MOD, 		RGB_RMOD, 	RGB_HUI, 		RGB_HUD, 		RGB_SAI, 		RGB_SAD, 		RGB_VAI, 		RGB_VAD, 		KC_PSCR, 	KC_SLCK, 		KC_PAUS, 	_______, \
	_______, 	RGB_M_P, 	RGB_M_B, 		RGB_M_R, 		RGB_M_SW, 		RGB_M_SN, 		RGB_M_K, 		RGB_M_X, 		_______, 		KC_INS, 		KC_HOME, 	KC_PGUP, 					_______, \
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		KC_DEL, 		KC_END, 		KC_PGDN, 	_______, 					_______, \
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 																		_______, 	_______, 		_______, 	_______),

	[_CAPSLOCK] = LAYOUT_60_ansi_split_space_rshift(
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 	_______, 		_______, 	KC_DEL, \
	_______, 	KC_MPLY, 	KC_VOLD, 		KC_VOLU, 		KC_MSTP, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 	_______, 		_______, 	XXXXXXX, \
	_______, 	_______, 	KC_MUTE, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		KC_HOME, 	KC_PGUP, 					_______, \
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		_______, 		KC_END, 		KC_PGDN, 	_______, 					_______, \
	_______, 	_______, 	_______, 		_______, 		_______, 		_______, 																		_______, 	_______, 		_______, 	_______),
	
	[_UPARROW] = LAYOUT_60_ansi_split_space_rshift(
	KC_ESC,   KC_1,     KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,     KC_MINS,    KC_EQL,   KC_BSPC, \
  KC_TAB,    KC_Q,     KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS, \
  LT(3, KC_BSPC),     KC_A,     KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,        KC_SCLN,    KC_QUOT,  KC_ENT, \
  KC_LSFT,  KC_Z,     KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,  RSFT_T(KC_UP),        TT(0), \
  KC_LCTL,  KC_LGUI,  PREV_DESKTOP,   KC_SPC,   KC_SPC,   KC_SPC,                             NEXT_DESKTOP,     KC_LEFT,  LT(2,KC_DOWN),  RCTL_T(KC_RGHT)),
};

// Code to make the ALT keys change virtual desktops in windows.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
  case PREV_DESKTOP:
    if (record->event.pressed) {
      // Activate LALT
      lalt_timer = timer_read();
      SEND_STRING(SS_DOWN(X_LALT));
    } else {
      // Deactivate LALT
      SEND_STRING(SS_UP(X_LALT));
      // If the action was a tap
      if (timer_elapsed(lalt_timer) < TAPPING_TERM) {
	    SEND_STRING(SS_PREV_DESKTOP);
      }
    }
    return false;

  case NEXT_DESKTOP:
    if (record->event.pressed) {
      // Activate RALT
      ralt_timer = timer_read();
      SEND_STRING(SS_DOWN(X_RALT));
    } else {
      // Deactivate RALT
      SEND_STRING(SS_UP(X_RALT));
      // If the action was a tap
      if (timer_elapsed(ralt_timer) < TAPPING_TERM) {
	    SEND_STRING(SS_NEXT_DESKTOP);
      }
    }
    return false;
  }
  return true;
};

// Only enables auto shift on base layer
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
      case _BASE:
          autoshift_enable();
          break;
      default:
          autoshift_disable();
          break;
      }
  return state;
}