#include "libft.h"

/*
 *	memcpy: copies byte by byte from src to dst up to a total of n bytes
 *	
 *	edge cases:
 *	- if dst and src is null pointer, return a (void*)0 pointer.
 *	- if n > size of dst or src, while loop may access beyond src / dst.
 *	  Behavior undefined in implementation.
 *	
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	if (!dst && !src)
		return (0);
	ptr = dst;
	while (n--)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
	}
	return (ptr);
}
