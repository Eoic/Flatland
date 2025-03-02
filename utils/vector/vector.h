#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    float x;
    float y;
} Vector2D;

float magnitude(Vector2D *vector);

Vector2D normalized(Vector2D *vector);

#endif