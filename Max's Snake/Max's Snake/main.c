//
//  main.c
//  Max's Snake
//
//  Created by Max Raulea on 02/04/2023.
//
//  Welcome to my implementation of the game snake :)
//

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "StartScreen.h"
#include "DynamicArray.h"
#include "GameOver.h"
#include "Fruit.h"
#include "CollisionFruit.h"
#include "PrintText.h"


int main(int argc, char* argv[]){
    
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 600;
    int score = 0;
    char scoreString[5];
    SDL_Rect snakePart;
    
    srand((unsigned int)time(NULL));
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf("sdl could not initialised: %s", SDL_GetError());
        return 1;
    }
    
    SDL_Window *View = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(!View){
        printf("sdl could not create window");
        return 1;
    }
    
    SDL_Renderer *Renderer = SDL_CreateRenderer(View, -1, SDL_RENDERER_SOFTWARE);
    if(!Renderer){
        printf("sdl could not render screen");
        return 1;
    }
    
    if(TTF_Init() < 0){
        return 1;
    }
    

    TTF_Font *scoreFont = TTF_OpenFont("title.ttf", 30);
    
    if (!scoreFont){
        return 1;
    }
    // sdl has been initialised so the game can start!
    // we first call the start game function which will ask the user to press enter to start the game
    // if the user wants to play the game 0 is returned
    // if the user does not want to play or an error occured an integer != 0 is returned
    if(StartGame(Renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 40) != 0){
        return 1;
    }
    
    // now the game can begin!
    
    // we clear the start screen
    SDL_RenderClear(Renderer);
    
    SDL_Event e;
    dynamicArray Snake;
    InitArray(&Snake);
    Snake.block[0].x = WINDOW_WIDTH/2;
    Snake.block[0].y = WINDOW_HEIGHT/2;
    Snake.block[0].direction = 'u';
    
    Fruit fruit;
    fruit = InitFruit(WINDOW_HEIGHT, WINDOW_WIDTH);
    
    int quit = 0;
     
    while (!quit){
        
        if(IsCollisionWithFruit(&Snake, fruit)){
            fruit =  InitFruit(WINDOW_HEIGHT, WINDOW_WIDTH);
            AppendBlock(&Snake);
            score += 1;
        }
        
        if (Snake.Lentgh > 1){
            for(int i = Snake.Lentgh - 1; i > 0; i--){
                Snake.block[i] = Snake.block[i-1];
            }
        }
        
        if (SDL_PollEvent(&e)){
            switch (e.key.keysym.sym) {
                case SDLK_a:
                    if(Snake.block[0].direction != 'r'){
                        Snake.block[0].direction = 'l';
                    }
                    break;
                case SDLK_d:
                    if(Snake.block[0].direction != 'l'){
                        Snake.block[0].direction = 'r';
                    }
                    break;
                case SDLK_w:
                    if(Snake.block[0].direction != 'd'){
                        Snake.block[0].direction = 'u';
                    }
                    break;
                case SDLK_s:
                    if(Snake.block[0].direction != 'u'){
                        Snake.block[0].direction = 'd';
                    }
                    break;
                case SDLK_ESCAPE:
                    quit = 1;
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
        
        if(IsGameOver(&Snake, WINDOW_HEIGHT, WINDOW_WIDTH)){
            quit = 1;
        }
        
        usleep(50000 - score * 100);
        SDL_RenderClear(Renderer);
        SDL_SetRenderDrawColor(Renderer, 100, 255, 150, 255);
        for(int i = 0; i < Snake.Lentgh; i++){
            
            snakePart.h = 10;
            snakePart.w = 10;
            snakePart.x = Snake.block[i].x;
            snakePart.y = Snake.block[i].y;
    
            SDL_RenderFillRect(Renderer, &snakePart);
        }
        snakePart.x = fruit.x;
        snakePart.y = fruit.y;
        SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(Renderer, &snakePart);
        
        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
        SDL_itoa(score, scoreString, 10);
        PrintText(Renderer, scoreFont, scoreString , 50, 50);
        SDL_RenderPresent(Renderer);
    }
    
    SDL_DestroyWindow(View);
    SDL_Quit();
    return 0;
}
