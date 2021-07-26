#include "ft_printf.h"

void	new_item(t_item *datum)
{
	datum->minus = 0;
	datum->zero = 0;
	datum->width = 0;
	datum->dot = 0;
	datum->precision = 0;
	datum->type = 0;
	datum->length = 0;
	datum->size = 0;
}

static int	ft_type_call_func(t_item *datum, va_list ap)
{
	if (datum->type == 'd' || datum->type == 'i')
		datum->length = ft_printf_d_i(datum, ap);
	if (datum->type == 'c')
		datum->length = ft_printf_char(datum, ap);
	if (datum->type == 's')
		datum->length = ft_printf_string(datum, ap);
	if (datum->type == 'u')
		datum->length = ft_printf_u(datum, ap);
	if (datum->type == 'x' || datum->type == 'X')
		datum->length = ft_printf_xX(datum, ap);
	if (datum->type == 'p')
		datum->length = ft_printf_p(datum, ap);
	if (datum->type == '%')
		datum->length = ft_printf_percent(datum);
	return (datum->length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	t_item	datum;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			count--;
			new_item(&datum);
			i = ft_parser_f_w_p(format, &datum, i + 1, ap);
			ft_parse_type(format, &datum, i);
			count += ft_type_call_func(&datum, ap);
		}
		count++;
		i++;
	}
	va_end(ap);
	return (count);
}
