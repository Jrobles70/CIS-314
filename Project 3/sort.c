#include <stdio.h>
#include <stdlib.h>


int* readArray(int count) {
    // read in an int count n from the user,
    // allocate an array of ints of size n on the heap using malloc(),
    // read n ints from the user to fill the array, return the array.
    int *a;

    a = (int *)malloc(sizeof(int)*count);

    if(a == NULL){
        printf("Something went wrong\n");
        return 0;
    }
    int i;
    for(i = 0; i < count; i++){
        printf("Enter the next number: \n");
        scanf("%d",&a[i]);
    }
    return a;
}


void swap(int *xp, int *yp){
    // swaps the int values stored at the xp and yp pointers.
    int temp_val = *xp;
    *xp = *yp;
    *yp = temp_val;
}


void sortArray(int *array, int length){
    // sorts the input array using Selection Sort
    // (Google it) by repeatedly calling your swap function as appropriate.

}


void printArray(int *array, int length){
    // prints the array (e.g., “[ 1, 3, 5, 7 ]”).
    int i;
    for (i = 0; i < length; i++){
        if(i == 0){
            printf("[ %d, ", array[i]);
        } else if(i == length - 1) {
            printf("%d ]\n", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
}
main() {
    // call readArray to create an array, call sortArray to sort it, call printArray
    // to print the result, then free the heap memory used by the array.
    int *a = readArray(5);
    printArray(a, 5);
    swap(&a[0],&a[1]);
    printArray(a,5);

}