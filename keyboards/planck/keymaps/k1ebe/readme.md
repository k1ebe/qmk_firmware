# k1ebes Planck Layout

The basis for this layout is the default one, but with some modifications. The alternative keyboard layouts are removed, only the Raise, Lower and Adjust layers are preserved. Left Control and Fn has switched places.


## Space Layer

This layer is accessed while holding down SPACE and gives easy access to F-keys and number keys. In addition F13 to F21 is also present in the center for shortcut use with Autohotkey.

## To Do

Raise and Lower seems under utilized. Left side of the keyboard is not used at all at present time.
Fn-layer is blank - how to use. Maybe layer toggle for numpad...

### Combo Keys

Top row combos as numbers, eg QW turns to 2.
P+Backspace is å.

https://docs.qmk.fm/#/feature_combo

- Use combo keys for CTRL+V and CTRL+C?

Toggle combos on/off on the Adjust layer ø


## Random Thoughts

Remove numbers on top row of RAISE.

Use the Fn key as Leader key?

Tap Dance? https://www.google.com/search?q=CMB_TOG

Unicode Map for å? https://docs.qmk.fm/#/feature_unicode


## QMK Commands

`compile -kb planck/rev6 -km k1ebe`

`qmk flash -kb planck/rev6 -km k1ebe`


## Keymap
![Keymap image](https://docs.google.com/drawings/d/e/2PACX-1vQU7v-kJCIc_dudvcS_vK0dUUSB-pX31g8Cu2vLY9RYyz1oYrqcUP9vW2FDGSbt5__OcxMfMkruKJXu/pub?w=1287&h=1087)