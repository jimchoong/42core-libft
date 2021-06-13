#include "libft.h"

static int	isset(char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && isset(*s1, set))
		s1++;
	end = ft_strlen(s1);
	if (end > 0)
		while (isset(s1[end - 1], set))
			end--;
	s = ft_calloc(end + 1, sizeof(char));
	if (!s)
		return (NULL);
	start = s;
	while (end--)
		*s++ = *s1++;
	return (start);
}
