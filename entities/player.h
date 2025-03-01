#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

typedef struct {
    double dx, dy;
    double speed;
    SDL_FRect shape;
    SDL_FRect ghost_shape;
    bool is_clipping_x, is_clipping_y;
    SDL_Color color;
} Player;

void init_player(Player *player, SDL_Color color);
void handle_player_input(Player *player, double deltaTime);
void update_player(Player *player, int window_width, int window_height);
void render_player(Player *player, SDL_Renderer *rendered);

#endif