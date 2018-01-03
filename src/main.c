#include <dirent.h>
#include <ao/ao.h>
#include "sampler.h"
#include "keyboard.h"

Sampler* instruments[127][127];

void keyboard_key_handler(char key) {
    float volume = 1.0;
    float speed = 1.0;
    int charcode = (int)key;

    if (charcode > 0) {
        Sampler_play(instruments[0][charcode-49], volume, speed);
    }

    printf("key: %c / code: %i / charcode: %i \n", key, key, charcode);
}

int list_directory(char *directory, char **dir_list) {
    int index = 0;
    DIR *samples_directory = opendir(directory);
    struct dirent *directory_data;

    while ( (directory_data = readdir(samples_directory)) ) {
        if (strcmp(directory_data->d_name, "..") > 0) {
            dir_list[index] = directory_data->d_name;
            index++;
        }
    }
    
    closedir(samples_directory);

    return index;
}

int main(int argc, char *argv[]) {
    ao_initialize();

    char *sample_folders[127];
    int sample_folders_count = list_directory("./samples", sample_folders); 

    for (int i = 0; i < sample_folders_count; i++) {

        char files_folder[1000];
        sprintf(files_folder, "./samples/%s", sample_folders[i]);
        puts(files_folder);

        for (int a = 0; a < 9; a++) {
            char sample_path[1000];
            sprintf(sample_path, "%s/%d.wav", files_folder, a+1);
            instruments[i][a] = Sampler_init(sample_path);
        }
    }

    Keyboard_listen(keyboard_key_handler);

    for (int y = 0; y < sizeof(instruments) / sizeof(instruments[0]); y++) {
        for (int x = 0; x < sizeof(instruments[y]) / sizeof(instruments[0][0]); x++) {
            if (instruments[y][x] != NULL) Sampler_destroy(instruments[y][x]);
        }
    }

    ao_shutdown();

    return 0;
}
