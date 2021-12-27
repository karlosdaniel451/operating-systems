#include <stdio.h>
#include <stdlib.h>

#include "FileCopy.h"

#define PATHNAME_BUFFER_SIZE 300 + 1

int main() {
    char input_file_pathname[PATHNAME_BUFFER_SIZE];
    char output_file_pathname[PATHNAME_BUFFER_SIZE];

    printf("Type the input file name: ");
    scanf("%100s", input_file_pathname);

    printf("Type the output file name: ");
    scanf("%100s", output_file_pathname);

    int return_by_copying_file_content =
        copy_file_content(input_file_pathname, output_file_pathname, false);

    if (return_by_copying_file_content == INPUT_FILE_NOT_FOUND) {
        fprintf(stderr, "ERROR: The input file was not found.\n");
        return EXIT_FAILURE;
    }

    if (return_by_copying_file_content == OUTPUT_FILE_ALREADY_EXISTS) {
        char option;
        fprintf(stderr,
                "ERROR: The output file already exists. Do you want to "
                "overwrite the output file? ('y' or 'n'): ");
        scanf(" %c", &option);

        while (option != 'n' && option != 'y') {
            fprintf(stderr, "ERROR: Invalid option. Please enter 'y' or 'n'.");
            scanf("%c", &option);
        }

        if (option == 'n') {
            return EXIT_FAILURE;
        }

        if (option == 'y') {
            return_by_copying_file_content = copy_file_content(
                input_file_pathname, output_file_pathname, true);

            /*puts("The file content was copied successfully.");
            return EXIT_SUCCESS;*/
        }
    }

    if (return_by_copying_file_content != CONTENT_COPIED_SUCCESSFULLY) {
        fprintf(stderr,
                "ERROR: It was not possible to copy the requested content."
                " Please check the permissions of the given files or that if "
                "they are not corrupted.\n");
        return EXIT_FAILURE;
    }

    puts("The file content was copied successfully.");
    return EXIT_SUCCESS;
}
