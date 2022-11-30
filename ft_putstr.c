/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:38:38 by jhwang2           #+#    #+#             */
/*   Updated: 2022/11/30 14:59:50 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_backup *backup)
{
	char	*tmp;
	int		s_len;
	int		i;

	if (s == 0)
		s = "(null)";
	s_len = ft_strlen (s);
	tmp = (char *)malloc (sizeof (char) * s_len + 1);
	if (tmp == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	backup->string = ft_strjoin (backup, tmp, i);
	free (tmp);
	if (backup->string == NULL)
		return (0);
	backup->s_idx = backup->s_idx + i;
	return (1);
}
