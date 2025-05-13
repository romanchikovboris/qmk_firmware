/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"
#include "keymap_russian.h" 
// #include "rgblight.h"


#define ERROR_SOUND HD_NOTE(_C8), HD_NOTE(_D3), HD_NOTE(_C6)

enum layers {
    BASE,   
    RU,   
    GAME,
    MACR1,
    MACR2,
    MACR3,
    SYMB
};

enum custom_keycodes { 
    LNG = CUSTOM_SAFE_RANGE,
    DLR_DQT,
    SPROP,
    BUTTON,
    CLC_LSN,
    ACTION,
    LABEL,
    DOT_QUE,
    SAVE,
    ENULL,
    NENULL,
    RET,
    TGM, 
    MEQU,
    PEQU, 
    EQUM, 
    SER,
    IFN,
    RENAME
};

uint8_t state_cache;

float layer1_song[][2] = SONG(COLEMAK_SOUND);
float error_sound[][2] = SONG(ERROR_SOUND);
float save_sound[][2] = SONG(QWERTY_SOUND);


// const ComboWithKeycode combos[] PROGMEM = {
  // Left Index
  // CHORD(KC_LCMD,          CMB_000),
  // CHORD(MO(MACRO),        CMB_000, CMB_001),
  // CHORD(LCTL(KC_BSPC),    CMB_000, CMB_002),
  // CHORD(LCMD(KC_DEL),     CMB_000, CMB_001, CMB_002),
  // CHORD(KC_SPC,           CMB_001),
  // CHORD(KC_DEL,           CMB_001, CMB_002),
  // CHORD(KC_BSPC,          CMB_002),
  // CHORD(KC_LSFT,          CMB_002, CMB_003),
  // CHORD(KC_LSFT,          CMB_002, CMB_017),//CMB_002, CMB_003
  // CHORD(KC_DOT,           CMB_003),
  // CHORD(KC_ENTER,         CMB_004),
  // CHORD(KC_CAPSLOCK,      CMB_004, CMB_006),
  // CHORD(MO(MACRO),        CMB_004, CMB_007),
  // CHORD(KC_LGUI,          CMB_004, CMB_006, CMB_007),
  // CHORD(LNG,              CMB_005),
  // CHORD(LALT(KC_LSFT),    CMB_005, CMB_006),
  // CHORD(KC_LALT,          CMB_006),
  // CHORD(LALT(KC_ENTER),   CMB_006, CMB_007),
  // CHORD(KC_RSFT,          CMB_007),
  // CHORD(LCMD(KC_W),       CMB_008),
  // CHORD(TGM,              CMB_008, CMB_009),
  // CHORD(LCMD(KC_F),       CMB_009),
  // CHORD(LCMD(LSFT(KC_B)), CMB_009, CMB_010),
  // CHORD(LALT(KC_ENTER),   CMB_010),
  // CHORD(KC_TAB,           CMB_011),
  // CHORD(LCMD(KC_A),       CMB_011, CMB_012),
  // CHORD(LCMD(KC_Z),       CMB_012),
  // CHORD(LCMD(KC_X),       CMB_012, CMB_013),
  // CHORD(LCMD(KC_C),       CMB_013),
  // CHORD(LCMD(KC_D),       CMB_013, CMB_014),
  // CHORD(LCMD(KC_V),       CMB_014),
  // CHORD(KC_SCLN,          CMB_015),
  // CHORD(DLR_DQT,          CMB_015, CMB_016),
  // CHORD(KC_DQT,           CMB_016),
  // CHORD(PEQU,             CMB_016, CMB_025),
  // CHORD(KC_SLSH,          CMB_017),//CMB_003
  // CHORD(SGUI(KC_S),       CMB_018),
  // CHORD(DOT_QUE,          CMB_018, CMB_019),
  // CHORD(LSFT(KC_SLSH),    CMB_019),
  // CHORD(LSFT(KC_F6),      CMB_020),
  // CHORD(ENULL,            CMB_021),
  // CHORD(NENULL,           CMB_021, CMB_022),
  // CHORD(KC_NO,            CMB_022),
  // CHORD(KC_B,             CMB_023),
  // CHORD(TGM,              CMB_023, CMB_024),
  // CHORD(KC_T,             CMB_024),
  // CHORD(KC_EQL,           CMB_025),
  // CHORD(MEQU,             CMB_025, CMB_026),
  // CHORD(EQUM,             CMB_025, CMB_027),
  // CHORD(LSFT(KC_MINS),    CMB_026),
  // CHORD(KC_QUOTE,         CMB_027),
  // CHORD(KC_LBRC,          CMB_028),
  // CHORD(SER,              CMB_028, CMB_029),
  // CHORD(KC_RBRC,          CMB_029),
  // CHORD(MO(SYMB),         CMB_030),
  // CHORD(MO(SYMB),         CMB_031),
  // CHORD(SAVE,             CMB_030, CMB_031),
