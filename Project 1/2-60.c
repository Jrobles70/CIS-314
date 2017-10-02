//
// Created by Justin on 9/28/2017.
//

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
    // When moving i over 3 bits we move i into the next 4 bits which is the same as i * 8
    // ex. i = 3 (binary: 0011)
    // i << 3 (binary: 0001 1000)
    // 0001 1000's decimal value is 24

    int shifts = i << 3;
    printf("Shifts: %X\n", shifts);

    // Makes a mask to use on the x value so you can erase the byte you want to replace by shifting
    // ff by the same amount and getting the inverse of that
    // 0xFF == 1111 1111
    // 0xFF << shifts == FF00FFFF
    unsigned mask = 0xFF << shifts;
    mask = ~mask;
    printf("Mask: %X\n", mask);

    // When you use the & operator on x and the mask you now get:
    // 12345678
    // 11001111
    //&--------
    // 12005678
    x = x & mask;
    printf("x & mask: %X\n", x);

    // Lastly to add b into the byte you remove you must use the or operator
    // 12005678
    // 00AB0000
    //|--------
    // 12AB5678
    return x | (b << shifts);
}

int main() {
    printf("%X\n\n", replace_byte(0x12345678, 2, 0xAB));
    printf("%X\n\n", replace_byte(0x12345678, 0, 0xAB));
}