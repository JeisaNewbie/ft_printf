/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:38:38 by jhwang2           #+#    #+#             */
/*   Updated: 2022/10/26 20:15:46 by jhwang2          ###   ########.fr       */
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
	if (backup->string == NULL)
		return (0);
	backup->s_idx = backup->s_idx + i;
	return (1);
}
