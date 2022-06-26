#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

#define BUFFER_SIZE_IN_BYTES 4
#define READ_END 0
#define WRITE_END 1

const char* PROGRAM_TO_EXECUTE = "/bin/ls";
const struct TIME_BEFORE_EXECUTE_PROGRAM;
const struct TIME_AFTER_EXECUTE_PROGRAM;

int main(int argc, char *argv[]) {
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed.");
        return EXIT_FAILURE;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error by forking process.");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        close(fd(WRITE_END));

        write(fd(WRITE_END), gettimeofday(&TIME_BEFORE_EXECUTE_PROGRAM));

        execlp(PROGRAM_TO_EXECUTE, PROGRAM_TO_EXECUTE, NULL);
    }

    read()

    return EXIT_SUCCESS;
}
