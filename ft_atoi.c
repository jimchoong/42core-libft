#include "libft.h"

int	ft_atoi(const char *s)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while ((9 <= *s && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		n = 10 * n + (*s - '0');
		s++;
	}
	return (sign * n);
}
