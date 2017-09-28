//
// Created by Justin on 9/28/2017.
// Used Figure 2.4 for help
//

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_double(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

int main() {
    show_short(30000);
    show_double(10.10);
    show_long(12345678910l);
}