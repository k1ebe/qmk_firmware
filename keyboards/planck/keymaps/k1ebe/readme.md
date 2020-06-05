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


## Random Thoughts

Remove numbers on top row of RAISE.


## QMK Commands

`compile -kb planck/rev6 -km k1ebe`

`qmk flash -kb planck/rev6 -km k1ebe`