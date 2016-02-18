#include <ao/ao.h>
#include "sampler.h"

int main() {
    ao_initialize();

    Sampler *snare = Sampler_new("samples/snare.wav");
    Sampler *kick = Sampler_new("samples/kick.wav");
    Sampler *test = Sampler_new("samples/test.wav");

    Sampler_playAsync(test);
    Sampler_play(snare);
    Sampler_play(snare);
    Sampler_play(snare);
    Sampler_play(kick);
    Sampler_play(kick);
    Sampler_play(kick);

    Sampler_cleanup(snare);
    Sampler_cleanup(kick);
    Sampler_cleanup(test);

    ao_shutdown();

    return 0;
}
