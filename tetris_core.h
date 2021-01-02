//
// Created by nikmo on 24.12.2020.
//

#ifndef TETRIS_VINTAGE_TETRIS_CORE_H
#define TETRIS_VINTAGE_TETRIS_CORE_H

#include "math.h"
#include <malloc.h>

#define  NUM_MASK 1
#define SCREEN_X 8
#define SCREEN_Y 20


typedef struct {
    byte *texture;
    byte n;
    byte x, y;
} part;

void clear_empty_rows();

void clear_empty_columns();

void copy(const byte *src, byte *dest, byte n);

void clear_buffer(byte *buffer, byte n);

void rotate(byte *part, byte n);

byte handle_collision(part *cur_part, byte *screen);

byte get_bit_mask(byte x, byte n);

void update();

#endif //TETRIS_VINTAGE_TETRIS_CORE_H
