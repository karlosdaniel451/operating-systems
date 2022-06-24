#!/usr/bin/env python
# -*- coding: utf-8 -*-

import threading
import time

NUMBER_OF_THREADS = 10

def main():
    start = time.perf_counter()

    threads = []

    for _ in range(NUMBER_OF_THREADS):
        thread = threading.Thread(target=do_something, args=[1.5])
        thread.start()
        threads.append(thread)

    for thread in threads:
        thread.join()

    finish = time.perf_counter()

    print(f'Finshed in {round(finish-start, 2)} second(s)')


def do_something(seconds: float):
    """
    Represents an I/O bound task.
    """

    print(f'Sleeping for {seconds} second(s)...')
    time.sleep(seconds)
    print('Done sleeping')


if __name__ == '__main__':
    main()

