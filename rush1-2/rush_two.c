/*
** EPITECH PROJECT, 2019
** rush1-2.c
** File description:
** rush1-2.c
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_mid_line(int x)
{
    my_putchar('*');
    x = x - 1;
    while (x > 0) {
        if (x == 1)
            my_putchar('*');
        else
            my_putchar(' ');
        x = x - 1;
    }
    my_putchar('\n');
}

void my_print_first_line(int x, int y)
{
    if (x == 1) {
        my_putchar('*');
        my_putchar('\n');
        return;
    }
    if (y != 1) {
        my_putchar('/');
        x = x - 1;
    }
    while (x > 0) {
        if (x == 1 && y != 1)
            my_putchar(92);
        else
            my_putchar('*');
        x = x - 1;
    }
    my_putchar('\n');
}

void my_print_last_line(int x, int x_start)
{
    if (x > 1) {
        my_putchar(92);
        x = x - 1;
    }
    while (x > 0) {
        if (x == 1 && x_start != 1)
            my_putchar('/');
        else
            my_putchar('*');
        x = x - 1;
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    int x_start = x;

    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return;
    }
    my_print_first_line(x, y);
    y = y - 1;
    while (y > 0) {
        if (y == 1)
            my_print_last_line(x, x_start);
        else
            my_print_mid_line(x);
        y = y - 1;
    }
}
