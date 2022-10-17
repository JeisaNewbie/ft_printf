/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:42:52 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 19:52:35 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*string_h;
	size_t	len_needle;
	size_t	i;

	string_h = (char *)haystack;
	len_needle = 0;
	i = 0;
	if (needle[i] == '\0')
		return (string_h);
	while (needle[len_needle])
		len_needle++;
	while ((i < len) && (haystack[i] != '\0'))
	{
		if (haystack[i] == needle[0])
		{
			if ((ft_strncmp (&haystack[i], needle, len_needle) == 0)
				&& (i + len_needle <= len))
				return (&string_h[i]);
		}
		i++;
	}
	return (0);
}
