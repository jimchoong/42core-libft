#include "libft.h"

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	if (!s)
		return (NULL);
	s1 = malloc(ft_strlen(s) + 1);
	if (!s1)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
