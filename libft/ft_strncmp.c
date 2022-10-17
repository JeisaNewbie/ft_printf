/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:42:42 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 21:41:09 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n && (string1[i] == string2[i]))
	{
		if (string1[i] == '\0' && string2[i] == '\0')
			break ;
		i++;
		n--;
	}
	if (n == 0)
		return (string1[i - 1] - string2[i - 1]);
	return (string1[i] - string2[i]);
}
