# The Default Planck Layout

## Backlights

```
LED physical location index
    6 5 4 3
       0
    7 8 1 2
```

[docs](https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight)

`RGBLIGHT_MODE_RAINBOW_SWIRL` is great
`RGBLIGHT_MODE_STATIC_GRADIENT` would be good for layers

Static rainbow:

```
rgblight rainbow set hsv: 0,232,1,255
rgblight rainbow set hsv: 1,4,1,255
rgblight rainbow set hsv: 2,32,1,255
rgblight rainbow set hsv: 3,61,1,255
rgblight rainbow set hsv: 4,89,1,255
rgblight rainbow set hsv: 5,117,1,255
rgblight rainbow set hsv: 6,146,1,255
rgblight rainbow set hsv: 7,174,1,255
rgblight rainbow set hsv: 8,202,1,255
```
