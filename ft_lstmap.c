/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:02:06 by tayou             #+#    #+#             */
/*   Updated: 2023/01/07 17:06:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_head;
	void	*f_address;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	lst_head = NULL;
	while (lst != NULL)
	{
		f_address = f(lst->content);
		new_lst = ft_lstnew(f_address);
		if (new_lst == NULL)
		{
			del(f_address);
			ft_lstclear(&lst_head, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_head, new_lst);
		lst = lst->next;
	}
	new_lst = NULL;
	return (lst_head);
}
