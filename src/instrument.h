#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "sampler.h"

typedef struct Instrument {
    Sampler *sampler;
    Sampler_play_params keys_params[12];
} Instrument;

Instrument* Instrument_init(Sampler *sampler);

void Instrument_destroy(Instrument *instrument);

#endif
