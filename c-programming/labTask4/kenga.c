#include <stdio.h>
#include <stdlib.h>

#define ROAD_WIDTH 10.0
#define ROADKILL_PROBABILITY 1.47

int main() {
    float side_length, roads_length, roos_density, road_surface_area, expected_kills;

    printf("\x1B[3mEnter side of square in km:\x1B[0m ");
    scanf("%f", &side_length);

    printf("\x1B[3mEnter roads length in km:\x1B[0m ");
    scanf("%f", &roads_length);

    printf("\x1B[3mEnter number of 'roos:\x1B[0m ");
    scanf("%f", &roos_density);

    // Calculate kangaroo density in roos per square kilometer
    roos_density /= side_length * side_length;

    // Calculate road surface area in square kilometers
    road_surface_area = roads_length * ROAD_WIDTH / 1000.0;

    // Calculate expected number of kills per year
    expected_kills = roos_density * road_surface_area * ROADKILL_PROBABILITY;

    printf("Expected number of kills is: %.1f\n", expected_kills);

    return EXIT_SUCCESS;
}

