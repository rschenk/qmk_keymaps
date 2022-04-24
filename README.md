# QMK Keymaps

I decided to pull my keymaps out of my qmk fork, and put them into their own repo. Mainly because finding them was hard in the big qmk repo, and also because all the git commands ran super slow in the giant qmk repo.

## Setup

You will still need the qmk firmware repo on your computer, preferably in a sibling directory to this one. I have it set up like this:

```bash
$ git clone qmk/qmk_firmware
$ cd qmk_firmware
$ git checkout master
$ git branch dev-brach
$
$ cd ..
$ git clone rschenk/qmk_keymaps
$ cd qmk_keymaps
$ ./link.sh
```

The link command will symlink the keymaps in this repo to the correct places in the qmk_firmware directory. If you ever want to update qmk you can just blow away any changes, pull down the latest master, and rebase dev-branch.

See `link.sh` for the linking details, I kept it as basic as possible.