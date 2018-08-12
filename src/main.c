#include <ao/ao.h>
#include "sampler.h"
#include "keyboard.h"

// These global are just for development tests
Sampler *global_drums;
struct Sampler_play_params global_kick;
struct Sampler_play_params global_snare;
struct Sampler_play_params global_hihat;

void onclick(char key) {
    switch (key) {
        case 122:
            Sampler_play(global_drums, global_kick);
            printf("Kick\n");
            break;
        case 99:
            Sampler_play(global_drums, global_snare);
            printf("Snare\n");
            break;
        case 103:
            Sampler_play(global_drums, global_hihat);
            printf("Hihat\n");
            break;
        default:
            printf("%d\n", key);
    }
}

int main(int argc, char *argv[]) {
    ao_initialize();

    Sampler *drums = Sampler_init("./samples/drums.wav");

    struct Sampler_play_params kick = Sampler_play_params_default();
    kick.begin = 191;
    kick.end = 454;

    struct Sampler_play_params snare = Sampler_play_params_default();
    snare.begin = 4300;
    snare.end = 4790;

    struct Sampler_play_params hihat = Sampler_play_params_default();
    hihat.begin = 4797;
    hihat.end = 5019;

    Sampler_play(drums, kick);
    Sampler_play(drums, snare);
    Sampler_play(drums, hihat);

    global_drums = drums;
    global_kick = kick;
    global_snare = snare;
    global_hihat = hihat;
    Keyboard_listen(onclick);

    ao_shutdown();

    return 0;
}
