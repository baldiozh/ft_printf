#include "ft_printf.h"

static void	ft_recount(t_item *datum, unsigned int value, int size)
{
	if (datum->precision <= size && datum->dot == 1 && value != 0)
	{
		datum->precision = 0;
		datum->width -= size;
	}
	if (datum->precision > size && datum->dot == 1)
	{
		datum->precision -= size;
		datum->width -= (datum->precision + size);
	}
	if (datum->dot == 0)
		datum->width -= size;
	if (datum->minus != 1)
		ft_print_width(datum, 0);
}

static void	ft_print_value_zero(t_item *datum, int size)
{
	if (datum->precision != -1)
		datum->width -= datum->precision;
	if (datum->minus == 1)
	{
		ft_print_precision(datum, 0);
		ft_print_width(datum, 0);
	}
	if (datum->minus == 0)
	{
		ft_print_width(datum, size);
		ft_print_precision(datum, 0);
	}
}

static void	ft_print_xX(t_item *datum, int size, unsigned int value)
{
	ft_recount(datum, value, size);
	if (datum->minus == 1)
	{
		ft_print_precision(datum, 0);
		ft_putnbr_hex(datum, value);
		ft_print_width(datum, 0);
	}
	else
	{
		if (datum->dot == 0 && datum->zero == 1)
			ft_print_width(datum, 0);
		ft_print_width(datum, size);
		ft_print_precision(datum, 0);
		ft_putnbr_hex(datum, value);
	}
}

int	ft_printf_xX(t_item *datum, va_list ap)
{
	unsigned int	value;
	int				size;

	value = va_arg(ap, unsigned int);
	size = ft_count_size(datum, value);
	if (value == 0 && datum->dot == 1)
		ft_print_value_zero(datum, size);
	else
		ft_print_xX(datum, size, value);
	return (datum->length);
}
