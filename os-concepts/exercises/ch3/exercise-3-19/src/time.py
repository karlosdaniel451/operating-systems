#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import time

def main():
    PROGRAM_TO_EXECUTE = 'locate'
    time_before_executing_program_in_milliseconds: int
    time_after_executing_program_in_milliseconds: int
    time_to_execute_program_in_milliseconds: int

    read_end, write_end = os.pipe()

    pid = os.fork()

    if pid < 0:
        print('Error by forking process.')
        exit(1)

    # If it is child process.
    if pid == 0:
        time_before_executing_program_in_milliseconds = int(time.time_ns() / 1_000_000)
        os.write(write_end, str(time_before_executing_program_in_milliseconds).encode())
        os.execlp(PROGRAM_TO_EXECUTE, PROGRAM_TO_EXECUTE, 'ab')

    # If it is parent process.
    else:
        os.wait()

        os.close(write_end)

        time_after_executing_program_in_milliseconds = int(time.time_ns() / 1_000_000)

        with os.fdopen(read_end) as r:
            time_before_executing_program_in_milliseconds = int(r.read())

        time_to_execute_program_in_milliseconds = time_after_executing_program_in_milliseconds - \
            time_before_executing_program_in_milliseconds

        print(f'Time to execute {PROGRAM_TO_EXECUTE}: {time_to_execute_program_in_milliseconds} ms')


if __name__ == '__main__':
    main()