// };  

// const uint8_t combos_size = sizeof(combos)/sizeof(ComboWithKeycode);
  
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_moonlander(
        KC_ESC,             KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,           LCMD(KC_W),                         LCMD(LSFT(KC_B)),  KC_CIRC,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RPRN,              LCA(KC_DEL),
        KC_TAB,             KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              LCMD(KC_F),                         LSFT(KC_SLSH),     KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_BSLS,
        MO(MACR1),          KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              LALT(KC_ENTER),                     _______,           KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN,              KC_DQT,
        MO(MACR2),          KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,                                                                     KC_N,              KC_M,              KC_COMM,           KC_COMM,           KC_QUOTE,             KC_EQL,
        MO(MACR3),          KC_LCTL,           KC_LALT,           KC_DOT,            MO(SYMB),                             KC_LCMD,                            KC_ENTER,                             MO(SYMB),          KC_GRV,            KC_COMM,           LALT(KC_LSFT),        LSFT(KC_MINS),
                                                                                     KC_SPC,            KC_BSPC,           KC_LSFT,                            LNG,               _______,           KC_LSFT 
    ),

	[RU] = LAYOUT_moonlander(
        _______,            _______,           _______,           _______,           _______,           _______,           _______,                            _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,            RU_SHTI,           RU_TSE,            RU_U,              RU_KA,             RU_IE,             _______,                            LSFT(KC_7),        RU_EN,             RU_GHE,            RU_SHA,            RU_SHCH,           RU_ZE,                RU_HA,
        _______,            RU_EF,             RU_YERU,           RU_VE,             RU_A,              RU_PE,             _______,                            _______,           RU_ER,             RU_O,              RU_EL,             RU_DE,             RU_ZHE,               RU_E,
        _______,            RU_YA,             RU_CHE,            RU_ES,             RU_EM,             RU_I,                                                                     RU_TE,             RU_SOFT,           RU_BE,             RU_YU,             RU_HARD,              RU_YO,
        _______,            _______,           _______,           KC_SLSH,           _______,                              _______,                            _______,                              _______,           _______,           LSFT(KC_SLSH),     _______,              _______,
                                                                                     _______,           _______,           KC_SLSH,                            _______,           _______,           _______
    ),

    [GAME] = LAYOUT_moonlander(
        _______,            _______,           _______,           _______,           _______,           _______,           KC_B,                               _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,            KC_TAB,            KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                               _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,            KC_LSFT,           KC_A,              KC_S,              KC_D,              KC_F,              KC_G,                               _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,            KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_V,                                                                     _______,           _______,           _______,           _______,           _______,              _______,
        _______,            KC_LALT,           _______,           _______,           _______,                              _______,                            _______,                              _______,           _______,           _______,           _______,              _______,
                                                                                     _______,           _______,           _______,                            _______,           _______,           _______
    ), 

    [MACR1] = LAYOUT_moonlander(
        RESET,               _______,          _______,           _______,           _______,           _______,           _______,                            _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,           LCMD(KC_UP),       RENAME,            _______,           _______,                            _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          LCMD(KC_LEFT),     LCMD(KC_DOWN),     LCMD(KC_RGHT),     _______,           LALT(LCTL(KC_N)),                   _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,           _______,           _______,           LCMD(KC_X),                                                               _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,           LCMD(KC_A),        LCMD(KC_D),                           SAVE,                               _______,                              _______,           _______,           _______,           _______,              _______,
                                                                                     LCMD(KC_C),        LCMD(KC_V),        LCMD(KC_Z),                         _______,           _______,           _______
    ),


    [MACR2] = LAYOUT_moonlander(
        _______,             _______,          _______,             _______,              _______,             _______,       _______,                         _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,             LCTL(LSFT(KC_UP)),    _______,             _______,       _______,                         _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          LCTL(LSFT(KC_LEFT)), LCTL(LSFT(KC_DOWN)),  LCTL(LSFT(KC_RGHT)), _______,       _______,                         _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,             _______,              _______,             _______,                                                           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,             _______,              _______,                            KC_ENTER,                        _______,                              _______,           _______,           _______,           _______,              _______,
                                                                                          _______,             KC_DEL,        _______,                         _______,           _______,           _______
    ),

    [MACR3] = LAYOUT_moonlander(
        _______,             _______,          _______,           _______,           _______,                  _______,                TGM,                    _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,           LALT(LSFT(KC_F12)),_______,                  LCMD(LALT(LSFT(KC_T))), _______,                _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          _______,           LALT(KC_F12),      _______,                  _______,                _______,                _______,           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          LCMD(LALT(KC_Q)),  LCMD(LALT(KC_V)),  LCMD(LALT(LSFT(KC_D))),   _______,                                                           _______,           _______,           _______,           _______,           _______,              _______,
        _______,             _______,          LCMD(LALT(KC_I)),  LCMD(LALT(KC_G)),  LCMD(LALT(KC_M)),                                 _______,                _______,                              _______,           _______,           _______,           _______,              _______,
                                                                                     _______,           LCMD(KC_DEL),                  _______,                _______,           _______,           _______
    ),

    [SYMB] = LAYOUT_moonlander(
        _______,             KC_F1,            KC_F2,             KC_F3,             KC_F4,             KC_F5,             KC_F6,                              KC_F7,             KC_F8,             KC_F9,             KC_F10,            KC_F11,            KC_F12,               _______,
        _______,             KC_LBRC,          KC_RBRC,           KC_UP,             KC_LPRN,           KC_RPRN,           _______,                            _______,           _______,           KC_1,              KC_2,              KC_3,              _______,              _______,
        KC_SLSH,             KC_LCMD,          KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_MINS,           _______,                            _______,           _______,           KC_4,              KC_5,              KC_6,              KC_LCTL,              _______,
        _______,             LSFT(KC_LBRC),    LSFT(KC_RBRC),     LSFT(KC_COMM),     LSFT(KC_DOT),      LSFT(KC_EQL),                                                             _______,           KC_7,              KC_8,              KC_9,              _______,              _______,
        _______,             _______,          _______,           _______,           _______,                              _______,                            _______,                              _______,           KC_0,              _______,           _______,              _______,
                                                                                     _______,           _______,           _______,                            _______,           _______,           _______
    ),


    // [RU] = LAYOUT_moonlander(
    //     _______,         _______,           _______,           _______,           _______,           _______,           _______,                            _______,           _______,           _______,           _______,           _______,           _______,              _______,
    //     _______,         _______,           _______,           _______,           _______,           _______,           _______,                            _______,           _______,           _______,           _______,           _______,           _______,              _______,
    //     _______,         _______,           _______,           _______,           _______,           _______,           _______,                            _______,           _______,           _______,           _______,           _______,           _______,              _______,
    //     _______,         _______,           _______,           _______,           _______,           _______,                                                                  _______,           _______,           _______,           _______,           _______,              _______,
    //     _______,         _______,           _______,           _______,           _______,                              _______,                            _______,                              _______,           _______,           _______,           _______,              _______,
    //                                                                               _______,           _______,           _______,                            _______,           _______,           _______
    // ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// if (!combo_process_record(keycode, record))
    // 	return false;
    if (record->event.pressed) {
        switch (keycode) 
        { 
	        case LNG:
		        if (record->event.pressed) {// down
		        //	register_code(KC_LALT);
		        //	register_code(KC_LSHIFT); 
		        //  unregister_code(KC_LSHIFT);
		        //	unregister_code(KC_LALT); 
		        //	layer_invert(RU);
                    register_code(KC_LCMD);
                    register_code(KC_SPACE); 
                    unregister_code(KC_SPACE);
                    unregister_code(KC_LCMD); 
                    layer_invert(RU);
		        } else {//  up
		        }
          break; 
          case TGM:
            if (record->event.pressed) {
              layer_invert(GAME);
            } else {//  up
            }
	        break; 
          case DLR_DQT:// $"
            if (record->event.pressed) {
              register_code(KC_LSFT);
              tap_code(KC_4);
              tap_code(KC_QUOT); 
              unregister_code(KC_LSFT);
            } else {//  up
            }
          break; 
          case SPROP:// sprop
            if (record->event.pressed) {
              tap_code(KC_S);
              tap_code(KC_P);
              tap_code(KC_R);
              tap_code(KC_O);
              tap_code(KC_P);
              tap_code(KC_TAB);
            } else {//  up
            }
          break;
          case BUTTON:// button
            if (record->event.pressed) {
              tap_code(KC_B);
              tap_code(KC_U);
              tap_code(KC_T);
              tap_code(KC_T);
              tap_code(KC_O);
              tap_code(KC_N);
              tap_code(KC_TAB);
            } else {//  up
            }
          break;
          case CLC_LSN:// clickListener
            if (record->event.pressed) {
              tap_code(KC_C);
              tap_code(KC_L);
              tap_code(KC_I);
              tap_code(KC_C);
              tap_code(KC_K);
              register_code(KC_LSFT);
              tap_code(KC_L);
              unregister_code(KC_LSFT);
              tap_code(KC_I);
              tap_code(KC_S);
              tap_code(KC_T);
              tap_code(KC_E);
              tap_code(KC_N);
              tap_code(KC_E);
              tap_code(KC_R);
              tap_code(KC_TAB);
            } else {//  up
            } 
          break;  
          case ACTION://action
            if (record->event.pressed) {
              tap_code(KC_A);
              tap_code(KC_C);
              tap_code(KC_T);
              tap_code(KC_I);
              tap_code(KC_O);
              tap_code(KC_N);
              tap_code(KC_TAB);
            } else {//  up
            }
          break; 
          case LABEL://label
            if (record->event.pressed) {
              tap_code(KC_L);
              tap_code(KC_A);
              tap_code(KC_B);
              tap_code(KC_E);
              tap_code(KC_L);
              tap_code(KC_TAB);
            } else {//  up
            }
          break; 
          case DOT_QUE:
            if (record->event.pressed) {
              SEND_STRING("?.Invoke();");
              tap_code(KC_LEFT);
              tap_code(KC_LEFT);
            } else {//  up
            }
          break;
          case SAVE:
            if (record->event.pressed) {
              register_code(KC_LCMD);
              tap_code(KC_S);
              unregister_code(KC_LCMD);
              PLAY_SONG(save_sound);
            } else {//  up
            }
          break;  
          case ENULL:
            if (record->event.pressed) {
              SEND_STRING(" == null");
            } else {//  up
            }
          break;  
          case NENULL:
            if (record->event.pressed) {
              SEND_STRING(" != null");
            } else {//  up
            }
          break;  
          case RET:
            if (record->event.pressed) {
              SEND_STRING("return;");
            } else {//  up
            }
          break; 
          case MEQU:
            if (record->event.pressed) {
              SEND_STRING(" -= ");
            } else {//  up
            }
          break;  
          case PEQU:
            if (record->event.pressed) {
              SEND_STRING(" += ");
            } else {//  up
            }
          break; 
          case EQUM:
            if (record->event.pressed) {
              SEND_STRING(" => ");
            } else {//  up
            }
          break; 
          case SER:
            if (record->event.pressed) {
              SEND_STRING("[SerializeField] ");
            } else {//  up
            }
          break;
          case IFN:
            if (record->event.pressed) {
              SEND_STRING("ifn");
              tap_code(KC_TAB);
            } else {//  up
            }
          break; 
          case RENAME:
            if (record->event.pressed) {
              register_code(KC_LCMD);
              tap_code(KC_R);
              tap_code(KC_R);
              unregister_code(KC_LCMD);
            } else {//  up
            }
          break; 
	    }

    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	state_cache = biton32(state);  
	switch (state_cache) 
    {
	    case BASE:  
    	break;
	    case RU:  
    	break;
	    case SYMB:  
    	break;
	    case MACR1:  
    	break;
        case MACR2:  
        break;
        case MACR3:  
        break;
	}
	return state;
}


