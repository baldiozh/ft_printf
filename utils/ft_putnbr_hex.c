#include "ft_printf.h"

int	ft_count_size(t_item *datum, unsigned long int n)
{
	if (n / 16 == 0)
		datum->size++;
	else
	{
		ft_count_size(datum, (n / 16));
		ft_count_size(datum, (n % 16));
	}
	return (datum->size);
}

void	ft_putnbr_hex(t_item *datum, unsigned long int n)
{
	char			*hex_set;

	if (datum->type == 'X')
		hex_set = "0123456789ABCDEF";
	if (datum->type == 'x' || datum->type == 'p')
		hex_set = "0123456789abcdef";
	if (n / 16 == 0)
	{
		write(1, &hex_set[n], 1);
		datum->length++;
	}
	else
	{
		ft_putnbr_hex(datum, (n / 16));
		ft_putnbr_hex(datum, (n % 16));
	}
}
