#ifndef SAMPLER_H
#define SAMPLER_H

#include <SDL2/SDL.h>

typedef struct Sampler {
    SDL_AudioDeviceID id;
    Uint8 *buffer;
    Uint32 buffer_size;
    SDL_AudioSpec spec;
} Sampler;

typedef struct Sampler_play_params {
    float volume;
    float speed;
    int begin;
    int end;
} Sampler_play_params;

Sampler_play_params Sampler_play_params_default();

Sampler* Sampler_init(char filename[]);

void Sampler_play(Sampler *sampler, struct Sampler_play_params options);

void Sampler_stop(SDL_AudioDeviceID id);

#endif
