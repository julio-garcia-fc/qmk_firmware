#ifndef CONFIG_JULIO_H
#define CONFIG_JULIO_H

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define EECONFIG_RGB_MATRIX (uint32_t *)16

#endif
