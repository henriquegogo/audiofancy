#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdio.h>
#include <termios.h>

enum {
    KEY_Q=113,
    KEY_ESC=27,
    KEY_SPACE=32,
    KEY_Z=122,
    KEY_C=99
};

void Keyboard_listen(void callback(char key_arg));

#endif
