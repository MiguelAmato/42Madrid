#!/bin/bash

gcc -c -Wall -Wextra -Werror *.c
ar rcs libft.a *.c