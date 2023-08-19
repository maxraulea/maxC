//
//  Game.c
//  Max's Snake
//
//  Created by Max Raulea on 18/05/2023.
//

#include "Game.h"
#include "DynamicArray.h"
#include "GameOver.h"
#include "Fruit.h"
#include "PrintText.h"
#include "CollisionFruit.h"
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <unistd.h>

int InitGame(SDL_Renderer *Renderer, int windowHeight, int windowWidth){
    
    int score = 0;
    char scoreString[5];
    SDL_Rect snakePart;
    
    TTF_Font *scoreFont = TTF_OpenFont("PressStart2P-Regular.ttf", 30);
    
    if (!scoreFont){
        return 1;
    }
    // we clear the start screen
    SDL_RenderClear(Renderer);
    
    SDL_Event e;
    dynamicArray Snake;
    InitArray(&Snake);
    Snake.block[0].x = windowWidth/2;
    Snake.block[0].y = windowHeight/2;
    Snake.block[0].direction = 'u';
    
    Fruit fruit;
    fruit = InitFruit(windowHeight, windowWidth);
    
    int quit = 0;
     
    while (!quit){
        
        if(IsCollisionWithFruit(&Snake, fruit)){
            fruit =  InitFruit(windowHeight, windowWidth);
            AppendBlock(&Snake);
            score += 1;
        }
        
        if (Snake.Lentgh > 1){
            for(int i = Snake.Lentgh - 1; i > 0; i--){
                Snake.block[i] = Snake.block[i-1];
            }
        }
        
        while (SDL_PollEvent(&e)){
            switch (e.key.keysym.sym) {
                case SDLK_a:
                case SDLK_LEFT:
                    if(Snake.block[0].direction != 'r'){
                        Snake.block[0].direction = 'l';
                    }
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    if(Snake.block[0].direction != 'l'){
                        Snake.block[0].direction = 'r';
                    }
                    break;
                case SDLK_w:
                case SDLK_UP:
                    if(Snake.block[0].direction != 'd'){
                        Snake.block[0].direction = 'u';
                    }
                    break;
                case SDLK_s:
                case SDLK_DOWN:
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
        
        if(IsGameOver(&Snake, windowHeight, windowWidth)){
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
    return score;
}
