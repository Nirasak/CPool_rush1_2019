/*
** EPITECH PROJECT, 2019
** rush1-4
** File description:
** rush1-4
*/

#include <unistd.h>

void my_putchar(char c)
{
    if (c == 'B')
        write(1, "\033[33mB", 9);
    if (c == ' ')
        write(1, "\033[34m ", 9);
    if (c == 'A')
        write(1, "\033[32mA", 9);
    if (c == 'C')
        write(1, "\033[32mC", 9);
    if (c == '\n')
        write(1, "\n", 1);
}

void my_print_mid_line(int x)
{
    my_putchar('B');
    x = x - 1;
    while (x > 0) {
        if (x == 1)
            my_putchar('B');
        else
            my_putchar(' ');
        x = x - 1;
    }
    my_putchar('\n');
}

void my_print_first_line(int x, int y)
{
    if (x == 1) {
        my_putchar('B');
        my_putchar('\n');
        return;
    }
    if (y != 1) {
        my_putchar('A');
        x = x - 1;
    }
    while (x > 0) {
        if (x == 1 && y != 1)
            my_putchar('C');
        else
            my_putchar('B');
        x = x - 1;
    }
}

void my_print_last_line(int x, int x_start)
{
    if (x > 1) {
        my_putchar('A');
        x = x - 1;
    }
    while (x > 0) {
        if (x == 1 && x_start != 1)
            my_putchar('C');
        else
            my_putchar('B');
        x = x - 1;
    }
}

void rush(int x, int y)
{
    int x_start = x;

    if (x <= 0 || y <= 0) {
        write(2, "\033[36mInvalid size\n", 21);
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

int main(void)
{
    rush(5, 5);
    return (0);
}
