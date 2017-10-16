#include <stdio.h>
#include <stdlib.h>


int* readArray(int count) {
    // read in an int count n from the user,
    // allocate an array of ints of size n on the heap using malloc(),
    // read n ints from the user to fill the array, return the array.

    // Declare a pointer
    int *a;

    // Allocate memory for the pointer
    // multiply the size of an int * the number the user wants
    a = (int *)malloc(sizeof(int)*count);

    // I found a few sources online that all say it is good to
    // check that the memory was allocated correctly
    if(a == NULL){
        printf("Something went wrong\n");
        return 0;
    }

    int i;
    for(i = 0; i < count; i++){
        // Ask user for n numbers
        printf("Enter the next number: \n");
        scanf("%d",&a[i]);
    }
    return a;
}


void swap(int *xp, int *yp){
    // Swaps the int values stored at the xp and yp pointers.
    // Save the pointer for the x value for later use
    int temp_val = *xp;
    // make x pointer = y pointer
    *xp = *yp;
    // Lastly make y pointer = the temporary value (x pointer)
    *yp = temp_val;
}


void sortArray(int *array, int length){
    // sorts the input array using Selection Sort
    // (Google it) by repeatedly calling your swap function as appropriate.
    int i;
    int j;
    int lowest_index;
    for(i = 0; i < length; i++) {
        // checks each value in array
        // index i is default lowest value that needs to be compared to others
        lowest_index = i;
        for (j = i; j < length; j++) {
            if (array[lowest_index] > array[j]) {
                // starts at the Ith value and compares the rest of the values to find lowest
                // if the value at j is lower than the lowest index change it to j
                lowest_index = j;
            }
        }
        if(lowest_index != i){
            // if the lowest index has not changed skip this step
            // Sends the address of both values to swap
            swap(&array[lowest_index], &array[i]);
        }
    }
}


void printArray(int *array, int length){
    // prints the array (e.g., “[ 1, 3, 5, 7 ]”).
    int i;
    for (i = 0; i < length; i++){
        // for each value in the array print the letter
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
    sortArray(a, 5);
    printArray(a, 5);
    free(a);
}