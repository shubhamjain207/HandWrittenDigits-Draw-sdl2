#include <SDL.h>
#include <iostream>
#include <windows.h>
#include <vector>

#undef main

class CustomPoint {

    int posX, posY;
    SDL_Renderer* rend;

public:

    CustomPoint(SDL_Renderer* rend, int posx,int posy) {
        this->posX = posx;
        this->posY = posy;
        this->rend = rend;
    }


    void drawPoint() {
        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
        SDL_RenderDrawPoint(rend, posX, posY);
    
    }

};

class CustomRect {

    SDL_Rect rect;

    SDL_Renderer* rend;

public:

    CustomRect(SDL_Renderer* rend, SDL_Rect rect) {
        
        this->rect = rect;
        this->rend = rend;
    
    }


    void drawRect() {



        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_RenderFillRect(rend,&rect);

    }

};

int main()
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer* rend = nullptr;
    SDL_Window* window = nullptr;


    SDL_CreateWindowAndRenderer(

        300 , 300,
        0, &window, &rend);


    SDL_RenderSetScale(rend, 1, 1);

    float r, g, b;

    




    SDL_Rect rect;

    rect.x = 100;
    rect.y = 100;
    rect.w = 100;
    rect.h = 100;

    std::vector<CustomPoint> points;
    std::vector<CustomRect> rects;
    

    int posX = 200, posY = 200;

    bool flag = false;

    bool running = true;

    SDL_Event e;


    CustomPoint point(rend, 100,100);





    while (running) {


        while (SDL_PollEvent(&e)) {

            if (e.type == SDL_KEYDOWN) {

                if (e.key.keysym.sym == SDLK_ESCAPE) {

                    running = false;
                }

                if (e.key.keysym.sym == SDLK_LCTRL) {

                    SDL_Surface *sshot = SDL_CreateRGBSurface(0, 300,300, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
                    SDL_RenderReadPixels(rend, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
                    SDL_SaveBMP(sshot, "screenshot.bmp");
                    SDL_FreeSurface(sshot);
                }

                 
            }

            

            if (e.type == SDL_MOUSEMOTION) {
                if (flag) {

                    
                    SDL_GetMouseState(&posX, &posY);
                   // CustomPoint point1(rend, posX - 200, posY - 200);

                    SDL_Rect rect;

                    rect.x = posX;
                    rect.y = posY;
                    rect.w = 15;
                    rect.h = 15;

                    CustomRect rect1(rend, rect);
                    rects.push_back(rect1);

                   

                }
                    
                    
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    flag = true;

                }

                if (e.button.button == SDL_BUTTON_RIGHT) {
                    rects.clear();
                    flag = false;

                }
            }

            if (e.type == SDL_MOUSEBUTTONUP) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    flag = false;

                }

               
            }




        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        for (int i = 0; i < rects.size(); i++) {
            rects[i].drawRect();
        }
        
       


        SDL_RenderPresent(rend);


    }

    return 0;


}
