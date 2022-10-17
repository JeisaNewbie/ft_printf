/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:34:22 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/15 21:13:28 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*string;
	void			*return_s;

	ch = (unsigned char)c;
	string = (unsigned char *)s;
	while (n)
	{
		if (*string == ch)
		{
			return_s = string;
			return (return_s);
		}
		string++;
		n--;
	}
	if (n > 0 && *string == ch)
	{
		return_s = string;
		return (return_s);
	}
	return (0);
}
