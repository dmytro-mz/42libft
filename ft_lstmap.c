/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:14:06 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/02 12:14:07 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	res = ft_lstnew((*f)(lst->content));
	if (!res)
		return (NULL);
	res->next = NULL;
	if (lst->next)
	{
		res->next = ft_lstmap(lst->next, f, del);
		if (!(res->next))
		{
			ft_lstdelone(res, del);
			return (NULL);
		}
	}
	return (res);
}
