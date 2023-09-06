/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:22:52 by svydrina          #+#    #+#             */
/*   Updated: 2023/02/23 18:36:29 by svydrina         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		len;
	char	*dest;
	int		ind;

	len = count_len(src);
	dest = malloc((len +1) * sizeof(char));
	if (!(dest))
		return (NULL);
	ind = 0;
	while (src[ind])
	{
		dest[ind] = src[ind];
		ind++;
	}
	dest[ind] = '\0';
	return (dest);
}
