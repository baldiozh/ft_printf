#include "ft_printf.h"

static void	ft_flag_minus(t_item *datum, int value)
{
	write(1, &value, 1);
	if (datum->width < 0)
		datum->width *= -1;
	while ((datum->width - 1) > 0)
	{
		write(1, " ", 1);
		datum->width--;
		datum->length++;
	}
}

static void	ft_no_flag(t_item *datum, int value)
{
	while ((datum->width - 1) > 0)
	{
		write(1, " ", 1);
		datum->width--;
		datum->length++;
	}
	write(1, &value, 1);
}

int	ft_printf_char(t_item *datum, va_list ap)
{
	int	value;

	value = va_arg(ap, int);
	if (datum->minus == 1)
		ft_flag_minus(datum, value);
	else
		ft_no_flag(datum, value);
	datum->length++;
	return (datum->length);
}
