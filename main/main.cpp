#include <iostream>
#include <SDL2/SDL.h>

#include "DemoDrawer/Controller.h"

using namespace std;

int main()
{
    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 300;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "GamedevMathProblems",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        cout << "Couldn't create window: " << SDL_GetError() << endl;
        return 0;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event *mainEvent = new SDL_Event();
    Controller controller(renderer);
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(mainEvent)) {
            if (mainEvent->type == SDL_QUIT) quit = true;
            else controller.addEvent(mainEvent);
        }
        controller.processEvents();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);
        controller.draw();
        SDL_RenderPresent(renderer);
    }

    delete mainEvent;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
