//
// Created by Justin on 10/4/2017.
//

/* Copy integer into buffer if space is available */
#include <mem.h>
#include <stdio.h>

/* WARNING: The following code is buggy */
void copy_intOLD(int val, void *buf, int maxbytes) {
    if (maxbytes-sizeof(val) >= 0) {
        memcpy(buf, (void *) &val, sizeof(val));
        // If this print statement prints then that means there is a bug in the code since I made the
        // maxbytes = 0
        printf("copy_intOLD: Bug");
    }
}

void copy_int(int val, void *buf, int maxbytes) {
    // Changing this to a comparison fixes the casting issue from before and allows this code to run
    // properly. "copy_intOLD: Bug" will print but "copy_int: Bug" will not
    if (maxbytes >= sizeof(val)) {
        memcpy(buf, (void *) &val, sizeof(val));
        printf("copy_int: Bug");
    }
}

main(){
    int a = 10;
    int* buf = &a;
    copy_intOLD(1, buf, 0);
    copy_int(1, buf, 0);
}

// A: This does not work because ints are signed by default but the value of size_t is
//    unsigned since it will never be a negative value. So in this case the unsigned value
//    casts the signed value to an unsigned int as well.

// B: we could correct this by comparing maxbytes to sizeof(val) rather than subtracting
//