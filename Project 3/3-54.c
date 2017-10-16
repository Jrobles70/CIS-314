#include <stdio.h>


int decode2(int x, int y, int z){
    // x at %ebp+8,
    // y at %ebp+12,
    // z at %ebp+16
    // operation (Src, Dest)

    // movl   12(%ebp), %edx
    // We are moving the pointer at 12(%ebp) to %edx
    // So edx = y
    int edx = y;

    // subl   16(%ebp), %edx
    // dest = dest - src
    // so this means that edx = y -z
    edx -= z;

    // movl   %edx, %eax
    // moving %edx to %eax
    // So eax = edx = y - z
    int eax = edx;

    // sall   $31, %eax
    // Arithmetic left shift
    // shift eax right 31 spots
    eax = eax << 31;

    // sarl   $31, %eax
    // Arithmetic right shift
    // shift eax right 31 times
    eax = eax >> 31;

    // imull   8(%ebp), %edx
    // dest = dest * src
    // edx = edx*x
    edx *= x;

    // xorl   %edx, %eax
    // exclusive or operator
    // eax = eax ^ edx
    eax = eax ^ edx;

    // Function returns value at eax
    return eax;
}

void main() {
    printf("%d\n", decode2(1, 2, 4));
    printf("%d\n", decode2(-4, -8, -12));
}