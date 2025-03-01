#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

#include "entities/player.h"

typedef struct {
    double x;
    double y;
} Vector2D;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Surface *surface = NULL;
static const int WIDTH = 800;
static const int HEIGHT = 600;
int win_width = WIDTH;
int win_height = HEIGHT;
Player player;
Uint64 NOW = 0;
Uint64 LAST = 0;
double delta_time = 0;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    if (!SDL_CreateWindowAndRenderer("Flatland", WIDTH, HEIGHT, SDL_WINDOW_EXTERNAL | SDL_WINDOW_RESIZABLE, &window,
                                     &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    surface = SDL_CreateSurface(WIDTH, HEIGHT, SDL_PIXELFORMAT_ARGB32);
    init_player(&player, (SDL_Color){.a = 255, .r = 255, .g = 128, .b = 64});

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    if (event->type == SDL_EVENT_WINDOW_RESIZED) {
        SDL_GetWindowSize(window, &win_width, &win_height);
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    delta_time = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

    handle_player_input(&player, delta_time);
    update_player(&player, win_width, win_height);

    SDL_SetRenderDrawColor(renderer, 20, 26, 20, 255);
    SDL_RenderClear(renderer);

    render_player(&player, renderer);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) { printf("%s\n", "Bye..."); }
