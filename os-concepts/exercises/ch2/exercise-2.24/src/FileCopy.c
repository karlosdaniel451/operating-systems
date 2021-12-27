#include "FileCopy.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int copy_file_content(const char *input_file_pathname, const char *output_file_pathname,
                      bool overwrite) {
    int input_file_descriptor = open(input_file_pathname, O_RDONLY);

    // Validate whether the given input file exit.
    if (input_file_descriptor == -1) {
        return INPUT_FILE_NOT_FOUND;
    }

    int output_file_descriptor = open(output_file_pathname, O_WRONLY);

    // Check that the given output file already exists.
    if (output_file_descriptor != -1) {
        if (overwrite == true) {
            __copy_file_content(input_file_descriptor, output_file_descriptor);
            return CONTENT_COPIED_SUCCESSFULLY;
        }
        close(input_file_descriptor);
        return OUTPUT_FILE_ALREADY_EXISTS;
    }

    // If the given output file does not exist.

    // Create the output file with the permissions -rw-rw-r--.
    // Reference for Permission Bits:
    // https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html
    output_file_descriptor = creat(output_file_pathname, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                                   S_IROTH);

    printf("pathname of the input file: %s\n"
           "file descriptor of input file: %d\n",
           input_file_pathname, input_file_descriptor);

    printf("pathname of the output file: %s\n"
           "file descriptor of output file: %d\n",
           input_file_pathname, input_file_descriptor);

    __copy_file_content(input_file_descriptor, output_file_descriptor);

    close(input_file_descriptor);
    close(output_file_descriptor);

    return CONTENT_COPIED_SUCCESSFULLY;
}

void __copy_file_content(int input_file_descriptor, int output_file_descriptor) {
    char character_read;
    while (read(input_file_descriptor, &character_read, 1) > 0) {
        // putchar(character_read);
        write(output_file_descriptor, &character_read, sizeof(char));
    }
}
