#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize(int number) {
    int factor1 = 1;
    int factor2 = number;

    // Handle special case for even numbers
    if (number % 2 == 0) {
        factor1 = 2;
        factor2 = number / 2;
        printf("%d=%d*%d\n", number, factor1, factor2);
        return;
    }

    // Iterate only odd numbers up to the square root of 'number'
    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            factor1 = i;
            factor2 = number / i;
            printf("%d=%d*%d\n", number, factor1, factor2);
            return;
        }
    }

    printf("%d=%d*%d\n", number, factor1, factor2);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int number;

    while (fscanf(file, "%d", &number) == 1) {
        factorize(number);
    }

    fclose(file);

    return EXIT_SUCCESS;
}
