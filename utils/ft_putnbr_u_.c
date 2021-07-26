#include "ft_printf.h"

void	ft_putnbr_u_fd(unsigned int n)
{
	char	c;

	if (n < 10 && n >= 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_u_fd((n / 10));
		ft_putnbr_u_fd((n % 10));
	}
}
