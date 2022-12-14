/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:39:41 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/24 12:34:38 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0' && s1[i] != '%')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == 0)
		return (0);
	j = 0;
	while (i > 0)
	{
		tmp[j] = s1[j];
		j++;
		i--;
	}
	tmp[j] = '\0';
	return (tmp);
}
