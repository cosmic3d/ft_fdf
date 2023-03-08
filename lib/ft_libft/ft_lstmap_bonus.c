/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:03:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/05/26 11:33:25 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*elt;
	t_list	*temp;

	if (!lst)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		temp = f(lst->content);
		elt = ft_lstnew(temp);
		if (!elt)
		{
			del(temp);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&newlist, elt);
			lst = lst->next;
		}
	}
	return (newlist);
}
