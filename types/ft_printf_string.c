#include "ft_printf.h"

static void	ft_zero_zero(t_item *datum, char *val)
{
	if (datum->width == 0 && datum->dot == 0)
	{
		ft_putstr_fd(val, 1);
		datum->length += ft_strlen(val);
	}
}

static void	ft_flag_minus(t_item *datum, char *val, int len)
{
	if (datum->precision > 0)
		datum->width -= datum->precision;
	else if (datum->dot == 0)
		datum->width -= len;
	if (datum->dot == 0)
	{
		ft_putstr_fd(val, 1);
		datum->length += len;
	}
	while (datum->precision-- > 0)
	{
		write(1, val++, 1);
		datum->length++;
	}
	while (datum->width-- > 0)
	{
		write(1, " ", 1);
		datum->length++;
	}
}

static void	ft_no_flag(t_item *datum, char *val, int len)
{
	if (datum->precision > 0)
		datum->width -= datum->precision;
	if (datum->dot == 0 && datum->width >= len)
		datum->width -= len;
	else if (datum->dot == 0 && datum->width < len)
		datum->width = 0;
	while (datum->width > 0)
	{
		write(1, " ", 1);
		datum->length++;
		datum->width--;
	}
	ft_zero_zero(datum, val);
	while (datum->precision-- > 0)
	{
		write(1, val++, 1);
		datum->length++;
	}
}

int	ft_printf_string(t_item *datum, va_list ap)
{
	char	*val;
	int		len;

	val = va_arg(ap, char *);
	if (val == NULL)
		val = "(null)";
	len = (int)ft_strlen(val);
	if (datum->precision > len && datum->precision != -1)
		datum->precision = len;
	if (datum->minus == 1)
		ft_flag_minus(datum, val, len);
	else
		ft_no_flag(datum, val, len);
	return (datum->length);
}
