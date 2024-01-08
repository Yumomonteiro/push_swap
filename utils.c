/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:43:43 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:10 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



push_list	*ft_lstnew(int data)
{
	push_list	*new_node;

	new_node = (push_list *)malloc(sizeof(push_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(push_list **lst, int data)
{
	push_list	*new;
	push_list	*last;
	
	new = ft_lstnew(data);
	if (!data)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new; 
}

int	ft_lstsize(push_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
