#include "libft.h"

static char	*ft_strncpy(char *dst, char const *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	slen;
	size_t	size;

	slen = ft_strlen(s);
	if (s && start < slen && len > 0)
	{
		if (len < slen - start)
			size = len;
		else
			size = slen - start;
		s1 = malloc(sizeof(char) * (size + 1));
		if (!s1)
			return (NULL);
		s1 = ft_strncpy(s1, s + start, size);
		return (s1);
	}
	return (ft_calloc(1, 1));
}
