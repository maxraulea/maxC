//
//  PrintText.c
//  Max's Snake
//
//  Created by Max Raulea on 12/04/2023.
//

#include "PrintText.h"

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

int PrintText(SDL_Renderer *Renderer, TTF_Font *font, const char *text, int xPosition, int yPosition){
    if(TTF_Init() < 0){
        return 1;
    }
    
    SDL_Color White = {255, 255, 255};
    
    SDL_Surface *Text = TTF_RenderText_Solid(font, text, White);
    
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(Renderer, Text);
    
    SDL_Rect textBox;
        textBox.h = Text->h;
        textBox.w = Text->w;
        textBox.x = xPosition - Text->w/2;
        textBox.y = yPosition;
    
    SDL_RenderCopy(Renderer, textTexture, NULL, &textBox);
    return 0;
}
