#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import json

def main():
    start: int
    end: int
    step: int
    file_name: str

    try:
        file_name = sys.argv[1]
        start = int(sys.argv[2])
        end = int(sys.argv[3])
        step = int(sys.argv[4])
    except IndexError:
        print('Insuficient arguments.')
        exit(1)
    except ValueError:
        print('Invalid arguments.')
        exit(1)

    with open(file_name, 'w') as f:
        generated_input = list(range(start, end, step))

        f.write(f'{len(generated_input)} ')

        for i in generated_input:
            f.write(f'{i} ')


if __name__ == '__main__':
    main()

