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

int main() {
  SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  Mix_Init(0);

  SDL_Window *window;
  window = SDL_CreateWindow(
    "Test Application",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    640, 480,
    SDL_WINDOW_SHOWN
  );

  SDL_Delay(3000);

  /*
  initscr();
  int key;
  while (1) {
    key = getch();
    if (key == '.') break;
    else if (key == 'z') play("./kick.wav");
    else if (key == 'x') play("./snare.wav");
  }
  endwin();
  */

  SDL_DestroyWindow(window);
  Mix_Quit();
  Mix_CloseAudio();
  SDL_Quit();

  return 0;
}
