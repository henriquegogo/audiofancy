#include "instrument.h"

Instrument* Instrument_init(Sampler *sampler) {
    Instrument *instrument = malloc(sizeof(Instrument));
    instrument->sampler = sampler;

    instrument->keys_params[0] = Sampler_play_params_default();
    instrument->keys_params[0].speed = 1.0;
    instrument->keys_params[1] = Sampler_play_params_default();
    instrument->keys_params[1].speed = 1.059;
    instrument->keys_params[2] = Sampler_play_params_default();
    instrument->keys_params[2].speed = 1.122;
    instrument->keys_params[3] = Sampler_play_params_default();
    instrument->keys_params[3].speed = 1.189;
    instrument->keys_params[4] = Sampler_play_params_default();
    instrument->keys_params[4].speed = 1.259;
    instrument->keys_params[5] = Sampler_play_params_default();
    instrument->keys_params[5].speed = 1.334;
    instrument->keys_params[6] = Sampler_play_params_default();
    instrument->keys_params[6].speed = 1.414;
    instrument->keys_params[7] = Sampler_play_params_default();
    instrument->keys_params[7].speed = 1.498;
    instrument->keys_params[8] = Sampler_play_params_default();
    instrument->keys_params[8].speed = 1.587;
    instrument->keys_params[9] = Sampler_play_params_default();
    instrument->keys_params[9].speed = 1.681;
    instrument->keys_params[10] = Sampler_play_params_default();
    instrument->keys_params[10].speed = 1.781;
    instrument->keys_params[11] = Sampler_play_params_default();
    instrument->keys_params[11].speed = 1.887;

    return instrument;
}

void Instrument_destroy(Instrument *instrument) {
    free(instrument);
}
