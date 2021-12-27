#include <stdbool.h>

#define CONTENT_COPIED_SUCCESSFULLY 0
#define INPUT_FILE_NOT_FOUND 1
#define OUTPUT_FILE_ALREADY_EXISTS 2

/* Copy the file content from a given input file into a given output file.
   Overwrite the given output file if, and only if, `overwrite` is true.
   Return CONTENT_COPIED_SUCCESSFULLY if, and only if, the content has been copied successfully.
   Return INPUT_FILE_NOT_FOUND if, and only if, the given input file was not found.
   Return OUTPUT_FILE_ALREADY_EXISTS if, and only if, `overwrite` is false and the given output
   file already exists.
*/
int copy_file_content(const char *input_file_pathname, const char *output_file_pathname,
                      bool overwrite);


/* Copy the file content from a given file descriptor to another given file descriptor.
   It does not verify whether the given file descriptors actually exist.
   It is to be used by `copy_file_content()` and any other functions that have already
   verify the failure conditions regarding the input and output files.*/
void __copy_file_content(int input_file_descriptor, int output_file_descriptor);
