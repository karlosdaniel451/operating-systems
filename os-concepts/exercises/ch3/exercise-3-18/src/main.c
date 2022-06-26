#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error by forking process.");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        return EXIT_SUCCESS;
    }

    sleep(60);

    wait(NULL);

    return EXIT_SUCCESS;
}
