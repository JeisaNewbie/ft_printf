/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:43:39 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/20 17:27:13 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_same(char c, char const *set)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			check = 1;
		i++;
	}
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		index_f;
	int		index_l;

	if (s1 == 0)
		return (0);
	index_l = ft_strlen(s1);
	index_f = 0;
	index_l = index_l - 1;
	while (check_same (s1[index_f], set) && (index_f < index_l))
		index_f++;
	while (check_same (s1[index_l], set) && (index_f < index_l))
		index_l--;
	tmp = (char *)malloc(sizeof(char) * (index_l - index_f) + 2);
	if (tmp == 0)
		return (0);
	if (index_f == index_l && check_same (s1[index_f], set))
	{
		tmp[0] = '\0';
		return (tmp);
	}
	ft_strlcpy (tmp, &s1[index_f], (index_l - index_f) + 2);
	return (tmp);
}
