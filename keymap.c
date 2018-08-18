#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "quantum.h"

/* Layers */
enum  {
  BASE = 0,
  SYMB,
  NUMP,
  OVERWATCH,
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
};

// Enable leader support.
LEADER_EXTERNS();

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Glyphs: http://graphemica.com/
/* Keymap 0: Base Layer
 *
 * ,------------------------------------------------------.           ,-------------------------------------------------------.
 * | Escape    |  1   |  2   |  3   |   4   |   5  | !    |           |  =   |   6  |   7  |   8  |   9   |   0   |    _      |
 * |-----------+------+------+------+-------+-------------|           |------+------+------+------+-------+-------+-----------|
 * |      /    |   Q  |   W  |   E  |   R   |   T  |      |           |      |   Y  |   U  |   I  |   O   |   P   |    ~      |
 * |-----------+------+------+------+-------+------|   *  |           |  +   |------+------+------+-------+-------+-----------|
 * |    Tab    |   A  |   S  |   D  |   F   |   G  |------|           |------|   H  |   J  |   K  |   L   | TO(1) |    "      |
 * |-----------+------+------+------+-------+------|      |           |      |------+------+------+-------+-------+-----------|
 * | OSM(SHIFT)|   Z  |   X  |   C  |   V   |   B  |  /   |           |   -  |   N  |   M  |   .  |   ,   | TO(2) |    '      |
 * `-----------+------+------+------+-------+-------------'           `-------------+------+------+-------+-------+-----------'
 *     | CTRL  | ⇧⌘  |  ⇧⎇  |  ⎇  |OSM(⌘)|                                       |  Esc | Ctrl |⇧(Ctrl) | LEAD |   ⌘  |
 *     `------------------------------------'                                       `------------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |  ←   |   →  |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |  ↑   |      |      |
 *                                  |  ⎵   | ⌫   |------|           |------|  Tab |  ⏎  |
 *                                  |      |      |  ⌦  |           |  ↓   |      |      |
 *                                  `--------------------'           `--------------------'
 */
  [BASE] = LAYOUT_ergodox(
// left hand
KC_ESCAPE,      KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EXLM,
KC_SLASH,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_ASTR,
KC_TAB,         KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
OSM(MOD_LSFT),  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_SLASH,
KC_LCTL, LSFT(KC_LGUI), LSFT(KC_LALT),  KC_LALT,   KC_LGUI,
                                        KC_NO,  KC_LEAD,
                                                KC_NO,
                        KC_SPACE,   KC_BSPACE,  KC_DEL,

// right hand
KC_EQUAL,   KC_6,     KC_7,   KC_8,   KC_9,     KC_0,   KC_UNDS,
KC_PLUS,    KC_Y,     KC_U,   KC_I,   KC_O,     KC_P,   KC_TILD,
            KC_H,     KC_J,   KC_K,   KC_L,     TG(1),  KC_DQUO,
KC_MINUS,   KC_N,     KC_M,   KC_DOT, KC_COMMA, TG(2),  KC_QUOTE,
KC_ESCAPE,  KC_COLN,  KC_PERC,  KC_LEAD,  KC_LGUI,

KC_LEFT,  KC_RIGHT,
KC_UP,
KC_DOWN,  KC_TAB, KC_ENTER
),

  // layer 1
  [SYMB] = LAYOUT_ergodox(
KC_ESCAPE,  KC_F1,    KC_F2,    KC_F3,        KC_F4,        KC_F5,    KC_F6,
KC_NO,      KC_MINUS, KC_AT,    KC_LCBR,      KC_RCBR,      KC_GRAVE, KC_ASTR,
KC_TAB,     KC_CIRC,  KC_UNDS,  KC_LPRN,      KC_RPRN,      KC_DLR,
KC_LSHIFT,  KC_LABK,  KC_RABK,  KC_LBRACKET,  KC_RBRACKET,  KC_TILD,  KC_SLASH,
KC_LCTL,    LSFT(KC_LGUI), LSFT(KC_LALT),     KC_LALT,      KC_LGUI,

                                              KC_NO,        KC_NO,
                                                            KC_NO,
                                    KC_SPACE, KC_BSPACE,    KC_DEL,

KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,         KC_F12,     KC_NO,
KC_PLUS,  KC_ASTR,  KC_EXLM,  KC_PIPE,    KC_PERC,        KC_PLUS,    KC_NO,
          KC_HASH,  KC_EQUAL, KC_COLN,    KC_SCOLON,  KC_TRANSPARENT, KC_DQUO,
KC_MINUS, KC_AMPR,  KC_QUES,  KC_SLASH,   KC_BSLASH,      TG(2),      KC_QUOTE,
KC_ESCAPE,KC_COLN,  KC_PERC,    KC_NO,      KC_NO,

KC_LEFT,  KC_RIGHT,
KC_UP,
KC_DOWN,  KC_TAB, KC_ENTER
),

  // layer 2
  [NUMP] = LAYOUT_ergodox(
KC_NO,  KC_NO,  KC_NO,          KC_NO,                KC_NO,                KC_NO,    KC_NO,
KC_NO,  KC_NO,  KC_F15,         KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  KC_NO,    KC_ASTR,
KC_TAB,  KC_NO,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,      KC_NO,
KC_NO,  KC_NO,  KC_F14,         KC_PAUSE,             KC_MEDIA_PLAY_PAUSE,  KC_NO,    KC_SLASH,
TO(0),  KC_NO,  KC_NO,          KC_NO,                KC_NO,

  KC_NO,      KC_NO,
  KC_NO,
KC_SPACE, KC_BSPACE,

KC_EQUAL, KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET,
KC_PLUS,  KC_COMMA, KC_7,   KC_8,   KC_9,   KC_NO,
          KC_NO,    KC_0,   KC_4,   KC_5,   KC_6,   TO(1),  KC_NO,
KC_MINUS, KC_DOT,   KC_1,   KC_2,   KC_3,   TO(0),  KC_NO,
          KC_0,  KC_NO,    KC_NO,  TO(3),  KC_NO,

KC_LEFT,  KC_RIGHT,
KC_UP,
KC_DOWN,  KC_TAB, KC_ENTER
),

  // layer 3
  [OVERWATCH] = LAYOUT_ergodox(
KC_ESCAPE,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    TO(0),
KC_TAB,      KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,     KC_NO,
KC_LCTL,     KC_A,   KC_S,   KC_D,   KC_F,   KC_P,
KC_LSHIFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_GRAVE, KC_GRAVE,
KC_LCTL,    KC_F9,  KC_F9,  KC_H,   KC_R,

   KC_NO,    KC_NO,
   KC_NO,
KC_SPACE,   KC_NO,  KC_NO,


KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT

),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};


