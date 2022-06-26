#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import time

def main():
    try:
        starting_number = int(sys.argv[1])
    except IndexError:
        print('Error: argument <starting_number> is missing.')
        exit(1)
    except ValueError:
        print('Error: argument <starting_number> must be a positive number.')
        exit(1)

    if starting_number < 0:
        print('Error: argument <starting_number> must be a positive number.')
        exit(1)

    pid = os.fork()

    if pid < 0:
        print('Error by forking process.')
        exit(1)

    # If it is child process.
    if pid == 0:
        print(f'pid of child process: {os.getpid()}')
        if starting_number == 1:
            print(1)
            exit()

        print(starting_number, end=', ')
        result = starting_number
        if pid == 0:
            while True:
                result = apply_collatz_conjecture_algorithm(result)

                if result == 1:
                    break
                print(result, end=', ')

            print('1 ')

    # If it is parent process.
    else:
        pass

def apply_collatz_conjecture_algorithm(number: int) -> int:
    ''' Return `number` if it is even or 3 * `number` + 1 otherwise'''
    return number // 2 if number % 2 == 0 else 3 * number + 1

if __name__ == '__main__':
    main()

