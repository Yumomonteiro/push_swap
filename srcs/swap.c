/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:39:51 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/25 16:49:05 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stacka(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	ft_printf("sa\n");
}

void	swap_stackb(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	ft_printf("sb\n");
}

void	swap_both(t_list **stacka, t_list **stackb)
{
	swap_stacka(stacka);
	swap_stackb(stackb);
	ft_printf("ss\n");
}
