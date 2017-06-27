#ifndef MIDI_H
#define MIDI_H

#include <stdio.h>
#include <alsa/asoundlib.h>

typedef struct Midi {
    snd_seq_t *handle;
} Midi;

Midi* Midi_new();

void Midi_cleanup(Midi *midi);

#endif
