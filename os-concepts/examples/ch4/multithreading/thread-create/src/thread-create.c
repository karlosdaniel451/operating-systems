#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_xs(void *unused) {
    while (1) {
        fputc('x', stderr);
    }

    return NULL;
}

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, &print_xs, NULL);

    while (1) {
        fputc('o', stderr);
    }

    return EXIT_SUCCESS;
}
