#ifndef MIDI_H
#define MIDI_H

#include <pthread.h>
#include <alsa/asoundlib.h>

snd_seq_t* Midi_listen(void callback(snd_seq_event_t *event));

#endif
