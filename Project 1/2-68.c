//
// Created by Justin on 9/28/2017.
//
#include <stdio.h>

int lower_on_mask(int n){
    // For the case where n = w you will get an error when shifting a w-bit word w-times. In the book it tells you that
    // to get a w-bit word with 8 1's in the least significant bits you use (1 << 8) - 1
    // 1 == 0001
    // 1 << 8 == 0001 0000 0000
    // (1 << 8) - 1 == 1111 1111
    // to make this work with (n-1) to get a 32-bit mask with 32 1's you must start with 2 instead of 1
    // 2 == 0010
    // (2 << 31) == 0001 0000 0000 0000 0000
    // (2 << 31) - 1  == 1111 1111 1111 1111

    signed mask = (2 << (n-1)) - 1;
    printf("mask shifted %i spots: %X\n", n, mask);
    return mask;
}

int main() {
    lower_on_mask(1);
    lower_on_mask(2);
    lower_on_mask(3);
    lower_on_mask(5);
    lower_on_mask(32);
}