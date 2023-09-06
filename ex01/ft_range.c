/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:52:34 by svydrina          #+#    #+#             */
/*   Updated: 2023/02/23 16:03:20 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*ptr;
	int	ind;

	size = max - min;
	ind = 0;
	if (min >= max)
		return (NULL);
	ptr = malloc(size * sizeof(*ptr));
	while (ind < size && min < max)
	{
		*(ptr + ind) = min;
		ind++;
		min++;
	}
	return (ptr);
}
