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
//     SDL_CreateWindowAndRenderer(
//       
//        680, 480,
//        0,&window,&rend);
//
//
//    SDL_RenderSetScale(rend, 1,1);
//    
//    float r, g, b;
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
//                running = false;
//                }
//
//            }
//            if (e.type == SDL_MOUSEBUTTONDOWN) {
//                if (e.button.button == SDL_BUTTON_LEFT) {
//                    std::cout << "Helfkla" << std::endl;
//                }
//            }
//
//
//        }
//
//
//        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
//        SDL_RenderClear(rend);
//
//
//
//
//      for (int i = 0; i < 0; i++) {
//
//            float v1 = rand() % 680;
//            float v2 = rand() % 480;
//        /*    r = rand() % 255;
//            g = rand() % 255;
//            b = rand() % 255;*/
//
//
//            SDL_SetRenderDrawColor(rend, r, g, b, 255);
//
//            for (int i = 0;i < 500; i++) {
//
//                SDL_RenderDrawPoint(rend, v1 + 100 * sin(i), v2 + 100 * cos(i));
//            }
//
//     }
//
//
//
//
//        SDL_RenderPresent(rend);
//        //SDL_Delay(10);
//
//    }
//   
//    return 0;
//
//   
//}
