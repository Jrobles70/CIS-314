//
// Created by Justin on 10/4/2017.
//
#include <stdio.h>

// Use the following code for f2u:
unsigned f2u(float f) {
    return *((unsigned*)&f);
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    printf("%f %f\n", (x,y));
    printf("%x %x\n", (x,y));
    printf("%x %x\n", (ux,uy));
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    printf("%x %x\n", (sx,sy));

    /* Give an expression using only ux, uy, sx, and sy */
    // there are a few cases we must consider:
    // 1: That x is negative and y is positive
    // 2: That x and y have the same sign (+ or -)
    //      2a: x is smaller
    //      2b: y is smaller
    // so in case 1
    return (sx > sy) | (ux < uy);
}

main() {
    float x = 1;
    float y = 2;
    if (float_le(x, y)){
        printf("TRUE");
    } else {
        printf("FALSE");
    }
}