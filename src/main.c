#include <SDL2/SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_hints.h>
#include <SDL_image.h>
#include <SDL_log.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "defs.h"
#include "draw.h"

App app;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

void initSDL(void) {
  int rendererFlags, windowFlags;

  rendererFlags = SDL_RENDERER_ACCELERATED;

  windowFlags = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialise SDL: %s\n", SDL_GetError());
    exit(-1);
  }

  app.window = SDL_CreateWindow("BFight", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                SCREEN_HEIGHT, windowFlags);

  if (!app.window) {
    printf("Failed to open %d by %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT,
           SDL_GetError());
    exit(-1);
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
  if (!app.renderer) {
    printf("Failed to create renderer: %s\n", SDL_GetError());
    exit(-1);
  }
}

void BF_processInput(void) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      exit(0);
      break;

    default:
      break;
    }
  }
}

int main(void) {

  memset(&app, 0, sizeof(App));

  SDL_Log("BFight 0.1 initialising");
  initSDL();

  SDL_Event e;

  while (1) {
    BF_prepare();
    BF_processInput();

    SDL_Texture *texture = IMG_LoadTexture(app.renderer, "assets/ballon.png");

    SDL_Rect dest;

    dest.x = 100;
    dest.y = 100;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app.renderer, texture, NULL, &dest);

    BF_present();
    SDL_Delay(16);
  }

  return 0;
}
