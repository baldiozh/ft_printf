#include "ft_printf.h"

int	ft_parse_flags(const char *format, t_item *datum, int i)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			datum->minus = 1;
			datum->zero = 0;
		}
		else if (format[i] == '0' && !datum->minus)
			datum->zero = 1;
		i++;
	}
	return (i);
}

int	ft_parse_width(const char *format, t_item *datum, int i, va_list ap)
{
	if (ft_isdigit(format[i]) == 1 || format[i] == '*')
	{
		if (ft_isdigit(format[i]) == 1)
		{
			datum->width = ft_atoi(format + i);
			while (ft_isdigit(format[i]) == 1)
				i++;
		}
		else
		{
			datum->width = va_arg(ap, int);
			i++;
		}
	}
	if (datum->width < 0)
	{
		datum->width *= -1;
		datum->minus = 1;
		datum->zero = 0;
	}
	return (i);
}

int	ft_parse_precision(const char *format, t_item *datum, int i, va_list ap)
{
	if (format[i] == '.')
	{
		datum->dot = 1;
		i++;
		if (ft_isdigit(format[i]) == 1)
		{
			datum->precision = ft_atoi(format + i);
			while (ft_isdigit(format[i]) == 1)
				i++;
		}
		else if (format[i] == '*')
		{
			datum->precision = va_arg(ap, int);
			if (datum->precision < 0)
			{
				datum->dot = 0;
				datum->precision = -1;
			}
			i++;
		}
		else
			datum->precision = -1;
	}
	return (i);
}

int	ft_parser_f_w_p(const char *format, t_item *datum, int i, va_list ap)
{
	i = ft_parse_flags(format, datum, i);
	i = ft_parse_width(format, datum, i, ap);
	i = ft_parse_precision(format, datum, i, ap);
	return (i);
}
