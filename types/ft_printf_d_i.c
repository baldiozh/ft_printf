#include "ft_printf.h"

static void	ft_flag_minus(t_item *datum, int value, int size)
{
	if (value < 0)
	{
		if (value == -2147483648)
			datum->length++;
		else
		{
			value *= -1;
			write(1, "-", 1);
			datum->length++;
		}
		datum->width--;
	}
	ft_print_precision(datum, size);
	ft_putnbr_fd(value, 1);
	datum->length += size;
	ft_print_width(datum, size);
}

static void	ft_flag_minus_off(t_item *datum, int value, int size)
{
	if (value < 0)
		datum->width--;
	if (datum->zero == 0 || (datum->dot == 1 && datum-> zero == 1))
		ft_print_width(datum, 0);
	if (value < 0)
	{
		if (value == -2147483648)
			datum->length++;
		else
		{
			value *= -1;
			write(1, "-", 1);
			datum->length++;
		}
		if (datum->zero == 0)
			datum->width--;
	}
	if (datum->dot == 0 && datum->zero == 1)
		ft_print_width(datum, 0);
	ft_print_precision(datum, size);
	ft_putnbr_fd(value, 1);
}

int	ft_printf_d_i(t_item *datum, va_list ap)
{
	int		size;
	int		value;

	value = va_arg(ap, int);
	size = ft_count_digits(value);
	if (value == 0)
	{
		ft_printf_d_i_zero(datum);
		return (datum->length);
	}	
	if (datum->precision > size)
		datum->width -= datum->precision;
	else
		datum->width -= size;
	if (datum->minus == 1)
	{
		ft_flag_minus(datum, value, size);
		return (datum->length);
	}
	if (datum->minus == 0)
	{
		ft_flag_minus_off(datum, value, size);
		return (datum->length += size);
	}
	return (datum->length += size);
}
