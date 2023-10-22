/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:48:44 by svaccaro          #+#    #+#             */
/*   Updated: 2023/10/23 00:11:19 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(const char *s, const char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			cnt++;
	}
	return (cnt);
}

static void	*free_all(char **s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
	return (NULL);
}

static char	*next_word(const char *s, char c, size_t *i)
{
	size_t	word_start;

	while (s[*i] && s[*i] == c)
		(*i)++;
	word_start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (ft_substr(s, word_start, *i - word_start));
}

char	**ft_split(const char *s, char c)
{
	char	**ssplit;
	size_t	wcnt;
	size_t	ci;
	size_t	wi;

	wcnt = word_counter(s, c);
	ssplit = malloc((wcnt + 1) * sizeof(char *));
	if (!ssplit)
		return (NULL);
	ci = 0;
	wi = 0;
	while (wi < wcnt)
	{
		ssplit[wi] = next_word(s, c, &ci);
		if (!ssplit[wi])
			return (free_all(ssplit, wi));
		wi++;
	}
	ssplit[wi] = NULL;
	return (ssplit);
}
