# exercise 2.24

## This is a programming problem which applies the concepts of kernel system calls, system call wrappers, POSIX API (or Windows API) and the `strace` (or `dtruss`) utility.

### - `bin`: the object files generated by the command bellow. PS: these object files must be ignored by git.

```
operating-systems/os-concepts/exercises/ch2/exercise-2-24$ gcc src/FileCopy.h src/FileCopy.c src/main.c -o bin/main.elf

```

### - `file`: where the input file and output files reside.

### - `src`: the source code of the program.

### - `strace_output`: The content of the file `strace_output_file.txt` is the output provided by `strace` by entering the following command:

```
operating-systems/os-concepts/exercises/ch2/exercise-2-24$ strace /bin/main.elf 2> strace_output/strace_output.txt
```