bool rgb_matrix_indicators_user()
{
    switch (state_cache) 
    {
	    case BASE:  
		    rgb_matrix_set_color_all(RGB_GREEN);
    	break;
	    case RU:  
		    rgb_matrix_set_color_all(RGB_CYAN); 
    	break;
	    case SYMB:  
		    rgb_matrix_set_color_all(RGB_PURPLE);
    	break;
	    case MACR1:  
		    rgb_matrix_set_color_all(RGB_RED);
    	break;
        case MACR2:  
            rgb_matrix_set_color_all(RGB_WHITE);
        break;
        case MACR3:  
            rgb_matrix_set_color_all(RGB_YELLOW);
        break;
	}
    return true;
}

// void user_timer(void) {
//   	combo_user_timer();
// }

// void matrix_scan_user(void) {
//   	user_timer();
// }

// void combo_max_count_error(void) {
// 	PLAY_SONG(layer1_song);
// }

// void combo_max_size_error(void) {
// 	PLAY_SONG(layer1_song);
// }

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
//     return state;
// }
 
// void eeconfig_init_user(void) {  // EEPROM is getting reset!
//   // use the non noeeprom versions, to write these values to EEPROM too
//   rgblight_enable(); // Enable RGB by default
//   rgblight_sethsv_white();  // Set it to white by default
//   rgblight_mode(RGBLIGHT_MODE_BREATHING); // set to breathing by default
// }

// layer_state_t layer_state_set_user(layer_state_t state) { 
//    	//rgblight_set_layer_state(biton32(state));
// 	return state;
// }b


