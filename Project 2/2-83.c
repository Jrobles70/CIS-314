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
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx, and sy */

    // there are a few cases we must consider:
    //
    // 1: That x is negative and y is positive
    // 2: That x and y have the same sign and (x < y)
    //
    // case 1: 1 means negative, 0 means positive so if (sx > sy) then (x < y)
    // case 2: if signs are same (sx == sy) and (ux < uy) then (x < y)

    return (sx > sy) | ((sx == sy) && (ux < uy));
}

int main() {
    float x = -9.99;
    float y = -9.99;
    if (float_le(x, y)){
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    return 0;
}