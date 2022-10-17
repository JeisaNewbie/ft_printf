/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:07:51 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/18 16:27:43 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmplst;

	if (lst == 0)
		return ;
	else if (*lst == 0)
		*lst = new;
	else
	{
		tmplst = ft_lstlast(*lst);
		tmplst->next = new;
	}
}
