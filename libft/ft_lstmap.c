/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:26:28 by jhwang2           #+#    #+#             */
/*   Updated: 2022/07/20 18:24:28 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	newlist = 0;
	while (lst)
	{
		tmp = ft_lstnew (f(lst->content));
		if (tmp == 0)
		{
			tmp = newlist;
			while (newlist != 0)
			{
				free(newlist->content);
				newlist = newlist->next;
			}
			ft_lstclear (&tmp, del);
			return (0);
		}
		ft_lstadd_back (&newlist, tmp);
		lst = lst->next;
	}
	return (newlist);
}
