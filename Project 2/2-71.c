//
// Created by Justin on 10/4/2017.
//


#include <stdio.h>

typedef unsigned packed_t;

int xbyteOLD(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF;
}

int xbyte(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF;
}

int test_xbyte(packed_t word, int bytenum) {
    printf("Input: %x\n", word);
    signed test = xbyte(word, bytenum);
    if (word * -1 == test) {
        printf("SUCCESS");
    } else {
        printf("Wrong output\nShould be: %x\n", word * -1);
        printf("Returned int: %i\n", test);
    }

    printf("Returned hex: %x\n", test);
}
    main(){
    test_xbyte(-100, 0);
    return 0;
    }