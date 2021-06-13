#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	if (!dst && !src)
		return (0);
	dst1 = dst;
	src1 = src;
	if (dst > src)
	{
		dst1 += len;
		src1 += len;
		while (len--)
			*--dst1 = *--src1;
	}
	else
	{
		while (len--)
			*dst1++ = *src1++;
	}
	return (dst);
}
