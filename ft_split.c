/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahayne <mtahayne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:47:00 by mtahayne          #+#    #+#             */
/*   Updated: 2026/11/07 16:47:00 by mtahayne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_isspace(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_isspace(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*extract_word(const char **str)
{
	int		len;
	char	*word;
	int		i;

	while (**str && ft_isspace(**str))
		(*str)++;
	len = 0;
	while ((*str)[len] && !ft_isspace((*str)[len]))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[i] = '\0';
	*str += len;
	return (word);
}

static void	*free_split_err(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split_spaces(const char *str)
{
	char	**tab;
	int		words;
	int		i;

	if (!str)
		return (NULL);
	words = count_words(str);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < words)
	{
		tab[i] = extract_word(&str);
		if (!tab[i])
			return (free_split_err(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
