#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int mix_audio;

void play(char* file_path) {
  Mix_Chunk *sample = Mix_LoadWAV(file_path);
  Mix_PlayChannel(-1, sample, 0);
  // Mix_FreeChunk(sample);
}

void initialize() {
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Init(0);
}

void deinitialize() {
  Mix_Quit();
  Mix_CloseAudio();
  SDL_Quit();
}

int main(int argc, char const *argv[]) {
  initialize();

  int key;

  system("/bin/stty raw");
  while (key = getchar() != '.') {
    play("./test.wav");
    printf("%c\n\r", key);
  }
  system("/bin/stty cooked");

  printf("Bye bye!\n");

  deinitialize();

  return 0;
}
