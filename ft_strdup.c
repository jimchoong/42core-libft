#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len + 1);
	return (s);
}
