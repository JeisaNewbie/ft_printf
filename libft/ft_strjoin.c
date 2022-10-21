/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:07:45 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/21 21:19:50 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		len_s1;
	int		len_s2;
	int		i;

	i = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (tmp == NULL)
		return (0);
	while (i++ < len_s1)
		tmp[i] = s1[i];
	i = 0;
	while (i < len_s2)
	{
		tmp[i + len_s1] = s2[i];
		i++;
	}
	tmp[len_s1 + len_s2] = '\0';
	free (s1);
	free (s2);
	return (tmp);
}
