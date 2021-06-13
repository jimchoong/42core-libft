#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	j;
	size_t	wrd;
	size_t	i;

	i = 0;
	wrd = 0;
	j = 0;
	while (s)
	{
		if (s[i] == '\0')
			
			break;
		if (s[i] != c))
		{
			wrd++;
			j = i + 1;
			while (s[j] == c || s[j] == '\0')
			{
				wrd++;
			}
		}
		i++;
	}
	return (wrd);
}

static void	free_all(char **lst)
{
	while (*lst)
	{
		free(*lst);
		lst++;
	}
	free(lst);
}

static char	**fill(char const *s, size_t len, char **lst, size_t n)
{
	char			*s1;
	size_t			i;

	i = 0;
	s1 = malloc(sizeof(char) * (len + 1));
	if (s1 == NULL)
	{
		lst[n] = NULL;
		free_all(lst);
		return (NULL);
	}
	while (i < len)
		s1[i++] = *s++;
	s1[i] = '\0';
	lst[n] = s1;
	return (lst);
}

static char	**split(char const *s, char c, char **lst, size_t wrd)
{
	size_t	i;
	size_t	is_word;
	size_t	start;
	size_t	n;

	i = 0;
	is_word = 0;
	n = 0;
	while (n < wrd)
	{
		if (s[i] != c && !is_word)
		{
			start = i;
			is_word = 1;
		}
		else if (s[i] == c && is_word)
		{
			is_word = 0;
			if (fill((s + start), i - start, lst, n) == NULL)
				return (NULL);
			n++;
		}
		i++;
	}
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	wrd;
	size_t	lst_idx;

	wrd = 0;
	lst_idx = 0;
	if (s == NULL)
		return (NULL);
	wrd = count_words(s, c);
	lst = (char **)malloc(sizeof(char *) * (wrd + 1));
	if (lst == NULL)
		return (NULL);
	if (split(s, c, lst, wrd) == NULL)
		return (NULL);
	lst[wrd] = NULL;
	return (lst);
}
