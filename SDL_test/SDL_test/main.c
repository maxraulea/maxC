//
//  main.c
//  SDL_test
//
//  Created by Max Raulea on 01/04/2023.
//

#include <stdio.h>
#include "GameStruct.h"

#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
   if(SDL_Init(SDL_INIT_VIDEO) < 0 ){
      printf("sdl could not initialised: %s", SDL_GetError());
   }else{
       printf("SDL succes!!");
   }

   return 0;
}
