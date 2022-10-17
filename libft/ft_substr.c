/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:44:08 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/20 17:21:54 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	is_large(size_t len_s, size_t len)
{
	if (len_s <= len)
		return (1);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*tmp;

	if (s == 0)
		return (0);
	len_s = ft_strlen(s);
	if (is_large (len_s, len))
		tmp = (char *)malloc(sizeof(char) * (len_s + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	if (len_s < start)
	{
		tmp[0] = 0;
		return (tmp);
	}
	if (is_large (len_s, len))
		ft_strlcpy (tmp, &s[start], len_s + 1);
	else
		ft_strlcpy (tmp, &s[start], len + 1);
	return (tmp);
}
