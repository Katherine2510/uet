#ifndef  SQUARE_H

#define SQUARE_H
#include "BaseObject.h"
#include "Head.h"
#include <cstdlib>
#include <ctime>
#include <cstring>


class Square : public BaseObject
{


    public:
        Square();
        ~Square();
       void Show (SDL_Renderer* des,int px,int py);
    bool HandleInputAction(SDL_Event events, int px, int py);
     void ShowTruth (SDL_Renderer* des,int px,int py);
     void ShowDone(SDL_Renderer* des,int px,int py);

       //void HandleMove();
    private:


};




#endif // SQUARE_H
