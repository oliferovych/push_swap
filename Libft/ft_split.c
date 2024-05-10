/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:02:44 by dolifero          #+#    #+#             */
/*   Updated: 2024/03/16 14:29:43 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	split_free(char **splitted, int j)
{
	if (j == 0)
	{
		free(splitted);
		return ;
	}
	while (j > 0)
	{
		free(splitted[j]);
		j--;
	}
	free(splitted[j]);
	free(splitted);
}

static char	**splitting(char **splitted, int words, char c, const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		splitted[j] = ft_substr(s, i, word_len(s, c, i));
		if (!splitted[j])
		{
			split_free(splitted, j);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	splitted[j] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	splitted = (char **)malloc((words + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	return (splitting(splitted, words, c, s));
}
