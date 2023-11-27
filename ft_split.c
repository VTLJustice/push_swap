/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradules <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:36:29 by rradules          #+#    #+#             */
/*   Updated: 2023/11/27 17:36:58 by rradules         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_result(char **result)
{
	int	i;

	i = 0;
	if (result)
	{
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
}

int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**allocate_result(int num_words)
{
	char	**result;

	result = malloc((num_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[num_words] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	int		i;
	int		j;
	size_t	word_len;
	char	**result;

	num_words = count_words(s, c);
	result = allocate_result(num_words);
	if (!result)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < num_words)
	{
		while (s[i] == c)
			i++;
		word_len = get_word_len(&s[i], c);
		result[j] = malloc((word_len + 1) * sizeof(char));
		if (!result[j])
			return (free_result(result), NULL);
		ft_memcpy(result[j], &s[i], word_len);
		result[j][word_len] = '\0';
		i = i + word_len;
	}
	return (result);
}
