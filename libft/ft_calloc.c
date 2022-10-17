/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:58:59 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 21:19:24 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	int		i;

	tmp = malloc(size * count);
	if (tmp == 0)
		return (0);
	i = size * count;
	ft_bzero (tmp, i);
	return (tmp);
}
