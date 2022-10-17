/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:39:11 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 18:55:00 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	char	ch;
	int		i;

	string = (char *)s;
	ch = (char)c;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ch)
			return (&string[i]);
		i++;
	}
	if (string[i] == ch)
		return (&string[i]);
	return (0);
}
