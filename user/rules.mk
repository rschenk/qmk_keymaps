SRC += rschenk.c
SRC += features/achordion.c

# Fix after QMK Breaking Changes 2022 August 27: https://github.com/qmk/qmk_firmware/pull/17559/files
ifdef USE_RMS36_LAYOUT
	INTROSPECTION_KEYMAP_C = rms36.c
endif

DYNAMIC_TAPPING_TERM_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no // This is needed to prevent warning with caps_word
