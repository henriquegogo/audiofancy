#include <stdio.h>
#include <termios.h>
#include <ao/ao.h>
#include "midi.h"
#include "sampler.h"

Sampler* samples[127]; 
static struct termios old, new;

char getkey() 
{
    char key;
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= ~ECHO; /* disable echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
    key = getchar();
    tcsetattr(0, TCSANOW, &old);
    return key;
}

void event_handler(snd_seq_event_t *event) {
    int midi_note = event->data.note.note;
    int midi_velocity = event->data.note.velocity;

    float volume = midi_velocity / 127.0;
    float speed = 1.0;
    Sampler_play(samples[midi_note], volume, speed);
}

int main(int argc, char *argv[]) {
    ao_initialize();

    samples[60] = Sampler_init("samples/kick.wav");
    samples[64] = Sampler_init("samples/snare.wav");

    Midi *midi = Midi_init();
    Midi_listen(midi, event_handler);

    printf("Press any key to quit\n");
    char key = getkey();
    printf("Key pressed: %c\n", key);

    Midi_destroy(midi);
    
    for (int i = 0; i < sizeof(samples) / sizeof(samples[0]); i++) {
        if (samples[i] != NULL) Sampler_destroy(samples[i]);
    }

    ao_shutdown();

    return 0;
}
