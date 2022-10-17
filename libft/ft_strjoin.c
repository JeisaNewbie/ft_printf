/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:07:45 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/20 17:23:32 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		len_s1;
	int		len_s2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (tmp == 0)
		return (0);
	tmp[0] = '\0';
	ft_strlcat(tmp, s1, len_s1 + 1);
	ft_strlcat(tmp, s2, len_s1 + len_s2 + 1);
	tmp[len_s1 + len_s2] = '\0';
	return (tmp);
}
