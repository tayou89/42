/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:50:18 by tayou             #+#    #+#             */
/*   Updated: 2022/11/20 16:16:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy_lst;

	copy_lst = *lst;
	if (copy_lst == NULL)
	{
		copy_lst = new;
		return ;
	}
	while (copy_lst->next != NULL)
		copy_lst = copy_lst->next;
	copy_lst->next = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list	*lst[10];
	t_list	*new;
	char	*s1 = "111111";
	char	*s2 = "222222";
	char	*s3 = "333333";
	char	*s4 = "new";
	int		size;
	int		i;

	lst[0] = ft_lstnew((void *) s1);
	lst[1] = ft_lstnew((void *) s2);
	lst[2] = ft_lstnew((void *) s3);
	new = ft_lstnew((void *) s4);
	i = 0;
	while (i < 2)
	{
		lst[i]->next = lst[i + 1];
		i++;
	}
	size = ft_lstsize(lst[0]);
	printf("before list_size: %d\n", size);
	ft_lstadd_back(&lst[0], new);
	size = ft_lstsize(lst[0]);
	printf("after list_size: %d\n", size);
	return (0);
}	
*/
