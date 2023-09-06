/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:49:25 by svydrina          #+#    #+#             */
/*   Updated: 2023/02/24 21:51:23 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*arr;

	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (-1);
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}
