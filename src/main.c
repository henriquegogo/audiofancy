#include "sampler.h"
#include "instrument.h"
#include "keyboard.h"

Instrument *synth;

void onkeypress(char key) {
    Sampler_stop(synth->sampler->id);

    switch (key) {
        case KEY_Z:
            Sampler_play(synth->sampler, synth->keys_params[0]);
            break;
        case KEY_S:
            Sampler_play(synth->sampler, synth->keys_params[1]);
            break;
        case KEY_X:
            Sampler_play(synth->sampler, synth->keys_params[2]);
            break;
        case KEY_D:
            Sampler_play(synth->sampler, synth->keys_params[3]);
            break;
        case KEY_C:
            Sampler_play(synth->sampler, synth->keys_params[4]);
            break;
        case KEY_V:
            Sampler_play(synth->sampler, synth->keys_params[5]);
            break;
        case KEY_G:
            Sampler_play(synth->sampler, synth->keys_params[6]);
            break;
        case KEY_B:
            Sampler_play(synth->sampler, synth->keys_params[7]);
            break;
        case KEY_H:
            Sampler_play(synth->sampler, synth->keys_params[8]);
            break;
        case KEY_N:
            Sampler_play(synth->sampler, synth->keys_params[9]);
            break;
        case KEY_J:
            Sampler_play(synth->sampler, synth->keys_params[10]);
            break;
        case KEY_M:
            Sampler_play(synth->sampler, synth->keys_params[11]);
            break;
        default:
            printf("%d\n", key);
    }
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_AUDIO);

    Sampler *juno = Sampler_init("./samples/synth.wav");
    synth = Instrument_init(juno);

    Keyboard_listen(onkeypress);

    SDL_Quit();

    return 0;
}
