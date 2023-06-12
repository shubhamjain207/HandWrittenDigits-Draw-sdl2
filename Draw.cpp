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
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
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



        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend,&rect);

    }

};

int main()
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer* rend = nullptr;
    SDL_Window* window = nullptr;


    SDL_CreateWindowAndRenderer(

        783 , 783,
        0, &window, &rend);


    SDL_RenderSetScale(rend, 1, 1);

    float r, g, b;

    std::vector<std::vector<int>> board;

    for (int i = 0;i < 783; i++) {
        for (int j = 0;j < 783; j++) {
            board[j].push_back(1);
        }
    }


   std::cout << board[12][12] << std::endl;


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

                    //boardMatrix[posX][posY] = 1;

                }
                    
                    
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    if (flag) flag = false;
                    else flag = true;

                }

                if (e.button.button == SDL_BUTTON_RIGHT) {
                    rects.clear();
                    flag = false;

                }
            }




        }

        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_RenderClear(rend);

        for (int i = 0; i < rects.size(); i++) {
            rects[i].drawRect();
        }
        
       


        SDL_RenderPresent(rend);


    }

    return 0;


}
