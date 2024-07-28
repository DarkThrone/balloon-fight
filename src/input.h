#ifndef __BF_INPUT_H
#define __BF_INPUT_H

#include <SDL_events.h>

#define PLAYER_COUNT 2

typedef void (*OnKeyEvent)(SDL_KeyboardEvent *ev);

typedef struct {
  OnKeyEvent onKeydown;
  OnKeyEvent onKeyup;
} PlayerInput;

PlayerInput *playerInputList[PLAYER_COUNT];

void _BF_ProcessKey(SDL_EventType evType, SDL_KeyboardEvent *ev);
void BF_ProcessInput(void);
int BF_AddPlayerInput(PlayerInput *playerInputController);

#endif
