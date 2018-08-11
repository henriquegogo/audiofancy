#include <ao/ao.h>
#include "sampler.h"
#include "keyboard.h"

int main(int argc, char *argv[]) {
    ao_initialize();

    Sampler *drums = Sampler_init("./samples/drums.wav");

    struct player_options options;
    options.volume = 1.0;
    options.speed = 1.0;
    options.begin = 4300;
    options.end = 4790;

    Sampler_play(drums, options);

    Keyboard_listen(NULL);

    ao_shutdown();

    return 0;
}
