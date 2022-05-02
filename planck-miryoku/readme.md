# Planck with Miryoku

I hacked Miryoku a bit, to make it play well with Mac's OS-level handling of
Colemak DH, and to add some extras that I like, such as Achordion, Caps-Word,
and my own LED config.

To do this I followed the instructions in [manna-harbour's qmk repo](https://github.com/manna-harbour/qmk_firmware/commit/3d7a0b10295d6082de874dde4d78e7d09298364e)

```bash
d=keyboards/planck/keymaps/rschenk-miryoku
mkdir -p $d

layout=layouts/community/ortho_4x12
for f in users/manna-harbour_miryoku/config.h $layout/manna-harbour_miryoku/config.h
do
  echo "// copied from $f"
  cat $f
  echo
  echo
done > $d/config.h

for f in users/manna-harbour_miryoku/manna-harbour_miryoku.{h,c}
do
  echo "// copied from $f"
  cat $f
  echo
  echo
done > $d/keymap.c

for f in users/manna-harbour_miryoku/rules.mk
do
  echo "# copied from $f"
  cat $f
done > $d/rules.mk
```
