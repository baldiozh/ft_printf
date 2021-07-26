#include "ft_printf.h"

static int	ft_des(int n)
{
	int	des;

	des = 1;
	while (n / 10)
	{
		n /= 10;
		des *= 10;
	}
	return (des);
}

static void	ft_big_n(int n, int fd)
{
	int	num;
	int	des;

	num = 0;
	des = ft_des(n);
	while (des)
	{
		num = n / des;
		ft_putchar_fd(num + '0', fd);
		n %= des;
		des /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	ft_big_n(n, fd);
}
