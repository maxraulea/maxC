//
//  PrintText.h
//  Max's Snake
//
//  Created by Max Raulea on 12/04/2023.
//

#ifndef PrintText_h
#define PrintText_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

int PrintText(SDL_Renderer *Renderer, TTF_Font *font, const char *text, int xPosition, int yPosition);

#endif /* PrintText_h */
