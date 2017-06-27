#ifndef MIDI_H
#define MIDI_H

#include <stdio.h>
#include <string.h>
#include <alsa/asoundlib.h>

typedef struct Midi {
    snd_seq_t *seq;
} Midi;

Midi* Midi_new();

void Midi_cleanup(Midi *midi);

#endif
