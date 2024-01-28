#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
SDL_Window *Window = NULL;
SDL_Renderer *Renderer = NULL;

void QUIT()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
int SDL_main(int argc, char *argv[])
{
    printf("hello\n");
    SDL_Init(SDL_INIT_VIDEO);

    Window = SDL_CreateWindow("Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 1000, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event MainEvent;
    while (SDL_WaitEvent(&MainEvent))
    {
        switch (MainEvent.type)
        {
        case SDL_QUIT:
            QUIT();
            break;
        case SDL_KEYDOWN:
            printf("keydown\n");
            switch (MainEvent.key.keysym.sym)
            {
            case SDLK_RETURN:
                printf("enter\n");
                break;
            case SDLK_1:
                printf("1");
                break;
            default:
                break;
            }
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEBUTTONUP:
            break;
        case SDL_MOUSEMOTION:
            break;
        default:
            break;
        }
    }
    QUIT();
}