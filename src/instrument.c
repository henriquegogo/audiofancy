#include "instrument.h"

Instrument* Instrument_init(Sampler *sampler) {
    Instrument *instrument = malloc(sizeof(Instrument));
    instrument->sampler = sampler;

    for (int i = 0; i < 12; i++) {
        instrument->keys_params[i] = Sampler_play_params_default();
        instrument->keys_params[i].speed = pow(2, (double)i/12);
    }

    return instrument;
}

void Instrument_destroy(Instrument *instrument) {
    free(instrument);
}
