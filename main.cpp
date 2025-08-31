#include <SDL2/SDL.h>
#include<iostream>
using namespace std;

void init_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error(SDL_GetError());
    }
}

SDL_Window* create_window()
{
    SDL_Window* window = SDL_CreateWindow(
        "Snake",                     // window title
        SDL_WINDOWPOS_CENTERED,      // x position
        SDL_WINDOWPOS_CENTERED,      // y position
        800,                         // width
        600,                         // height
        SDL_WINDOW_SHOWN             // flags
    );
    if (!window) {
        throw std::runtime_error(SDL_GetError());
    }
    return window;
}


int main(int argc, char const *argv[])
{
    init_sdl();
    SDL_Window* window = create_window();

    // Event loop
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_Delay(16); // ~60 FPS wait
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
