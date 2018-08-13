#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdio.h>
#include <termios.h>

enum {
    KEY_Q=113,
    KEY_ESC=27,
    KEY_SPACE=32,
    KEY_Z=122,
    KEY_S=115,
    KEY_X=120,
    KEY_D=100,
    KEY_C=99,
    KEY_V=118,
    KEY_G=103,
    KEY_B=98,
    KEY_H=104,
    KEY_N=110,
    KEY_J=106,
    KEY_M=109
};

void Keyboard_listen(void callback(char key_arg));

#endif
