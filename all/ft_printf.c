#include "ft_printf.h"

int	ft_print(int c, const char *arr, int i, va_list args)
{
	if (arr[i] == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (arr[i] == 'x' || arr[i] == 'X')
		c += ft_hex(va_arg(args, unsigned long), arr[i]);
	else if (arr[i] == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (arr[i] == 'p')
		c += ft_pointer(va_arg(args, unsigned long long));
	else if ((arr[i] == 'i') || (arr[i] == 'd'))
		c += ft_putnbr(va_arg(args, int));
	else if (arr[i] == 'u')
		c += ft_putunbr(va_arg(args, unsigned int));
	else if (arr[i] == '%')
	{
		write(1, "%", 1);
		c++;
	}
	i++;
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int c;

	va_start(args, str);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			c = ft_print(c, str, i, args);
		}
		else
			c += ft_putchar(str[i]);
		i++;
	}
	return (c);
}