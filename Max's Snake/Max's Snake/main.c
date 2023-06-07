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
#include "Game.h"


int main(int argc, char* argv[]){
    
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 600;
    int score;

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
    
    // sdl has been initialised so the game can start!
    // we first call the start game function which will ask the user to press enter to start the game
    // if the user wants to play the game 0 is returned
    // if the user does not want to play or an error occured an integer != 0 is returned
    if(StartGame(Renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 40) != 0){
        return 1;
    }
    
    // now the game can begin!
    score = InitGame(Renderer, WINDOW_HEIGHT, WINDOW_WIDTH);
    
    if(score >= 0){
        // save the score in save file or db
    }
    
    
    SDL_DestroyWindow(View);
    SDL_Quit();
    return 0;
}
