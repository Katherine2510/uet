#include "Square.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <map>

Square::Square()
{
    rect_.x = SCREEN_WIDTH/45;
    rect_.y = SCREEN_HEIGHT/18;


}

Square::~Square()
{
    SDL_RenderCopy(g_screen, p_object_, 0, NULL);
}

void Square::Show(SDL_Renderer* g_screen,int px, int py)
{
    this -> SetRect(px,py);
    this -> GetRect();
    this -> LoadImg("Square.png",g_screen);


}
bool Square::HandleInputAction(SDL_Event events, int px, int py)
{   if (events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_ESCAPE) return false;
    if(   events.button.button == SDL_BUTTON_LEFT)
    {
        //Get mouse position

        int x, y;
        SDL_GetMouseState( &x, &y );


        bool inside = true;

        if(  x < px )

        {
            inside = false;
        }

       else if( x >  px + 100)
        {
            inside = false;
        }
        else if( y < py )
        {
            inside = false;
        }


       else if( y >  py + 100 )
        {
            inside = false;
        }


        if(inside == true)
        {
            return true;
        }
        else return false;
    }
}


void Square::ShowDone (SDL_Renderer* g_screen,int px, int py)
{
    this -> SetRect(px,py);
    this -> GetRect();
    this -> LoadImg("done.png",g_screen);
}







