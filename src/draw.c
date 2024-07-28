#include "defs.h"
#include <SDL2/SDL.h>
#include <SDL_render.h>

void BF_prepare(App *app) {
  // do nothing`
  SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
  SDL_RenderClear(app->renderer);
}

void BF_present(App *app) { SDL_RenderPresent(app->renderer); }
