## Introduction  

Work in progress, this is my first QMK keyboard and I'm activly working on my layout.
ANSI layout with split right shift. This this also has split space but I have not that on the actual board. Keys k44 and k48 are not present so I keep them the same as the spacebar to prevent errors.
Auto shift is enabled but is under consideration.
---

## Layers  

### Base layer  

As auto shift for all keys at the moment, considering the usage, maybe to limit it to non-alfa keys. Auto shift is only active on the base layer.

### Space layer - momentary layer  

Adds F-keys and numpad. Plus Page Up and Page Down with Home and End with double taps.

### Menu layer - momentary layer  

Primarly used for keyboard commands: RGB and reset.

### Caps lock layer - momentary layer  

Media keys.
Added Page up, Page down, Home and End to simplify navigation for pages.
Layer 3 on Hold and Backspace on tap.

### Up arrow layer - Layer-tap-toggle  

Tentatively used for mouse movement, I'm unsure how usefull this would be. Probably gone change this to a gaming layer, ie no special keys and auto shift.
---

## Layout  

 LAYOUT_60_ansi_split_space_rshift
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐\
  │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0e     │\
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤\
  │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │\
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤\
  │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │\
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤\
  │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3d    │3e │\
  ├────┬───┴┬──┴─┬─┴───┴───┴┬──┴─┬─┴───┴──┬┴───┼───┴┬────┬┴───┤\
  │40  │41  │43  │44        │46  │48      │4a  │4b  │4d  │4e  │\
  └────┴────┴────┴──────────┴────┴────────┴────┴────┴────┴────┘\

#define LAYOUT_60_ansi_split_space_rshift( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,      k0e, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d,      \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d, k3e, \
    k40, k41,      k43, k44,      k46,      k48,      k4a, k4b,      k4d, k4e  \
)

* ESC row has 14 keys
* TAB row has 14 keys
* CAPS LOCK row has 13 keys
* SHIFT row has 13 keys
* CTRL row has 10 keys (8 physical)
---

## Notes  

RGB stuff was found in mechmerlins keymap.

The virtual desktop swither on the ALT key was found here: https://www.keebtalk.com/t/show-me-your-favorite-qmk-hacks/2682/48

Vurder Caps lock som ESC ved tap og layer 3 ved hold. Alternativt tap dance funksjonalitet: https://docs.qmk.fm/#/feature_tap_dance?id=example-6-using-tap-dance-for-momentary-layer-switch-and-layer-toggle-keys
Mulig jeg kan bruke CAPS som leader key: https://docs.qmk.fm/#/feature_leader_key - https://thomasbaart.nl/2018/12/20/qmk-basics-leader-key/

Vurder Combos for feks F1-F12 med å presse 1 og 2 samtidig for F1 (evt begynn med ESC og 1 for F1) og så videre: https://docs.qmk.fm/#/feature_combo
Det kan se ut som om Combos og Auto shift ikke virker på de samme knappene samtidig. Combos vinner.

Lag en lag for spilling - dvs uten auto shift.