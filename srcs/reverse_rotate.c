/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:36:28 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/26 10:35:19 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_stacka(t_list **stack)
{
	t_list	*current;
	t_list	*previous;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	previous->next = NULL;
	ft_printf("rra\n");
}

void	reverse_rotate_stackb(t_list **stack)
{
	t_list	*current;
	t_list	*previous;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current = *stack;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	previous->next = NULL;
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_list **stacka, t_list **stackb)
{
	reverse_rotate_stacka(stacka);
	reverse_rotate_stackb(stackb);
	ft_printf("rrr\n");
}
