#include <ao/ao.h>
#include <unistd.h>
#include <time.h>
#include "midi.h"
#include "sampler.h"

int main() {
    /* Midi */
    Midi *midi = Midi_new();

    /* Player */

    ao_initialize();

    Sampler *snare = Sampler_new("samples/snare.wav");
    Sampler *kick = Sampler_new("samples/kick.wav");
    Sampler *test = Sampler_new("samples/test.wav");

    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 450000000;

    Sampler_playAsync(test);
    for (int i = 0; i < 8; i++) {
        Sampler_playAsync(kick);
        if (i % 2) Sampler_playAsync(snare);
        nanosleep(&delay, NULL);
    }

    sleep(1);

    Sampler_cleanup(snare);
    Sampler_cleanup(kick);
    Sampler_cleanup(test);

    ao_shutdown();

    return 0;
}
