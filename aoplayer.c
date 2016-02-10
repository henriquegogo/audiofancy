#include <stdio.h>
#include <string.h>
#include <ao/ao.h>
#include <sndfile.h>

int bits_from_sf_format(int format) {
    int bits = 16;

    switch (format & SF_FORMAT_SUBMASK) {
        case SF_FORMAT_PCM_16:
            bits = 16;
            break;
        case SF_FORMAT_PCM_24:
            bits = 24;
            break;
        case SF_FORMAT_PCM_32:
            bits = 32;
            break;
        case SF_FORMAT_PCM_S8:
            bits = 8;
            break;
        case SF_FORMAT_PCM_U8:
            bits = 8;
            break;
        default:
            bits = 16;
            break;
    } 

    return bits;
}

typedef struct Sampler {
    short *buffer;
    long buffer_size;
    ao_sample_format format;
} Sampler;

Sampler Sampler_new(char filename[]) {
    SF_INFO file_info;
    Sampler sampler;

    SNDFILE *file = sf_open(filename, SFM_READ, &file_info); 
    sampler.buffer_size = file_info.channels * file_info.frames * sizeof(short);
    sampler.buffer = calloc(sampler.buffer_size, sizeof(short));
    sf_read_short(file, sampler.buffer, sampler.buffer_size);
    sf_close(file);

    memset(&sampler.format, 0, sizeof(sampler.format));
    sampler.format.bits = bits_from_sf_format(file_info.format);
    sampler.format.channels = file_info.channels;
    sampler.format.rate = file_info.samplerate;
    sampler.format.byte_format = AO_FMT_LITTLE;

    return sampler;
}

void Sampler_play(Sampler sampler) {
    int driver_id = ao_default_driver_id();
    ao_device *device = ao_open_live(driver_id, &sampler.format, NULL); 
    ao_play(device, (char *)sampler.buffer, sampler.buffer_size);
    ao_close(device);
}

void Sampler_cleanup(Sampler sampler) {
    free(sampler.buffer);
}

int main() {
    ao_initialize();

    Sampler snare = Sampler_new("snare.wav");
    Sampler kick = Sampler_new("kick.wav");

    Sampler_play(kick);
    Sampler_play(snare);
    Sampler_play(kick);
    Sampler_play(snare);

    Sampler_cleanup(snare);
    Sampler_cleanup(kick);

    ao_shutdown();

    return 0;
}
