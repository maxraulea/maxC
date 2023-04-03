//
//  main.c
//  Max's Snake
//
//  Created by Max Raulea on 02/04/2023.
//
//  Welcome to my implementation of the game snake :)
//

#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include "StartScreen.h"

int main(int argc, char* argv[]){
    
    const int windowHeight = 750;
    const int windowWidth = 600;
    
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
    
    // sdl has been initialised so the game can start!
    // we first call the start game function which will ask the user to press enter to start the game
    // if the user wants to play the game 0 is returned
    // if the user does not want to play or an error occured an integer != 0 is returned
    if(StartGame(Renderer, windowWidth/2, windowHeight/2) != 0){
        return 1;
    }
    SDL_Event e;
    bool quit = false;
     
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }

        }
        
        SDL_RenderClear(Renderer);
        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
        SDL_RenderPresent(Renderer);
    }
    
    SDL_DestroyWindow(View);
    SDL_Quit();
    return 0;
}
