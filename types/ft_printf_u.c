#include "ft_printf.h"

static int	ft_size(unsigned int n)
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

static void	ft_recount(t_item *datum, unsigned int value, int size)
{
	if (datum->precision <= size && datum->dot == 1 && value != 0)
	{
		datum->precision = 0;
		datum->width -= size;
	}
	if (datum->precision >= size && datum->dot == 1)
	{
		if (value != 0)
			datum->precision -= size;
		if (value == 0)
			datum->width -= datum->precision;
		else
			datum->width -= (datum->precision + size);
	}
	if (datum->dot == 0)
		datum->width -= size;
}

static void	ft_print_u(t_item *datum, unsigned int value, int size)
{
	if (datum->minus != 1)
		ft_print_width(datum, 0);
	ft_print_precision(datum, 0);
	if (value != 0 || datum->dot == 0 || (datum->precision > 0 && value != 0))
	{
		ft_putnbr_u_fd(value);
		datum->length += size;
	}
	else if (datum->precision > 1 && value != 0)
	{
		ft_putnbr_u_fd(value);
		datum->length += size;
	}
	if (datum->minus == 1)
		ft_print_width(datum, 0);
}

int	ft_printf_u(t_item *datum, va_list ap)
{
	int					size;
	unsigned int		value;

	value = va_arg(ap, unsigned int);
	size = ft_size(value);
	if (value == 0 && datum->minus == 0
		&& datum->dot == 1 && datum->precision > 0)
	{
		datum->width -= datum->precision;
		ft_print_width(datum, 0);
		ft_print_precision(datum, 0);
	}
	else
	{
		ft_recount(datum, value, size);
		ft_print_u(datum, value, size);
	}	
	return (datum->length);
}
