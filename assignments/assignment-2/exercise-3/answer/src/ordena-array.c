#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../lib/sortlib.c"

// Function prototypes

/* Create an array of `array_size` integers in execution time and then insert
   random integers into it.
   `array_size` must be different from 0, otherwise NULL will be returned.
   Return a reference to the first integer of the array.  */
int *create_array_of_random_integers(size_t array_size);

/* Write all elements of an integer array, separated by space and with a newline
   after the last element, to stdout.
   If `array_size` is equal to 0, then just write a newline.  */
void print_array_of_integers(int *array, size_t array_size);

// Function implementations

int main() {
    const size_t ARRAY_SIZE = 10;
    pid_t child_process_id;

    int *array = create_array_of_random_integers(ARRAY_SIZE);

    // Try to create a child process.
    child_process_id = fork();

    // If it is the parent process.
    if (child_process_id > 0) {
        bubbleSort(array, ARRAY_SIZE);
        puts("I am the parent process and I used the bubble sort algorithm.");
        print_array_of_integers(array, ARRAY_SIZE);
    }
    // If it is the child process.
    else if (child_process_id == 0) {
        quickSort(array, 0, ARRAY_SIZE - 1);
        puts("I am the child process and I used the quick sort algorithm.");
        print_array_of_integers(array, ARRAY_SIZE);
    }
    // If it was not possible to create a child process.
    else {
        fprintf(stderr, "%s", "ERROR: unsuccessful child process creation.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int *create_array_of_random_integers(size_t array_size) {
    // Verify whether `array_size` is equal to 0.
    if (array_size == 0) {
        fprintf(stderr, "%s", "ERROR: attempt to create an array with 0 elements. .\n");
        return NULL;
    }

    // If `array_size` is different from 0.

    // Dynamically allocate the memory for `array`.
    int *array = (int *)malloc(sizeof(int) * array_size);

    // Assign a random value to each element of `array`.
    for (size_t i = 0; i < array_size; i++) {
        array[i] = random();
    }

    return array;
}

void print_array_of_integers(int *array, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    puts("");
}
