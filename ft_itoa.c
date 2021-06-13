#include "libft.h"

static int	num_len(long i)
{
	int	len;

	if (i == 0)
		return (1);
	len = 0;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char	*rev_num(char *s, int i)
{
	int		j;
	char	tmp;

	j = 0;
	while (j < i / 2)
	{
		tmp = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = tmp;
		j++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_num(char *s, long num, int is_neg)
{
	int		i;
	char	*ret;

	i = 0;
	ret = s;
	if (is_neg)
		*s++ = '-';
	if (num == 0)
	{
		*s++ = '0';
		*s = '\0';
		return (ret);
	}
	while (num > 0)
	{
		s[i++] = num % 10 + '0';
		num /= 10;
	}
	s = rev_num(s, i);
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	num;
	int		is_neg;
	int		len;

	is_neg = 0;
	num = n;
	len = 1;
	if (num < 0)
	{
		is_neg = 1;
		num *= -1;
		len++;
	}
	len += num_len(num);
	s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (get_num(s, num, is_neg));
}
