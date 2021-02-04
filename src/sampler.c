#include "sampler.h"
#include <SDL2/SDL_audio.h>

Sampler_play_params Sampler_play_params_default() {
    struct Sampler_play_params options;
    options.volume = 1.0;
    options.speed = 1.0;
    options.begin = 0;
    options.end = -1;

    return options;
}

Sampler* Sampler_init(char filename[]) {
    Sampler *sampler = malloc(sizeof(Sampler));
    sampler->id = 0;

    if (filename != NULL) {
        SDL_LoadWAV(filename, &sampler->spec, &sampler->buffer, &sampler->buffer_size);
    }

    return sampler;
}

void Sampler_play(Sampler *sampler, struct Sampler_play_params options) {
    if (sampler != NULL) {
        printf("Volume: %f, speed: %f freq: %d\n", options.volume, options.speed, sampler->spec.freq);
        
        SDL_AudioSpec spec = sampler->spec;
        spec.freq = sampler->spec.freq * options.speed;

        sampler->id = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
        SDL_QueueAudio(sampler->id, sampler->buffer, sampler->buffer_size);
        SDL_PauseAudioDevice(sampler->id, 0);
    }
}

void Sampler_stop(SDL_AudioDeviceID id) {
    SDL_CloseAudioDevice(id);
}

void Sampler_destroy(Sampler *sampler) {
    SDL_CloseAudioDevice(sampler->id);
    SDL_FreeWAV(sampler->buffer);
    free(sampler);
}
