/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:37:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/21 20:28:16 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putchar(char c, static char *string)
{
	char	*tmp;

	tmp = (char *)malloc (sizeof (char) * 2);
	if (tmp == NULL)
		return (0);
	tmp[0] = c;
	tmp[1] = '\0';
	string = ft_strjoin (string, tmp);
	if (string ==NULL)
		return (0);
	return (1);
}
