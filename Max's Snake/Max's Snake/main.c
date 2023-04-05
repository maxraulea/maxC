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
#include <unistd.h>

#include <SDL2/SDL.h>
#include "StartScreen.h"
#include "DynamicArray.h"

int main(int argc, char* argv[]){
    
    const int windowHeight = 750;
    const int windowWidth = 600;
    SDL_Rect snakePart;
    
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
    if(StartGame(Renderer, windowWidth/2, windowHeight/2, 40) != 0){
        return 1;
    }
    
    // now the game can begin!
    
    // we clear the start screen
    SDL_RenderClear(Renderer);
    
    SDL_Event e;
    dArray Snake;
    initArray(&Snake, 1);
    Snake.block[0].x = windowWidth/2;
    Snake.block[0].y = windowHeight/2;
    
    
    bool quit = false;
     
    while (!quit){
        
        for(int i = Snake.Lentgh; i > 0; i--){
            Snake.block[i] = Snake.block[i-1];
        }
        
        while (SDL_PollEvent(&e)){
            switch (e.key.keysym.sym) {
                case SDLK_a:
                    Snake.block[0].direction = 'l';
                    break;
                case SDLK_d:
                    Snake.block[0].direction = 'r';
                    break;
                case SDLK_w:
                    Snake.block[0].direction = 'u';
                    break;
                case SDLK_s:
                    Snake.block[0].direction = 'd';
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                default:
                    break;
            }
        }
        
        switch (Snake.block[0].direction) {
            case 'l':
                Snake.block[0].x -= 10;
                break;
            case 'r':
                Snake.block[0].x += 10;
                break;
            case 'u':
                Snake.block[0].y -= 10;
                break;
            case 'd':
                Snake.block[0].y += 10;
                break;
            default:
                break;
        }
        
        
        usleep(50000);
        SDL_RenderClear(Renderer);
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
        for(int i = 0; i < Snake.Lentgh; i++){
            
                snakePart.h = 10;
                snakePart.w = 10;
                snakePart.x = Snake.block[i].x;
                snakePart.y = Snake.block[i].y;
            
            SDL_RenderFillRect(Renderer, &snakePart);
            SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
        }
        SDL_RenderPresent(Renderer);
        
        if(5 > Snake.Lentgh){
            for (int i = 0; i < 5; i++){
                AppendBlock(&Snake);
            }
        }
        else{
            printf("position 2nd block %d, %d \n",Snake.block[1].x, Snake.block[1].y);
            printf("position 3rd block %d, %d \n",Snake.block[2].x, Snake.block[2].y);
            printf("position 4th block %d, %d \n",Snake.block[3].x, Snake.block[3].y);
            printf("position 5th block %d, %d \n",Snake.block[4].x, Snake.block[4].y);
        }
    }
    
    SDL_DestroyWindow(View);
    SDL_Quit();
    return 0;
}
