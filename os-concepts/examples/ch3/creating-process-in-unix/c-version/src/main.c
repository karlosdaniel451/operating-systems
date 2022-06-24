#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int child_exit_status;

    // Fork a child process.
    pid = fork();

    // If some error ocurred.
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return EXIT_FAILURE;
    }

    // If it is child process.
    if (pid == 0) {
        // sleep(10);
        execlp("/bin/ls", "ls", NULL);
        // If an error ocurred by loading `/bin/ls`.
        fprintf(stderr, "It was possible to load '/bin/ls'.\n");
    }

    // If it is parent process.
    // Parent will wait for the child to complete.
    wait(&child_exit_status);
    printf("Child process with pid %d complete with exit status %d\n",
            pid, child_exit_status);

    // sleep(10);

    return EXIT_SUCCESS;
}

