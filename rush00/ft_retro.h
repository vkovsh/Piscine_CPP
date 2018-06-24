#ifndef FT_RETRO_H
# define FT_RETRO_H
# include <string.h>
# include <signal.h>
# include "ncurses.h"
# include <iostream>
# define Y_SPLIT 4
# define X_SPLIT 4
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_SPACE 32
# define KEY_ESC 27
# define RETRO_HEIGHT 34
# define RETRO_WIDTH 102
# define FIELD_WIDTH (26 << 1)
# define FIELD_HEIGHT (12 << 1)
# define FRAME_RATE 60
# define SECOND 1000000
# define MICROSECONDS_BY_FRAME 16667
# define KEY_O 111
# define KEY_I 105
#endif