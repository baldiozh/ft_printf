#include "ft_printf.h"

void	ft_parse_type(const char *format, t_item *datum, int i)
{
	if (format[i] == 'd')
		datum->type = 'd';
	if (format[i] == 'i')
		datum->type = 'i';
	if (format[i] == 'c')
		datum->type = 'c';
	if (format[i] == 's')
		datum->type = 's';
	if (format[i] == 'u')
		datum->type = 'u';
	if (format[i] == 'x')
		datum->type = 'x';
	if (format[i] == 'X')
		datum->type = 'X';
	if (format[i] == 'p')
		datum->type = 'p';
	if (format[i] == '%')
		datum->type = '%';
	i++;
}
