//
// Created by Justin on 9/28/2017.
//

#include <stdio.h>

int any_odd_one(unsigned x){
    // By creating a mask with a 1 in every odd position and a 0 in every even position (which is 0xAAAAAAAA when w=32)
    // you can use the & operator to compare x & mask so you are left with either 0 or a non-zero number.
    // Using && to compare 1 and the new number leaves us with two non zero numbers which returns 1 (True) or
    // one 0 and one non zero which returns 0 (False)
    
    unsigned mask = 0xAAAAAAAA;
    printf("%x & 0xAAAAAAAA: %X\n", x, (x & mask) && 1);
    return (x & mask) && 1;
}

int main() {
    any_odd_one(0x0);
    any_odd_one(0x1);
    any_odd_one(0x2);
    any_odd_one(0x3);
    any_odd_one(0xFFFFFFFF);
    any_odd_one(0x55555555);
}