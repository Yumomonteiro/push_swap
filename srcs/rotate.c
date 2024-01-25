/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:38:52 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/25 16:49:05 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stacka(t_list **stack)
{
	t_list	*first;
	t_list	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*stack = first->next;
	current->next = first;
	first->next = NULL;
	printf("ra\n");
}

void	rotate_stackb(t_list **stack)
{
	t_list	*first;
	t_list	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*stack = first->next;
	current->next = first;
	first->next = NULL;
	printf("rb\n");
}

void	rotate_both(t_list **stackA, t_list **stackB)
{
	rotate_stacka(stackA);
	rotate_stackb(stackB);
	printf("rr\n");
}
