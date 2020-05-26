/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:03:23 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/09 14:53:27 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	**lst_null;

	lst_null = lst;
	if (!lst || !*lst || !del)
		return ;
	else
	{
		while (*lst)
		{
			p = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = p;
		}
		*lst_null = 0;
	}
}
