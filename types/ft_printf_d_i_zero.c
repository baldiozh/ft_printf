#include "ft_printf.h"

static void	ft_flagzero_noflag(t_item *datum)
{
	if (datum->zero == 1)
	{
		if (datum->width > 0)
			ft_print_width(datum, 0);
		if (datum->precision > 0)
			ft_print_precision(datum, 0);
		if (datum->dot == 0 && datum->width == 0)
		{
			write(1, "0", 1);
			datum->length++;
		}	
	}
	if (datum->zero == 0 && datum->minus == 0)
	{
		ft_print_width(datum, 0);
		ft_print_precision(datum, 0);
		if (datum->dot == 0)
		{
			write(1, "0", 1);
			datum->length++;
		}	
	}
}

void	ft_printf_d_i_zero(t_item *datum)
{
	if (datum->width <= datum->precision)
		datum->width = 0;
	else if (datum->width > datum->precision && datum->precision != -1)
		datum->width -= datum->precision;
	if (datum->dot == 0 && datum->zero == 0)
		datum->width--;
	if (datum->minus == 1)
	{
		ft_print_precision(datum, 0);
		if (datum->dot == 0)
		{
			write(1, "0", 1);
			datum->length++;
		}
		ft_print_width(datum, 0);
	}
	ft_flagzero_noflag(datum);
}
