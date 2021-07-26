#include "ft_printf.h"

static void 	ft_flag_minus_off(t_item *datum, unsigned long int value)
{
	ft_print_width(datum, 0);
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(datum, value);
}

static void	ft_flag_minus_on(t_item *datum, unsigned long int value)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(datum, value);
	ft_print_width(datum, 0);
}

int	ft_printf_p(t_item *datum, va_list ap)
{
	unsigned long int	value;
	int					size;

	value = va_arg(ap, unsigned long int);
	size = 2 + ft_count_size(datum, value);
	datum->zero = 0;
	if (datum->width >= size)
		datum->width -= size;
	else
		datum->width = 0;
	if (datum->minus == 0)
		ft_flag_minus_off(datum, value);
	if (datum->minus == 1)
		ft_flag_minus_on(datum, value);
	return (datum->length += 2);
}
