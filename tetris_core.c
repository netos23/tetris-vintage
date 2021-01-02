#include "tetris_core.h"

void clear_empty_rows() {

}

void clear_empty_columns() {

}

void copy(const byte *src, byte *dest, byte n) {
    for (byte i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void clear_buffer(byte *buffer, byte n) {
    for (byte i = 0; i < n; i++) {
        buffer[i] = 0;
    }
}

void rotate(byte *part, byte n) {
    byte *buffer = calloc(n, sizeof(byte));
    clear_buffer(buffer, n);

    for (byte r = 0; r < n; r++) {

        for (byte c = 0; c < n; c++) {
            byte val = part[r] >> (n - 1 - c);
            val &= NUM_MASK;
            buffer[c] |= val << r;
        }
    }

    copy(buffer, part, n);
    free(buffer);
}

byte handle_collision(part *cur_part, byte *screen) {
    byte x = cur_part->x;
    byte y = cur_part->y;
    byte n = cur_part->n;
    byte res = 0;

    if (x >= 0 && x < SCREEN_X && y < SCREEN_Y) {
        byte stop = min((y + n), SCREEN_Y);
        for (byte r = y; r < stop; r++) {
            if (y < 0) continue;
            
            byte contact = impl(screen[r], ~cur_part->texture[r - y]);
            contact |= get_bit_mask(x, n);
            res |= ~contact;
        }
        return res;
    } else {
        return 1;
    }
}

byte get_bit_mask(byte x, byte n){
    byte mask = ~0;
    byte stop = x + n;
    for(byte i = x + 1; i <= stop; i++){
        mask ^= 1 << (SCREEN_X - i);
    }
}