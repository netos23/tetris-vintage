#include <stdio.h>
#include <process.h>
#include <windows.h>
#include "tetris_core.h"

void render(const byte *screen, byte w, byte h) {

    char *row = calloc(h, sizeof(char));
    //char row[h];
    for (byte r = 0; r < h; r++) {
        for (byte c = 0; c < w; c++) {
            byte pos = screen[r] >> (w - 1 - c);
            pos &= NUM_MASK;

            row[c] = pos ? '#' : ' ';
        }
        printf("%s\n",row);
    }
    free(row);

}

int main() {
    int n = 3;
    byte *part = calloc(n, sizeof(byte));

    part[0] = 0b000;
    part[1] = 0b001;
    part[2] = 0b111;

    render(part, n, n);
    byte count = 4;
    while (1){
        //ClearScreen();
        system("cls");
        rotate(part, n);
        render(part, n, n);
        Sleep(100);
    }

    return 0;
}
