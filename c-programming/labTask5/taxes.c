#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//I DONT LIKE  this my laptop blue screened while coding this had to go to my pc.
#define MAX_SIZE 20

int main() {
    double tax = 0;
    char tax_group;
    double arr[MAX_SIZE];
    int num_elements = 0;
    double num;
    bool irsInput = true;
    double income = 0;
    double deduction = 0;
    double taxable_income = 0;

    while (irsInput) {
        if (num_elements >= MAX_SIZE) {
            printf("Array is full\n");
            irsInput = false;
        }

        printf("Enter next amount: ");
        scanf("%lf", &num);

        if (num == 0) {
            irsInput = false;
        } else if (num > 0) {
            income += num;
            arr[num_elements] = num;
            num_elements++;
        } else if (num < 0) {
            if (-num <= income - deduction) {
                deduction += -num;
                arr[num_elements] = num;
                num_elements++;
            } else {
                printf("Deduction exceeds income - deduction. Ignoring input.\n");
            }
        }
    }

    taxable_income = income - deduction;
    if (taxable_income >= 500000) {
        tax_group = 'S';
        tax = taxable_income * 0.25;
    } else if (taxable_income >= 200000) {
        tax_group = 'Q';
        tax = taxable_income * 0.25;
    } else if (taxable_income >= 100000) {
        tax_group = 'M';
        tax = taxable_income * 0.10;
    } else if (taxable_income >= 50000) {
        tax_group = 'A';
        tax = taxable_income * 0.03;
    } else if (taxable_income >= 20000) {
        tax_group = 'R';
        tax = taxable_income * 0.03;
    } else {
        tax_group = 'P';
    }

    if (tax_group == 'P') {
        tax = 0;
    } else {
        if (tax < 50000) {
            tax = 50000;
        }
    }

    printf("Income         = $%.2f\n", income);
    printf("Deductions     = $%.2f\n", deduction);
    printf("Taxable Income = $%.2f\n", taxable_income);
    printf("Tax group      = %c\n", tax_group);
    printf("Tax owed       = $%.2f\n", tax);

    return EXIT_SUCCESS;
}

