#include "midi.h"

struct thread_args_listen {
    snd_seq_t *seq;
    void (*callback)(snd_seq_event_t *event);
};

static void listen(struct thread_args_listen *args) {
    snd_seq_t *seq = args->seq;
    void (*callback)(snd_seq_event_t *event) = args->callback;
    free(args);

    while (1) {
        snd_seq_event_t *event = NULL;
        snd_seq_event_input(seq, &event);

        if (event->type == SND_SEQ_EVENT_NOTEON) {
            callback(event);
        }
    }

    free(seq);
}

snd_seq_t* Midi_listen(void callback(snd_seq_event_t *event)) {
    snd_seq_t *seq;

    snd_seq_open(&seq, "default", SND_SEQ_OPEN_INPUT, 0);
    snd_seq_set_client_name(seq, "Niobium");
    snd_seq_create_simple_port(seq, "Niobium:input", SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, SND_SEQ_PORT_TYPE_MIDI_GENERIC);

    struct thread_args_listen *args = malloc(sizeof(struct thread_args_listen));
    args->seq = seq;
    args->callback = callback;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, (void *)listen, args);
    pthread_detach(thread_id);
}
