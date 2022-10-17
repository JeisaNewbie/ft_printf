/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:04 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/20 17:38:38 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmplist;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	tmplist = *lst;
	while (tmplist)
	{
		tmplist = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmplist;
	}
}
