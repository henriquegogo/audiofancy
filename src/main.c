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
    int charcode = (int)key;

    if (charcode > 0) {
        Sampler_play(samples[charcode], volume, speed);
    }

    printf("key: %c / code: %i / charcode: %i \n", key, key, charcode);
}

int main(int argc, char *argv[]) {
    ao_initialize();

    for (int i = 0; i < 127; i++) {
        char sample_path[1000];
        sprintf(sample_path, "./samples/%d.wav", i);

        samples[i] = Sampler_init(sample_path);
    }

    Midi_listen(midi_event_handler);
    Keyboard_listen(keyboard_key_handler);

    for (int i = 0; i < sizeof(samples) / sizeof(samples[0]); i++) {
        if (samples[i] != NULL) Sampler_destroy(samples[i]);
    }

    ao_shutdown();

    return 0;
}
