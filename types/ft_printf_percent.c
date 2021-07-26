#include "ft_printf.h"

int	ft_printf_percent(t_item *datum)
{
	write(1, "%", 1);
	datum->length++;
	return (datum->length);
}
