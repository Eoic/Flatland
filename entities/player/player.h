#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

#include "../../utils/vector/vector.h"

extern const Uint8 PLAYER_SIZE;

typedef struct {
    double speed;
    Vector2D direction;
    SDL_FRect shape;
    SDL_FRect ghost_shape;
    bool is_clipping_x, is_clipping_y;
    SDL_Color color;
} Player;

void init_player(Player *player, SDL_Color color, int window_width, int window_height);
void handle_player_input(Player *player, double deltaTime);
void update_player(Player *player, int window_width, int window_height);
void render_player(Player *player, SDL_Renderer *rendered);
void render_gizmos(Player *player, SDL_Renderer *renderer);

#endif