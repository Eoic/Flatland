#include "vector.h"

#include <math.h>

float magnitude(Vector2D *vector) { return sqrtf(vector->x * vector->x + vector->y * vector->y); }

Vector2D normalized(Vector2D *vector) {
    float mag = magnitude(vector);

    if (mag == 0.0) {
        return (Vector2D){.x = 0, .y = 0};
    }

    return (Vector2D){.x = vector->x / mag, .y = vector->y / mag};
}