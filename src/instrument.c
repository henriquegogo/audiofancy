#include "instrument.h"

Instrument* Instrument_init(Sampler *sampler) {
    Instrument *instrument = malloc(sizeof(Instrument));
    instrument->sampler = sampler;

    instrument->keys_params[0] = Sampler_play_params_default();
    instrument->keys_params[0].speed = pow(2, (double)0/12);
    instrument->keys_params[1] = Sampler_play_params_default();
    instrument->keys_params[1].speed = pow(2, (double)1/12);
    instrument->keys_params[2] = Sampler_play_params_default();
    instrument->keys_params[2].speed = pow(2, (double)2/12);
    instrument->keys_params[3] = Sampler_play_params_default();
    instrument->keys_params[3].speed = pow(2, (double)3/12);
    instrument->keys_params[4] = Sampler_play_params_default();
    instrument->keys_params[4].speed = pow(2, (double)4/12);
    instrument->keys_params[5] = Sampler_play_params_default();
    instrument->keys_params[5].speed = pow(2, (double)5/12);
    instrument->keys_params[6] = Sampler_play_params_default();
    instrument->keys_params[6].speed = pow(2, (double)6/12);
    instrument->keys_params[7] = Sampler_play_params_default();
    instrument->keys_params[7].speed = pow(2, (double)7/12);
    instrument->keys_params[8] = Sampler_play_params_default();
    instrument->keys_params[8].speed = pow(2, (double)8/12);
    instrument->keys_params[9] = Sampler_play_params_default();
    instrument->keys_params[9].speed = pow(2, (double)9/12);
    instrument->keys_params[10] = Sampler_play_params_default();
    instrument->keys_params[10].speed = pow(2, (double)10/12);
    instrument->keys_params[11] = Sampler_play_params_default();
    instrument->keys_params[11].speed = pow(2, (double)11/12);

    return instrument;
}

void Instrument_destroy(Instrument *instrument) {
    free(instrument);
}
