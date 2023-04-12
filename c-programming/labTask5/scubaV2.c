#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main() {
    int depth, percentage_O2;
    double feet_per_atm = 33.0;
    double ambient_pressure, O2_pressure;
    char oxygen_pressure_group;
    bool exceeds_maximal_O2_pressure, exceeds_contingency_O2_pressure;

    printf("Enter depth and percentage O2: ");
    scanf("%d %d", &depth, &percentage_O2);

    ambient_pressure = depth / feet_per_atm + 1;
    O2_pressure = (percentage_O2 / 100.0) * ambient_pressure;
    oxygen_pressure_group = 'A' + (int)(O2_pressure / 0.1);
    exceeds_maximal_O2_pressure = O2_pressure > 1.4;
    exceeds_contingency_O2_pressure = O2_pressure > 1.6;

    printf("Ambient pressure: %.1f\n", ambient_pressure);
    printf("O2 pressure: %.2f\n", O2_pressure);
    printf("O2 group: %c\n", oxygen_pressure_group);
    printf("Exceeds maximal O2 pressure: %s\n", exceeds_maximal_O2_pressure ? "true" : "false");
    printf("Exceeds contingency O2 pressure: %s\n", exceeds_contingency_O2_pressure ? "true" : "false");

    return EXIT_SUCCESS;
}

