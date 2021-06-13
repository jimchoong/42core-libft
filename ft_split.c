#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		is_word;
	size_t	wrd;

	is_word = 0;
	wrd = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			wrd++;
		}
		else if (*s == c && is_word)
			is_word = 0;
		s++;
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

static char	**split(char const *s, char c, char **lst, size_t n)
{
	size_t	i;
	size_t	is_word;
	size_t	start;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (s[i] != c && !is_word)
		{
			start = i;
			is_word = 1;
		}
		else if ((s[i] == c || s[i] == '\0') && is_word)
		{
			is_word = 0;
			if (fill((s + start), i - start, lst, n) == NULL)
				return (NULL);
			n++;
		}
		if (!s[i])
			break ;
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
	if (split(s, c, lst, lst_idx) == NULL)
		return (NULL);
	lst[wrd] = NULL;
	return (lst);
}
