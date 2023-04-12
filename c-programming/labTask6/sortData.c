#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 5

typedef int* IntPointer;

void initialize(int integers[N]) {
    srand(getpid());
    for (int i = 0; i < N; i++) {
        integers[i] = rand();
    }
}

void initializeP(IntPointer pointers[N], int integers[N]) {
    for (int i = 0; i < N; i++) {
        pointers[i] = &integers[i];
    }
}

void printI(int integers[N]) {
    printf("---- Array of integers ----\n");
    for (int i = 0; i < N; i++) {
        printf(" %2d : %10d\n", i, integers[i]);
    }
}

void printP(IntPointer pointers[N]) {
    printf("---- Array of pointers ----\n");
    for (int i = 0; i < N; i++) {
        printf(" %2d : %10d\n", i, *pointers[i]);
    }
}

void bSP(IntPointer pointers[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (*pointers[j] > *pointers[j + 1]) {
                IntPointer temp = pointers[j];
                pointers[j] = pointers[j + 1];
                pointers[j + 1] = temp;
            }
        }
    }
}

void bSI(int integers[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (integers[j] > integers[j + 1]) {
                int temp = integers[j];
                integers[j] = integers[j + 1];
                integers[j + 1] = temp;
            }
        }
    }
}

int main() {
    int integers[N];
    IntPointer pointers[N];

    initialize(integers);
    initializeP(pointers, integers);

    printI(integers);

    bSP(pointers);

    printf("\n");
    printP(pointers);

    bSI(integers);

    printf("\n");
    printI(integers);

    printf("\n");
    printP(pointers);

    return EXIT_SUCCESS;
}
