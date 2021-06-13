#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	c = c % 256;
	while (i <= len)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
