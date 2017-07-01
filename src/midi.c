#include "midi.h"

Midi* Midi_init() {
    Midi *midi = malloc(sizeof(Midi));

    snd_seq_open(&midi->seq, "default", SND_SEQ_OPEN_INPUT, 0);
    snd_seq_set_client_name(midi->seq, "Sampler");
    snd_seq_create_simple_port(midi->seq, "Sampler:input", SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, SND_SEQ_PORT_TYPE_MIDI_GENERIC);

    return midi;
}

void Midi_listen(Midi *midi, void callback(snd_seq_event_t *event)) {
    while (1) {
        snd_seq_event_t *event = NULL;
        snd_seq_event_input(midi->seq, &event);

        if (event->type == SND_SEQ_EVENT_NOTEON) {
            if (event->data.note.note == 48) break;
            callback(event);
        }
    }
}

void Midi_destroy(Midi *midi) {
    free(midi->seq);
    free(midi);
}
