#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* read_array_of_int(size_t size);
int get_minimum(int *array, size_t size);
int get_maximum(int *array, size_t size);
double get_average(int *array, size_t size);


int main() {
    size_t size;
    int *array;

    int min, max;
    double average;

    printf("Enter the list size: ");
    scanf("%ld", &size);

    array = read_array_of_int(size);

    min = get_minimum(array, size);
    max = get_maximum(array, size);
    average = get_average(array, size);

    printf("min = %d max = %d average = %lf\n", min, max, average);

    return EXIT_SUCCESS;
}


int* read_array_of_int(size_t size) {
    int *array = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    return array;
}

int get_minimum(int *array, size_t size) {
    if (size == 1) {
        return array[0];
    }

    int min = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int get_maximum(int *array, size_t size) {
    if (size == 1) {
        return array[0];
    }

    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

double get_average(int *array, size_t size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}

