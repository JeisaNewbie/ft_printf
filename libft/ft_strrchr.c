/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:43:18 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 18:55:13 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	string = (char *)s;
	ch = (char)c;
	i = 0;
	while (string[i])
		i++;
	while (i >= 0)
	{
		if (string[i] == ch)
			return (&string[i]);
		i--;
	}
	return (0);
}
