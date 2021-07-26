#include "ft_printf.h"

int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

void	ft_print_width(t_item *datum, int size)
{
	char	sep;
	int		width;

	width = datum->width;
	if (datum->dot == 0 && datum->zero == 1)
	{
		sep = '0';
		while (datum->width-- > size)
		{
			write(1, &sep, 1);
			datum->length++;
		}
	}
	else
	{
		sep = ' ';
		while (datum->width-- > 0)
		{
			write(1, &sep, 1);
			datum->length++;
		}
	}
}

void	ft_print_precision(t_item *datum, int size)
{
	int	precision;

	precision = datum->precision;
	while (precision-- > size)
	{
		write(1, "0", 1);
		datum->length++;
	}
}
