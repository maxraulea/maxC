//
//  Game.h
//  Max's Snake
//
//  Created by Max Raulea on 18/05/2023.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

// this functions runs the game
// it's return value is the score of the player as an integer
// or a negative integer if the there occured an error while creating starting or running the game

int InitGame(SDL_Renderer *Renderer, int windowHeight, int windowWidth);

#endif /* Game_h */
