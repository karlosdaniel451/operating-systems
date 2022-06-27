import time
import random
# import functools

def main():
    number_of_integers: int

    try:
        number_of_integers = int(input('Enter the number of integers: '))
    except ValueError:
        exit(1)

    # integers = read_list_of_integers(list_size)
    # integers = [random.randint(0, 2**32) for _ in range(number_of_integers)]
    integers = [i for i in range(number_of_integers)]

    # minimum = min(integers)
    # maximum = max(integers)
    # average = sum(integers) / len(integers)

    print('\nBeginning to execute CPU bound tasks...\n')

    start_time = time.perf_counter()

    minimum = get_minimum(integers)
    maximum = get_maximum(integers)
    average = get_average(integers)

    end_time = time.perf_counter()

    print(f'\n{minimum = }\n{maximum = }\n{average = }\n\n'
          f'Finished in {(end_time-start_time):.3f}s.')


def get_minimum(integers: list[int]) -> int:
    print('Beginning to compute minimum...\n')

    if len(integers) == 1:
        return integers[0];

    minimum_integer = integers[0];

    for integer in integers:
        if integer < minimum_integer:
            minimum_integer = integer

    return minimum_integer;


def get_maximum(integers: list[int]) -> int:
    print('Beginning to compute maximum...\n')

    if len(integers) == 1:
        return integers[0];

    maximum_integer = integers[0];

    for integer in integers:
        if integer > maximum_integer:
            maximum_integer = integer

    return maximum_integer;


def get_average(integers: list[int]) -> float:

    print('Beginning to compute average...\n')

    # sum_of_all_integers = functools.reduce(lambda a, b: a + b, integers)

    sum_of_all_integers = 0

    for integer in integers:
        sum_of_all_integers += integer

    return sum_of_all_integers / len(integers)


if __name__ == '__main__':
    main()
