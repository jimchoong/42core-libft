#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	size_t	ned_len;

	if (!*ned)
		return ((char *)hay);
	ned_len = ft_strlen(ned);
	while (*hay && len && ned_len <= len)
	{
		if (*hay == *ned && (ft_strncmp(hay, ned, ned_len) == 0))
			return ((char *)hay);
		hay++;
		len--;
	}
	return (NULL);
}
