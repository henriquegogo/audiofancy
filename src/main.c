#include <ao/ao.h>
#include "sampler.h"
#include "instrument.h"
#include "keyboard.h"

Instrument *synth;

void onclick(char key) {
    Sampler_stop(synth->sampler->id);
    Sampler_play_params params;

    switch (key) {
        case KEY_Z:
            params = synth->keys_params[0];
            break;
        case KEY_S:
            params = synth->keys_params[1];
            break;
        case KEY_X:
            params = synth->keys_params[2];
            break;
        case KEY_D:
            params = synth->keys_params[3];
            break;
        case KEY_C:
            params = synth->keys_params[4];
            break;
        case KEY_V:
            params = synth->keys_params[5];
            break;
        case KEY_G:
            params = synth->keys_params[6];
            break;
        case KEY_B:
            params = synth->keys_params[7];
            break;
        case KEY_H:
            params = synth->keys_params[8];
            break;
        case KEY_N:
            params = synth->keys_params[9];
            break;
        case KEY_J:
            params = synth->keys_params[10];
            break;
        case KEY_M:
            params = synth->keys_params[11];
            break;
        default:
            printf("%d\n", key);
    }
     
    Sampler_play(synth->sampler, params);
}

int main(int argc, char *argv[]) {
    ao_initialize();

    Sampler *juno = Sampler_init("./samples/synth.aif");
    synth = Instrument_init(juno);

    Keyboard_listen(onclick);

    ao_shutdown();

    return 0;
}
