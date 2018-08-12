#ifndef SAMPLER_H
#define SAMPLER_H

#include <string.h>
#include <pthread.h>
#include <sndfile.h>
#include <ao/ao.h>

typedef struct Sampler {
    short *buffer;
    long buffer_size;
    ao_sample_format format;
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

void Sampler_destroy(Sampler *sampler);

#endif
