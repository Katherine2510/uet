#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <cstdlib>

#include <windows.h>
#include <cstring>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



static SDL_Window *g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//screen

const int SCREEN_WIDTH = 700;
const int  SCREEN_HEIGHT = 650;
const int SCREEN_BPP = 32;




#endif // HEAD_H
