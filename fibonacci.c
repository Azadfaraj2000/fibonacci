#include <stdio.h>
#include <stdlib.h>
long* make_long_array(long n){
     int i;
     long *a; // array.

    a = /* (int*) no need to cast */ malloc(sizeof( long /*s, remember? *) */ ) * n);
    if (a == NULL) {
        printf("ERROR: Out of memory\n");  // puts()/fputs() would be sufficient.
        return /* 1 */ NULL;
    }
    for (size_t i = 0; i < n; ++i )
        a[i] = 0;
    // return *a; you don't want to return the first long in the memory allocated
    return a; //the address we got from malloc()
}

void use_make_long_array(long n) {
    int i;
    long *p = make_long_array(n);
    printf("In use_make_long_array(%ld)\n", n);
    /* if p is not NULL, we could allocate memory, and we proceed with testing: */
    if (p != NULL) {
        /* write some data to the array -- if the allocated memory is too short, this might trigger a
        segfault*/
        for (i=0; i<n; i++) { p[i]=i+42;
        /* just write some data */
        }
        /* free array -- if the allocated array is too short, we may have corrupted malloc/free
        metadata when writing the i+42 data above, and this may show when we call the free
        command: */
        free(p);
        /* if the program does not crash, it is a good sign [but no proof for correctness]. The other
        way round: if the program segfaults or crashes, this is not a good sign. */
    }
    else { /* we get here if memory allocation didn't work for some reason. */
     printf("Error - it seems that the memory allocation failed.\n");
     }
}
long* make_fib_array(long n){

int i;
long *fib;
fib = (long*)malloc(sizeof(long)*n);
if (fib == NULL){
    printf("ERROR: Out of memory\n");
    return NULL;
}

*fib = 0;
*(fib +1) = 1;
for (i=2;i<n;i++){
    *(fib +i) = *(fib + (i-1)) + *(fib + (i-2));}
for(i=0;i<n;i++){
    printf("%ld\n",*(fib + i));}
return fib;
}
int main(void) {
    long int num =25;
    make_fib_array(num);
    return 0;
}
