#include "keyboard.h"

static struct termios old, new;

static char getkey() 
{
    char key;
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= ~ECHO; /* disable echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
    key = getchar();
    tcsetattr(0, TCSANOW, &old);
    return key;
}

void Keyboard_listen(void callback(char key_arg)) {
    char key = getkey();

    if (key != KEY_Q) {
        callback(key);
        Keyboard_listen(callback);
    }
}
