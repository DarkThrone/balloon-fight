#include "defs.h"
#include <SDL2/SDL.h>
#include <SDL_render.h>

extern App app;

void BF_prepare(void) {
  // do nothing`
  SDL_SetRenderDrawColor(app.renderer, 96, 196, 255, 255);
  SDL_RenderClear(app.renderer);
}

void BF_present(void) { SDL_RenderPresent(app.renderer); }
