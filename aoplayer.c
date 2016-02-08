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

int main() {
    ao_device *device;
    ao_sample_format format;
    int driver_id;
    short *buffer;
    long buffer_size;
    SNDFILE *file;
    SF_INFO file_info;

    // sndfile
    file = sf_open("snare.wav", SFM_READ, &file_info); 
    buffer_size = file_info.channels * file_info.frames * sizeof(short);
    buffer = calloc(buffer_size, sizeof(short));
    sf_read_short(file, buffer, buffer_size);
    sf_close(file);

    // ao
    ao_initialize();

    driver_id = ao_default_driver_id();

    memset(&format, 0, sizeof(format));
    format.bits = bits_from_sf_format(file_info.format);
    format.channels = file_info.channels;
    format.rate = file_info.samplerate;
    format.byte_format = AO_FMT_LITTLE;

    device = ao_open_live(driver_id, &format, NULL); 

    ao_play(device, (char *)buffer, buffer_size);

    ao_close(device);
    ao_shutdown();
    free(buffer);

    return 0;
}
