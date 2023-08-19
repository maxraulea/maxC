//
//  StartScreen.c
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "StartScreen.h"
#include "PrintText.h"

int StartGame(SDL_Renderer *Renderer, int xMiddle, int yMiddle, int Fontsize, char* user){

    int nameLength = 0;
    TTF_Font *title = TTF_OpenFont("PressStart2P-Regular.ttf", Fontsize);
    TTF_Font *description = TTF_OpenFont("PressStart2P-Regular.ttf", Fontsize/2.5);
    if (!title || !description){
        return 1;
    }
    
    SDL_Event e;
    int quit = 0;
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
    SDL_StartTextInput();
    
    while (!quit){
        SDL_RenderClear(Renderer);
        PrintText(Renderer, title, "SNAKE", xMiddle, yMiddle - 150);
        PrintText(Renderer, description, "PRESS ENTER TO START", xMiddle, yMiddle - 100);
        PrintText(Renderer, description, "Please enter username", xMiddle, yMiddle + 75);
        if(*user){
            PrintText(Renderer, description, user, xMiddle, yMiddle + 100);
        }
        SDL_RenderPresent(Renderer);
        
        while (SDL_PollEvent(&e)){
            if (e.key.keysym.sym == SDLK_RETURN){
                quit = 1;
                SDL_StopTextInput();
                return 0;
            }
            else if(e.key.keysym.sym == SDLK_BACKSPACE && strlen(user) > 0 && e.key.type == SDL_KEYDOWN){
                nameLength = (int)strlen(user) - 1;
            }
            else if(e.type == SDL_TEXTINPUT && strlen(user) < 20){
                strcat(user, e.text.text);
                nameLength = (int)strlen(user);
            }
        }
        user[nameLength] = 0;
        SDL_RenderPresent(Renderer);
    }
    
    return 1;
}
