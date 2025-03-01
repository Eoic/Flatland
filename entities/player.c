#include "./player.h"

#include "../utils/vector.h"

void init_player(Player *player, SDL_Color color, int window_width, int window_height) {
    player->speed = 0.7;
    player->color = color;

    int w = 50, h = 50;
    int x = window_width / 2 - w / 2;
    int y = window_height / 2 - h / 2;
    player->shape = (SDL_FRect){.x = x, .y = y, .w = w, .h = h};
    player->ghost_shape = (SDL_FRect){.x = x, .y = y, .w = w, .h = h};
}

void handle_player_input(Player *player, double deltaTime) {
    bool const *keys = SDL_GetKeyboardState(NULL);
    player->direction.x = (keys[SDL_SCANCODE_A] ? -1.0 : 0.0) + (keys[SDL_SCANCODE_D] ? 1.0 : 0.0);
    player->direction.y = (keys[SDL_SCANCODE_W] ? -1.0 : 0.0) + (keys[SDL_SCANCODE_S] ? 1.0 : 0.0);
    player->shape.x += player->direction.x * player->speed * deltaTime;
    player->shape.y += player->direction.y * player->speed * deltaTime;
}

void update_player(Player *player, int window_width, int window_height) {
    player->ghost_shape = player->shape;
    player->is_clipping_x = (player->shape.x < 0) || (player->shape.x + player->shape.w > window_width);
    player->is_clipping_y = (player->shape.y < 0) || (player->shape.y + player->shape.h > window_height);

    if (player->shape.x < 0) {
        player->ghost_shape.x = window_width + player->shape.x;
    } else if (player->shape.x + player->shape.w > window_width) {
        player->ghost_shape.x = player->shape.x - window_width;
    }

    if (player->shape.y < 0) {
        player->ghost_shape.y = window_height + player->shape.y;
    } else if (player->shape.y + player->shape.w > window_height) {
        player->ghost_shape.y = player->shape.y - window_height;
    }

    if (player->shape.x < -player->shape.w || player->shape.x > window_width || player->shape.y < -player->shape.w ||
        player->shape.y > window_height) {
        player->shape.x = player->ghost_shape.x;
        player->shape.y = player->ghost_shape.y;
        player->is_clipping_x = player->is_clipping_y = false;
    }
}

void render_player(Player *player, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, player->color.r, player->color.g, player->color.b, player->color.a);
    SDL_RenderFillRect(renderer, &player->shape);

    if (player->is_clipping_x || player->is_clipping_y) {
        SDL_SetRenderDrawColor(renderer, player->color.r, player->color.g, player->color.b, player->color.a);
        SDL_RenderFillRect(renderer, &player->ghost_shape);
    }

    render_gizmos(player, renderer);
}

void render_gizmos(Player *player, SDL_Renderer *renderer) {
    float mx, my;
    SDL_GetMouseState(&mx, &my);
    float px = player->shape.x + player->shape.w / 2;
    float py = player->shape.y + player->shape.h / 2;
    Vector2D line = normalized(&(Vector2D){.x = mx - px, .y = my - py});
    SDL_RenderLine(renderer, px, py, px + line.x * 100, py + line.y * 100);
}