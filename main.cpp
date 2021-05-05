#include <iostream>
#include "SDL2/SDL.h"
#include "Head.h"
#include "BaseObject.h"
#include "Square.h"
#include <vector>
#include <ctime>
#include <cstring>
#include <SDL2/SDL_ttf.h>
#include "TextObject.h"
#include "SDL2/SDL_mixer.h"

using namespace std;
TTF_Font *font_score;
TTF_Font *font_score1;
Mix_Music *g_sound;
 Mix_Chunk *g_sound1;


//#include "Player.h"
//#include "Obstacles.h"
std::string FOOD_LIST[] = {"image//cake.png","image//cheese.png","image//jam.png","image//onion.png","image//pizza.png","image//sandwich.png","image//steak.png","image//chicken.png","image//cake.png","image//cheese.png","image//jam.png","image//onion.png","image//pizza.png","image//sandwich.png","image//steak.png","image//chicken.png"};

std::string the_map[10][10];
bool Init()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("=================================Memory Game===============================", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH ,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
        success = false;
    }
    else
    {
       g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
        {
            success = false;
        } else
        {
            SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
            {
                success = false;
            }
        }
         g_sound = Mix_LoadMUS("sample1.wav");
         if (g_sound == NULL)
        {
            success = false;
        }

        g_sound1 = Mix_LoadWAV("sq.wav");

          if (g_sound1 == NULL)
         {
                success = false;
        }

          if (TTF_Init() == -1)
        {
            success = false;
        }
         font_score = TTF_OpenFont("font.ttf", 30);//phông chữ của thím
        if (font_score == NULL)
        {
            success = false;
        }
         font_score1 = TTF_OpenFont("font.ttf", 100);//phông chữ của thím
        if (font_score1 == NULL)
        {
            success = false;
        }


    }


    return success;
}

BaseObject g_background;
bool LoadBackGround()
{
    bool ret = g_background.LoadImg("background.png", g_screen);
    if (ret == false) return false;
    else return true;
}

