/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:09:48 by svydrina          #+#    #+#             */
/*   Updated: 2023/03/01 20:27:32 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	dans_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	wrd_cnt(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && !dans_sep(str[i], sep))
			|| (dans_sep(str[i - 1], sep) && !dans_sep(str[i], sep)))
			count++;
		i++;
	}
	return (count);
}

char	**malloc_arr(char **arr, char *str, char *sep)
{
	int	str_i;
	int	arr_i;
	int	len;

	str_i = 0;
	arr_i = 0;
	while (str[str_i])
	{
		len = 0;
		while (str[str_i] && dans_sep(str[str_i], sep))
			str_i++;
		if (str[str_i] && !dans_sep(str[str_i], sep))
		{
			while (str[str_i] && !dans_sep(str[str_i], sep))
			{
				len++;
				str_i++;
			}
			if (arr_i < wrd_cnt(str, sep))
				arr[arr_i++] = malloc(sizeof(char) * (len + 1));
		}
	}
	return (arr);
}

char	**fill_arr(char **arr, char *str, char *sep)
{
	int	str_i;
	int	arr_i;
	int	w_i;

	str_i = 0;
	arr_i = 0;
	while (str[str_i])
	{
		w_i = 0;
		while (str[str_i] && dans_sep(str[str_i], sep))
			str_i++;
		if (str[str_i] && !dans_sep(str[str_i], sep))
		{
			while (str[str_i] && !dans_sep(str[str_i], sep))
				arr[arr_i][w_i++] = str[str_i++];
			arr[arr_i][w_i] = '\0';
			arr_i++;
		}
	}
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		word_count;

	word_count = wrd_cnt(str, charset);
	strs = malloc((word_count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = malloc_arr(strs, str, charset);
	strs = fill_arr(strs, str, charset);
	return (strs);
}
