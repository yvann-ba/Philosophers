#include "philo.h"

void ft_putnbr(int n)
{
    char c;
    
    if (n >= 10)
        ft_putnbr(n / 10);
    c = '0' + (n % 10);
    write(STDOUT_FILENO, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
        write(STDOUT_FILENO, str++, 1);
}


void safe_write(int id, char *msg)
{
    ft_putstr("Philosopher ");
    ft_putnbr(id);
    ft_putstr(msg);
}
