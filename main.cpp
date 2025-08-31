#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include<iostream>
using namespace std;

void init_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error(SDL_GetError());
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
    if (!window)
        throw std::runtime_error(SDL_GetError());

    return window;
}

SDL_GLContext get_opengl_context(SDL_Window* window)
{
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        throw std::runtime_error(SDL_GetError());
    }
    return glContext;
}

void write_hello_world(){
    // Clear screen (black)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a simple triangle (modern OpenGL would use shaders)
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f);
    glEnd();
}

int main(int argc, char const *argv[])
{
    init_sdl();
    SDL_Window* window = create_window();
    SDL_GLContext glContext = get_opengl_context(window);
    
    // Event loop
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        write_hello_world();

        SDL_GL_SwapWindow(window);
        SDL_Delay(16); // ~60 FPS wait
    }

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
