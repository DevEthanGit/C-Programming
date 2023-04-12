#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_STRING_LENGTH 128

typedef char String[MAX_STRING_LENGTH];
//-----------------------------------------------------------------------------
int main(void) {

    float MyFloat;
    unsigned long int BitPattern;

    printf("The size of char is %ld\n",sizeof(char));
    printf("The size of short is %ld\n",sizeof(short));
    printf("The size of int is %ld\n",sizeof(int));
    printf("The size of long is %ld\n",sizeof(long));
    printf("The size of long long is %ld\n",sizeof(long long));
    printf("The size of float is %ld\n",sizeof(float));
    printf("The size of double is %ld\n",sizeof(double));
    printf("The size of long double is %ld\n",sizeof(long double));
    printf("The size of String is %ld\n",sizeof(String));
    printf("The size of 'A' is %ld\n",sizeof('A'));
    printf("The size of (char)'A' is %ld\n",sizeof((char)'A'));
    printf("The size of \"abcdefg\" is %ld\n",sizeof("abcdefg"));
    printf("The size of MyFloat is %ld\n",sizeof(MyFloat));
    printf("The size of BitPattern is %ld\n",sizeof(BitPattern));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
