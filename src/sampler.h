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

typedef struct player_options {
    float volume;
    float speed;
    int begin;
    int end;
} player_options;

Sampler* Sampler_init(char filename[]);

void Sampler_play(Sampler *sampler, struct player_options options);

void Sampler_destroy(Sampler *sampler);

#endif
