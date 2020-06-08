# k1ebes Planck Layout

The basis for this layout is the default one, but with some modifications. The alternative keyboard layouts are removed, only the Raise, Lower and Adjust layers are preserved. Left Control and Fn has switched places.

I have added the Norwegian keymap so I can use keycodes in the keymap that are easily recognizable since the keyboard will be used with Norwegian as input language. Since the Planck is one column too short to fit å, I have placed that on a combo-key of P+Backspace. This is working quite well.

The layout is created for use at work were I use numbers and F-keys a lot. That is why these have been given prime real estate on the Space-layer. This works well since my FPS experience keeps my left thumb resting on the space bar. 


## To Do

Raise and Lower seems under utilized. Left side of the keyboard is not used at all at present time. It is either going to be used as shortcuts for AutoHotKey with modified F13-F24, ex ALT+F13. Or I will move some common symbols over there. 

Flesh out the use of the Leader key.


## Space Layer

This layer is accessed while holding down SPACE and gives easy access to F-keys and number keys. In addition F13 to F21 are also present in the center for shortcut use with Autohotkey.


## Combo Keys

Top row combos as numbers, eg QW turns to 2.
	This is not working that well, especially for "er" as that is a very common sequence both in English and Norwegian. Might have to reconsider this.

P+Backspace is å.

https://docs.qmk.fm/#/feature_combo

- Use combo keys for CTRL+V and CTRL+C?

Toggle combos on/off on the Adjust layer ø


## Random Thoughts

Remove numbers on top row of RAISE.

Tap Dance? https://www.google.com/search?q=CMB_TOG

Unicode Map for å? https://docs.qmk.fm/#/feature_unicode

## Resources

### Norwegian keymap

[Language-specific Keycodes](https://docs.qmk.fm/#/reference_keymap_extras)
The Norwegian file is added to this folder for reference.


### QMK Commands

`compile -kb planck/rev6 -km k1ebe`

`qmk flash -kb planck/rev6 -km k1ebe`


### Keymap
![Keymap image](https://docs.google.com/drawings/d/e/2PACX-1vQU7v-kJCIc_dudvcS_vK0dUUSB-pX31g8Cu2vLY9RYyz1oYrqcUP9vW2FDGSbt5__OcxMfMkruKJXu/pub?w=1287&h=1087)