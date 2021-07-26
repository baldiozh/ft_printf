#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_item
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		type;
	int		length;
	int		size;
}			t_item; 	

int		ft_printf(const char *format, ...);

int		ft_parse_flags(const char *format, t_item *datum, int i);
int		ft_parse_width(const char *format, t_item *datum, int i, va_list ap);
int		ft_parse_precision(const char *format, t_item *datum, int i,
			va_list ap);
int		ft_parser_f_w_p(const char *format, t_item *datum, int i, va_list ap);

void	ft_parse_type(const char *format, t_item *datum, int i);

int		ft_printf_d_i(t_item *datum, va_list ap);
void	ft_printf_d_i_zero(t_item *datum);
int		ft_printf_u(t_item *datum, va_list ap);
int		ft_count_digits(int n);
int		ft_printf_char(t_item *datum, va_list ap);
int		ft_printf_string(t_item *datum, va_list ap);
int		ft_printf_xX(t_item *datum, va_list ap);
int		ft_printf_p(t_item *datum, va_list ap);
int		ft_printf_percent(t_item *datum);

void	ft_putnbr_hex(t_item *datum, unsigned long int n);
void	ft_putnbr_u_fd(unsigned int n);
int		ft_count_size(t_item *datum, unsigned long int n);
void	ft_print_width(t_item *datum, int size);
void	ft_print_precision(t_item *datum, int size);

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);

#endif