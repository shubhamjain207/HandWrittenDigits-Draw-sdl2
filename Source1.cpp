//#include <SDL.h>
//#include <iostream>
//#include <windows.h>
//
//
//#undef main
//
//
//
//int main()
//{
//
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Renderer* rend = nullptr;
//    SDL_Window* window = nullptr;
//
//
//    SDL_CreateWindowAndRenderer(
//
//        680, 480,
//        0, &window, &rend);
//
//
//    SDL_RenderSetScale(rend, 1, 1);
//
//    float r, g, b;
//
//
//    SDL_Rect rect;
//
//    rect.x = 100;
//    rect.y = 100;
//    rect.w = 100;
//    rect.h = 100;
//
//
//    int posX =200, posY=200;
//
//    bool flag = false;
//
//    bool running = true;
//
//    SDL_Event e;
//
//
//    while (running) {
//
//
//        while (SDL_PollEvent(&e)) {
//
//            if (e.type == SDL_KEYDOWN) {
//
//                if (e.key.keysym.sym == SDLK_ESCAPE) {
//
//                    running = false;
//                }
//
//            }
//
//            if (e.type == SDL_MOUSEMOTION) {
//                if(flag) SDL_GetMouseState(&posX, &posY);
//            }
//            if (e.type == SDL_MOUSEBUTTONDOWN) {
//                if (e.button.button == SDL_BUTTON_LEFT) {
//                    if (flag) flag = false;
//                    else flag = true;
//
//                }
//            }
//
//
//        }
//
//        SDL_SetRenderDrawColor(rend,255,255,255,255);
//        SDL_RenderClear(rend);
//
//        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
//        //SDL_RenderDrawLine(rend,100,100,posX,posY);
//        SDL_RenderFillRect(rend,&rect);
//        
//
//        SDL_RenderPresent(rend);
//       
//
//    }
//
//    return 0;
//
//
//}
