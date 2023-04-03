//
//  StartScreen.h
//  Max's Snake
//
//  Created by Max Raulea on 02/04/2023.
//

#ifndef StartScreen_h
#define StartScreen_h

#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

int StartGame(SDL_Renderer *Renderer, int xMiddle, int yMiddle){
    if(TTF_Init() < 0){
        return 1;
    }
    
    SDL_Color White = {255, 255, 255};
    TTF_Font *title = TTF_OpenFont("title.ttf", 30);
    TTF_Font *description = TTF_OpenFont("description.ttf", 15);
    if (!title || !description){
        return 1;
    }
    
    SDL_Surface *titleText = TTF_RenderText_Solid(title, "SNAKE", White);
    SDL_Texture *titleTexture = SDL_CreateTextureFromSurface(Renderer, titleText);
    
    SDL_Surface *descriptionText = TTF_RenderText_Solid(description, "PRESS ENTER TO START", White);
    SDL_Texture *descriptionTexture = SDL_CreateTextureFromSurface(Renderer, descriptionText);
    
    SDL_Rect titleBox;
        titleBox.h = titleText->h;
        titleBox.w = titleText->w;
        titleBox.x = xMiddle - titleText->w/2;
        titleBox.y = yMiddle;
    
    SDL_Rect descriptionBox;
        descriptionBox.h = descriptionText->h;
        descriptionBox.w = descriptionText->w;
        descriptionBox.x = xMiddle - descriptionText->w/2;
        descriptionBox.y = yMiddle + 50;
    
    SDL_Event e;
    bool quit = false;
     
    while (!quit){
        sleep(1);
        SDL_RenderClear(Renderer);
        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
        SDL_RenderCopy(Renderer, titleTexture, NULL, &titleBox);
        SDL_RenderPresent(Renderer);
        
        while (SDL_PollEvent(&e)){
            if (e.key.keysym.sym == SDLK_RETURN){
                quit = true;
                return 0;
            }
        }
        sleep(1);
        SDL_RenderCopy(Renderer, descriptionTexture, NULL, &descriptionBox);
        SDL_RenderPresent(Renderer);
    }
    
    return 1;
}

#endif /* StartScreen_h */
