#include "input.h"
#include <SDL_events.h>
#include <SDL_stdinc.h>
#include <time.h>

void _BF_ProcessKey(SDL_EventType evType, SDL_KeyboardEvent *ev) {
  for (int i = 0, len = PLAYER_COUNT; i < PLAYER_COUNT; i = i + 1) {
    PlayerInput *pi = playerInputList[i];

    if (pi != NULL) {
      if (ev->repeat == 0) {
        switch (evType) {
        case SDL_KEYDOWN:
          pi->onKeydown(ev);
          break;
        case SDL_KEYUP:
          pi->onKeyup(ev);
          break;
        default:
          break;
        }
        return;
      }
    }
  }
}

void BF_ProcessInput(void) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      exit(0);
      break;

    case SDL_KEYDOWN:
    case SDL_KEYUP:
      _BF_ProcessKey(e.type, &e.key);
      break;

    default:
      break;
    }
  }
}
