//
// Created by Justin on 10/4/2017.
//


#include <stdio.h>

typedef unsigned packed_t;
// A: This code works fine with returning unsigned ints but does not work with negative numbers.
//    The problem with this code is that it is returning an unsigned int because a signed int
//    was never declared. I found that using '| ~(0xFF)' instead of '& 0xFF' worked fine but I do not think
//    that meets the requirement to only use left and right shifts and a subtraction.

int xbyteOLD(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF;
}

int xbyte(packed_t word, int bytenum) {
    // Moving the byte we want to the most significant byte and shifting the word right 24 times is the
    // same as using the original code with | ~(0xFF)
    signed byte = (word << ((3 - bytenum) << 3));
    return byte >> 24;
}

int test_xbyte(packed_t word, int bytenum) {
    printf("Input: %x\n", word);
    signed test = xbyte(word, bytenum);
    printf("Returned int: %i\n", test);
    printf("Returned hex: %x\n", test);
}
    main(){
    test_xbyte(0xFFFEFDFC, 0);
    return 0;
    }