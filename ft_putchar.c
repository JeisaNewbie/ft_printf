/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:37:40 by jhwang2           #+#    #+#             */
/*   Updated: 2022/11/30 15:00:07 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_backup *backup)
{
	char	*tmp;

	tmp = (char *)malloc (sizeof (char) * 2);
	if (tmp == NULL)
		return (0);
	tmp[0] = c;
	tmp[1] = '\0';
	backup->string = ft_strjoin (backup, tmp, 1);
	free (tmp);
	if (backup->string == NULL)
		return (0);
	backup->s_idx++;
	return (1);
}
