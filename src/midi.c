#include "midi.h"

Midi* Midi_new() {
    Midi *midi = malloc(sizeof(Midi));

    int err = snd_seq_open(&midi->seq, "default", SND_SEQ_OPEN_INPUT, 0);
    if (err < 0) return NULL;
    snd_seq_set_client_name(midi->seq, "Sampler");

    snd_seq_create_simple_port(midi->seq, "Sampler input", SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, SND_SEQ_PORT_TYPE_MIDI_GENERIC);

    return midi;
}

void Midi_cleanup(Midi *midi) {
    free(midi->seq);
    free(midi);
}
