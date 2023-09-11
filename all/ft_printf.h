#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *arr, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_hex(unsigned int n, char x);
int	ft_putunbr(unsigned int nb);
int	ft_pointer(unsigned long long p);
int	ft_print(int c, const char *arr, int i, va_list args);
int	ft_hex_p(unsigned long long n);

#endif