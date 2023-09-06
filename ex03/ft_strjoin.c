/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:15:24 by svydrina          #+#    #+#             */
/*   Updated: 2023/02/23 22:03:37 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	count_len(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind])
		ind++;
	return (ind);
}

int	count_overall(int size, char **strs, char *sep)
{
	int	ind;
	int	overall_len;

	ind = 0;
	overall_len = 0;
	while (ind < size)
	{
		overall_len += count_len(strs[ind]);
		if (ind < size - 1)
			overall_len += count_len(sep);
		ind++;
	}
	return (overall_len + 1);
}

int	concat(char *dest, char *src, int dest_ind)
{
	int	ind;

	ind = 0;
	while (src[ind])
		dest[dest_ind++] = src[ind++];
	return (ind);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		ind;
	int		ind_len;
	int		overall;
	char	*string;

	ind = 0;
	ind_len = 0;
	if (size == 0)
	{
		string = malloc(1 * sizeof(char));
		string[0] = '\0';
		return (string);
	}
	overall = count_overall(size, strs, sep);
	string = malloc(overall * sizeof(char));
	while (ind < size && ind_len < overall)
	{
		ind_len += concat(string, strs[ind], ind_len);
		if (ind_len < overall - 1)
			ind_len += concat(string, sep, ind_len);
		ind++;
	}
	string[ind_len] = '\0';
	return (string);
}
