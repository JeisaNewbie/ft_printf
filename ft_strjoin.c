/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:07:45 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/26 20:17:16 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"

char	*ft_strjoin(t_backup *backup, char *s2, int s2_idx)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (backup->s_idx + s2_idx + 1));
	if (tmp == NULL)
		return (0);
	while (i < backup->s_idx)
	{
		tmp[i] = backup->string[i];
		i++;
	}
	i = 0;
	while (i < s2_idx)
	{
		tmp[i + backup->s_idx] = s2[i];
		i++;
	}
	tmp[backup->s_idx + s2_idx] = '\0';
	free (backup->string);
	free (s2);
	return (tmp);
}
