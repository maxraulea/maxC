//
//  main.c
//  SDL_test
//
//  Created by Max Raulea on 01/04/2023.
//

#include <stdio.h>
#include <stdbool.h>
#include "GameStruct.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
    
    const int windowHeight = 480;
    const int windowWidth = 640;
    if(SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf("sdl could not initialised: %s", SDL_GetError());
        return 1;
    }
    
    SDL_Window *View = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, 0);
    if(!View){
        printf("sdl could not create window");
        return 1;
    }
    
    SDL_Renderer *Renderer = SDL_CreateRenderer(View, -1, SDL_RENDERER_SOFTWARE);
    if(!Renderer){
        printf("sdl could not render screen");
        return 1;
    }
    SDL_SetRenderDrawColor(Renderer, 0, 0, 45, 255);
    
    
    
    SDL_Event e;
    bool quit = false;
    Position position;
    position.x = windowWidth/2;
    position.y = windowHeight/2;
     

    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
            if (e.key.keysym.sym == SDLK_UP){
                position.y -= 1;
            }
            else if (e.key.keysym.sym == SDLK_DOWN){
                position.y += 1;
            }
            else if (e.key.keysym.sym == SDLK_RIGHT){
                position.x += 1;
            }
            else if (e.key.keysym.sym == SDLK_LEFT){
                position.x -= 1;
            }
            
        }
        SDL_RenderClear(Renderer);
        SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawPoint(Renderer, position.x, position.y);
        SDL_SetRenderDrawColor(Renderer, 0, 0, 45, 255);
        SDL_RenderPresent(Renderer);
    }

    SDL_DestroyWindow(View);
    SDL_Quit();
    return 0;
}
