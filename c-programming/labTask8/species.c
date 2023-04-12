#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef enum { MAMMAL, INSECT, BIRD, FISH } AnimalType;

typedef struct {
    char name[128];
    double size;
    AnimalType type;
} Animal;

int main(void) {

    Animal *species = malloc(sizeof(Animal));
    int capacity = 1;
    int num_species = 0;
    bool done = false;

    while (!done) {
        printf("Enter animal information (\"exit\" to exit)\n");
        printf("What is the name: ");
        if (scanf("%127s", species[num_species].name) != 1) {
            perror("Invalid input");
            exit(EXIT_FAILURE);
        }

        if (strcmp(species[num_species].name, "exit") == 0) {
            done = true;
            continue;
        }

        printf("What is the size: ");
        if (scanf("%lf", &species[num_species].size) != 1) {
            perror("Invalid input");
            exit(EXIT_FAILURE);
        }

        printf("What is the type (mammal, insect, bird, fish): ");
        char type_str[128];
        if (scanf("%127s", type_str) != 1) {
            perror("Invalid input");
            exit(EXIT_FAILURE);
        }

        if (strcmp(type_str, "mammal") == 0) {
            species[num_species].type = MAMMAL;
        } else if (strcmp(type_str, "insect") == 0) {
            species[num_species].type = INSECT;
        } else if (strcmp(type_str, "bird") == 0) {
            species[num_species].type = BIRD;
        } else if (strcmp(type_str, "fish") == 0) {
            species[num_species].type = FISH;
        } else {
            printf("Invalid type\n");
            continue;
        }

        num_species++;

        if (num_species >= capacity) {
            capacity *= 2;
            species = realloc(species, capacity * sizeof(Animal));
            if (species == NULL) {
                perror("Cannot realloc");
                exit(EXIT_FAILURE);
            }
        }
    }

    printf("The following new species were found:\n");
    for (int i = 0; i < num_species; i++) {
        printf("%-20s has size %6.2f and is a ", species[i].name, species[i].size);
        switch (species[i].type) {
            case MAMMAL:
                printf("mammal\n");
                break;
            case INSECT:
                printf("insect\n");
                break;
            case BIRD:
                printf("bird\n");
                break;
            case FISH:
                printf("fish\n");
                break;
        }
    }

    free(species);

    return EXIT_SUCCESS;
}

