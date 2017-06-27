#include "midi.h"

Midi* Midi_new() {
    Midi *midi = malloc(sizeof(Midi));

    int err = snd_seq_open(&midi->handle, "default", SND_SEQ_OPEN_INPUT, 0);
    if (err < 0) return NULL;
    snd_seq_set_client_name(midi->handle, "Sampler");

    return midi;
}

void Midi_cleanup(Midi *midi) {
    free(midi->handle);
    free(midi);
}