void close()
{
    g_background.Free();


    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

void ShowTruth()
{
    int index,i;
    std::string tmp;

    srand(time(NULL));
    for(i=0;i<16;i++)
    {
        index=rand()%(16-i)+i;
        if(index!=i)
        {
            tmp=FOOD_LIST[i];
            FOOD_LIST[i]=FOOD_LIST[index];
            FOOD_LIST[index]=tmp;
        }
    }


    the_map[0][0]=FOOD_LIST[0];
    the_map[0][1]=FOOD_LIST[1];
    the_map[0][2]=FOOD_LIST[2];
    the_map[0][3]=FOOD_LIST[3];
    the_map[1][0]=FOOD_LIST[4];
    the_map[1][1]=FOOD_LIST[5];
    the_map[1][2]=FOOD_LIST[6];
    the_map[1][3]=FOOD_LIST[7];
    the_map[2][0]=FOOD_LIST[8];
    the_map[2][1]=FOOD_LIST[9];
    the_map[2][2]=FOOD_LIST[10];
    the_map[2][3]=FOOD_LIST[11];
    the_map[3][0]=FOOD_LIST[12];
    the_map[3][1]=FOOD_LIST[13];
    the_map[3][2]=FOOD_LIST[14];
    the_map[3][3]=FOOD_LIST[15];
}



Square sq[10][10];
int main(int argc, char* argv[])
{

  if (Init() == false) return -1;

     BaseObject g_menu_;
    bool ret1 = g_menu_.LoadImg("menu.png", g_screen);
    if (ret1 == false) return -1;

    const int num_item_menu = 2;
    SDL_Rect pos_arr[num_item_menu];

    pos_arr[0].x = 320;
    pos_arr[0].y = 380;

    pos_arr[1].x = 320;
    pos_arr[1].y = 430;

    TextObject text_menu[num_item_menu];

    text_menu[0].setText("Play");
    text_menu[0].setColor(TextObject::BLACK_TEXT);
    text_menu[0].LoadFromRenderText(font_score, g_screen);


    text_menu[1].setText("Exit");
    text_menu[1].setColor(TextObject::BLACK_TEXT);
    text_menu[1].LoadFromRenderText(font_score, g_screen);

    SDL_Event m_event;
    Mix_PlayMusic(g_sound, -1);
    Square loser;
    Square winner;


    while (true)

    {
         Uint32 time_val;
        Uint32 StartTisk = SDL_GetTicks()/1000;
        int pauseTicks ;
        g_menu_.Render(g_screen);
        text_menu[0].RenderText(g_screen, pos_arr[0].x, pos_arr[0].y);
        text_menu[1].RenderText(g_screen,  pos_arr[1].x, pos_arr[1].y);
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                return 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
            {
                int xm = m_event.button.x;
                int ym = m_event.button.y;

                if (xm >=320 && xm <= 370 && ym >=430 && ym <= 480)
                {
                    close();
                    return 0;
                }

                if (xm >= 320 && xm <= 370 && ym >= 380 && ym <=430)
                {
                    pauseTicks= StartTisk;
                    if (LoadBackGround() == false) return -1;



                     Square sq[4][4];
                    int potx= 110;
                    TextObject time_game;
                    time_game.setColor(TextObject::BLACK_TEXT);
                    for ( int i = 0; i < 4; i++){
                            int poty = 150;
                            for ( int j = 0; j < 4; j++){
                            sq[i][j].Show(g_screen,potx,poty);

                            poty+= 4*SCREEN_BPP;

                        }
                    potx += 4*SCREEN_BPP;
                    }
                    int demm = 0;
                      int solve = 0;

                      ShowTruth();


                     bool is_quit = false;


      while (!is_quit)

    {


              int row[2];
               int col[2];
               int x[2];
               int y[2];


        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;break;

            }
            int cnt = 0;

           // while (solve < 8)
               {    int potx = 110;
                   for(int i = 0; i < 4; i++)
                   {
                       int poty = 150;
                       for (int j = 0; j < 4; j++)
                       {

                           if(sq[i][j].HandleInputAction(g_event,potx,poty) == true)
                           {
                                    demm ++;

                                    if (demm == 2 || demm == 4 || demm == 6){
                                        if ( demm  == 2){
                                        Mix_PlayChannel(-1,g_sound1, 0);
                                        sq[i][j].SetRect(potx,poty);
                                        sq[i][j].GetRect();
                                        sq[i][j].LoadImg(the_map[i][j],g_screen);
                                        row[0] = i;
                                        col[0] = j;
                                        x[0] = potx;
                                        y[0]= poty;


                                    }

                                     if ( demm == 4)
                                    {
                                        Mix_PlayChannel(-1,g_sound1, 0);
                                        sq[i][j].SetRect(potx,poty);
                                    sq[i][j].GetRect();
                                    sq[i][j].LoadImg(the_map[i][j],g_screen);

                                    row[1] = i;
                                    col[1] = j;
                                    x[1] = potx;
                                    y[1]= poty;





                                    }
                                    if(demm >4 ){


                                        demm = 0;


                                        if ((the_map[row[0]][col[0]] != the_map[row[1]][col[1]] ) ||(row[0] == row[1] && col[0] == col[1])){

                                        sq[row[0]][col[0]].Show (g_screen,x[0],y[0]);
                                        sq[row[1]][col[1]].Show (g_screen,x[1],y[1]);


                                     }

                                    }





                                }
                           }

                                           poty+= 4*SCREEN_BPP;
                       }
                                potx += 4*SCREEN_BPP;
                   }
        }


   }
                SDL_SetRenderDrawColor(g_screen, 218,218 , 218, 0);
                SDL_RenderClear(g_screen);
                std::string str_time = "time : ";
                time_val =SDL_GetTicks()/1000 ;
                std::string str_val = std::to_string(45 + pauseTicks - time_val);
                str_time += str_val;
                 time_game.setText(str_time);
                time_game.setColor(TextObject::BLACK_TEXT);
                time_game.LoadFromRenderText(font_score, g_screen);
                time_game.RenderText(g_screen,100,100);

                TextObject lose;
                      if (time_val == 45+ pauseTicks)
                {
                    SDL_Delay(1000);
                 lose.setText("you lose");
                lose.setColor(TextObject::BLACK_TEXT);
                lose.LoadFromRenderText(font_score1, g_screen);
                lose.RenderText(g_screen,200,250);
                SDL_RenderPresent(g_screen);
                SDL_Delay(3000);
                return 0;


                }

                g_background.Render(g_screen);
                time_game.RenderText(g_screen, 100, 100,NULL, 0,0);

                  for ( int i = 0; i < 4; i++){

                    for ( int j = 0; j < 4; j++){
                        sq[i][j].Render(g_screen);

                    }

                }





                SDL_RenderPresent(g_screen);


                }


            }


                break;
        }
            default:
                break;
     }
    }

        SDL_RenderPresent(g_screen);
    }
    close();
    return 0;

}




