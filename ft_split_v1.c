#include "libft.h"

static size_t	g_word;
static char		**g_list;
static size_t	g_list_index;

static void	count_words(char const *s, char c)
{
	int		is_word;

	is_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!is_word)
			{
				is_word = 1;
				g_word++;
			}
		}
		else if (*s == c && is_word)
			is_word = 0;
		s++;
	}
}

static void	free_all(void)
{
	while (*g_list)
	{
		free(*g_list);
		g_list++;
	}
	free(g_list);
}

static int	fill_list(char const *s, size_t start, size_t end)
{
	char			*s1;
	char			*ptr;

	s1 = malloc(sizeof(char) * (end - start + 2));
	if (s1 == NULL)
	{
		g_list[g_list_index] = NULL;
		return (-1);
	}
	ptr = s1;
	while (start <= end)
		*s1++ = s[start++];
	*s1 = '\0';
	g_list[g_list_index++] = ptr;
	return (0);
}

static int	split_list(char const *s, char c)
{
	size_t	i;
	size_t	is_word;
	size_t	start;

	i = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c && !is_word)
		{
			start = i;
			is_word = 1;
		}
		else if (s[i] == c && is_word)
		{
			is_word = 0;
			if (fill_list(s, start, i - 1) == -1)
				return (-1);
		}
		i++;
	}
	if (s[i - 1] != c && is_word)
		if (fill_list(s, start, i - 1) == -1)
			return (-1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	g_word = 0;
	g_list_index = 0;
	if (s == NULL)
		return (NULL);
	count_words(s, c);
	g_list = (char **)malloc(sizeof(char *) * (g_word + 1));
	if (g_list == NULL)
		return (NULL);
	if (split_list(s, c) == -1)
	{
		free_all();
		return (NULL);
	}
	g_list[g_list_index] = NULL;
	return (g_list);
}
