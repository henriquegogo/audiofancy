#include <stdio.h>
#include <ncurses.h>
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
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Init(0);
  initscr();
}

void deinitialize() {
  endwin();
  Mix_Quit();
  Mix_CloseAudio();
  SDL_Quit();
}

int main(int argc, char const *argv[]) {
  initialize();

  int key;
  while (1) {
    key = getch();
    if (key == '.') break;
    else if (key == 'z') play("./kick.wav");
    else if (key == 'x') play("./snare.wav");
  }

  deinitialize();

  return 0;
}