// Runs constantly in the background, in a loop every 100ms or so.
// Best used for LED status output triggered when user isn't actively typing.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == 0) {

      // Set up LED indicators for stuck modifier keys.
      // https://github.com/qmk/qmk_firmware/blob/master/tmk_core/common/report.h#L118
      switch (keyboard_report->mods) {
          case MOD_BIT(KC_LSFT): // LSHIFT
              ergodox_right_led_1_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_1_on ();
              ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_2_on ();
              ergodox_right_led_3_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_3_off ();
              break;

          case MOD_BIT(KC_LGUI): // LGUI
              ergodox_right_led_1_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_1_off ();
              ergodox_right_led_2_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_2_on ();
              ergodox_right_led_3_set (LED_BRIGHTNESS_LO);
              ergodox_right_led_3_on ();
              break;

          case MOD_BIT(KC_LSFT) ^ MOD_BIT(KC_LGUI):
              ergodox_right_led_1_set (70);
              ergodox_right_led_1_on ();
              ergodox_right_led_2_set (70);
              ergodox_right_led_2_on ();
              ergodox_right_led_3_set (70);
              ergodox_right_led_3_on ();
              break;

          default: // reset leds
              ergodox_right_led_1_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_1_off ();
              ergodox_right_led_2_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_2_off ();
              ergodox_right_led_3_set (LED_BRIGHTNESS_HI);
              ergodox_right_led_3_off ();
      }
  }
  LEADER_DICTIONARY() {
    leading = false;
    leader_end ();
    SEQ_ONE_KEY (KC_B) {
      uprintf("CMD:test\n");
    }
    SEQ_ONE_KEY (KC_S) {
      uprintf("CMD:smi\n");
    }
    SEQ_ONE_KEY (KC_V) {
      uprintf(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION"\n" );
    }
  }
}

// called by QMK during key processing before the actual key event is handled. Useful for macros.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// only runs when when the layer is changed, good for updating LED's and clearing sticky state
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        break;
      case 1:
      clear_mods();
        ergodox_right_led_1_on();
        break;
      case 2:
      clear_mods();
        ergodox_right_led_2_on();
        break;
      case 3:
      clear_mods();
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;
};
