#pragma once

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif

#define TAPPING_TERM 220
#define QUICK_TAP_TERM 60
#define PERMISSIVE_HOLD
#undef  HOLD_ON_OTHER_KEY_PRESS
#define IGNORE_MOD_TAP_INTERRUPT

#define TAP_CODE_DELAY 0
