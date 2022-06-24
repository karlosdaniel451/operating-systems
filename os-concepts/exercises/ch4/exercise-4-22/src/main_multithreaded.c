#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>

void* get_minimum_worker(void* param);
void* get_maximum_worker(void* param);
void* get_average_worker(void* param);

int* read_array_of_int(size_t size);
int get_minimum(int *array, size_t size);
int get_maximum(int *array, size_t size);
double get_average(int *array, size_t size);

typedef struct ArgsToWorkers {
    int *array;
    size_t size;
} ArgsToWorkers;

int min, max;
double average;

int main() {
    size_t size;
    int *array;

    printf("Enter the list size: ");
    scanf("%ld", &size);

    array = read_array_of_int(size);

    ArgsToWorkers args_to_workers = {array, size};

    pthread_t thread_of_max, thread_of_min, thread_of_average;

    // Create the thread whith the corresponding tasks.
    pthread_create(&thread_of_max, NULL, &get_minimum_worker, &args_to_workers);
    pthread_create(&thread_of_min, NULL, &get_maximum_worker, &args_to_workers);
    pthread_create(&thread_of_average, NULL, &get_average_worker, &args_to_workers);

    // Wait for the created threads to terminate.
    pthread_join(thread_of_min, NULL);
    pthread_join(thread_of_max, NULL);
    pthread_join(thread_of_average, NULL);

    printf("min = %d max = %d average = %lf\n", min, max, average);

    return EXIT_SUCCESS;
}

void* get_minimum_worker(void* param) {
    ArgsToWorkers *args_to_workers = (ArgsToWorkers*) param;
    
    min = get_minimum(args_to_workers->array, args_to_workers->size);

    pthread_exit(0);
}

void* get_maximum_worker(void* param) {
    ArgsToWorkers *args_to_workers = (ArgsToWorkers*) param;
    
    min = get_maximum(args_to_workers->array, args_to_workers->size);

    pthread_exit(0);
}
void* get_average_worker(void* param) {
    ArgsToWorkers *args_to_workers = (ArgsToWorkers*) param;
    
    average = get_average(args_to_workers->array, args_to_workers->size);

    pthread_exit(0);
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

