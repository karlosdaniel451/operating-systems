#!/usr/bin/env python
# -*- coding: utf-8 -*-

import concurrent.futures
import time

NUMBER_OF_THREADS = 10

def main():
    start = time.perf_counter()

    with concurrent.futures.ThreadPoolExecutor() as executor:
        #  results = [executor.submit(do_something, 1) for _ in range(NUMBER_OF_THREADS)]
        #  for f in concurrent.futures.as_completed(results):
        #      print(f.result())

        seconds_to_wait_list = [5, 4, 3, 2, 1]

        # executor.map will return the results in the order the corresponding
        # task of each one was submited.
        results = executor.map(do_something, seconds_to_wait_list)

        for result in results:
            print(result)


    finish = time.perf_counter()

    print(f'Finshed in {round(finish-start, 2)} second(s)')


def do_something(seconds: float):
    """
    Simulates an I/O bound task.
    """

    print(f'Sleeping for {seconds}s...')
    time.sleep(seconds)

    return f'Done sleeping after {seconds}s'


if __name__ == '__main__':
    main()

