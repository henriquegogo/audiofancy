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

Sampler* Sampler_init(char filename[]);

void Sampler_play(Sampler *sampler, float volume, float speed);

void Sampler_destroy(Sampler *sampler);

#endif
