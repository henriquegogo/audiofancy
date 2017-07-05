#include <ao/ao.h>
#include "midi.h"
#include "sampler.h"
#include "keyboard.h"

Sampler* samples[127]; 

void midi_event_handler(snd_seq_event_t *event) {
    int midi_note = event->data.note.note;
    int midi_velocity = event->data.note.velocity;

    float volume = midi_velocity / 127.0;
    float speed = 1.0;
    Sampler_play(samples[midi_note], volume, speed);
}

void keyboard_key_handler(char key) {
    float volume = 1.0;
    float speed = 1.0;

    switch (key) {
        case KEY_Z:
            Sampler_play(samples[60], volume, speed);
            break;
        case KEY_C:
            Sampler_play(samples[64], volume, speed);
            break;
        default:
            printf("key: %c / code: %i\n", key, key);
    } 
}

int main(int argc, char *argv[]) {
    ao_initialize();

    samples[60] = Sampler_init("samples/kick.wav");
    samples[64] = Sampler_init("samples/snare.wav");

    Midi_listen(midi_event_handler);
    Keyboard_listen(keyboard_key_handler);

    for (int i = 0; i < sizeof(samples) / sizeof(samples[0]); i++) {
        if (samples[i] != NULL) Sampler_destroy(samples[i]);
    }

    ao_shutdown();

    return 0;
}
