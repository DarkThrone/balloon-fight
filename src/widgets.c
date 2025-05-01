#include "widgets.h"

void BF_Create_FPS_W(void) {
  printf("Widget Created");
  TTF_Init();
  TTF_Font *font = TTF_OpenFont(
      "/Users/gsgritta/Libr ary/Fonts/JetBrainsMonoNerdFont-Regular.ttf", 24);

  printf("Font Family: %s", font->face->family_name);
}

void BF_Destroy_FPS_W(void) { printf("Widget Destroyed"); }
