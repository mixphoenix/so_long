#include "ft_printf.h"

int	ft_hex(unsigned int n, char x)
{
	char	*hex;
	int		c;

	c = 0;
	hex = 0;
	if (x == 'X')
		hex = "0123456789ABCDEF";
	else if (x == 'x')
		hex = "0123456789abcdef";
	if (n >= 16)
		c += ft_hex((n / 16), x);
	c += ft_putchar(hex[(n % 16)]);
	return (c);
}

int	ft_hex_p(unsigned long long n)
{
	char	*hex;
	int		c;

	c = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		c += ft_hex_p((n / 16));
	c += ft_putchar(hex[(n % 16)]);
	return (c);
}

int	ft_pointer(unsigned long long p)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	c += ft_hex_p(p);
	return (c);
}
