/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:21 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/27 15:13:33 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stacka)
{
	t_list	*current;

	current = stacka;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	min_node(t_list **stacka)
{
	t_list	*current;
	int		min_node;

	current = *stacka;
	min_node = current->data;
	while (current != NULL)
	{
		if (current->data < min_node)
			min_node = current->data;
		current = current->next;
	}
	return (min_node);
}

void	algo_three(t_list **stack)
{
	while (!is_sorted(*stack))
	{
		if ((*stack)->data > (*stack)->next->data)
			swap_stacka(stack);
		else
			reverse_rotate_stacka(stack);
	}
}

void	algo_four(t_list **stack_a, t_list **stack_b)
{
	int	min_value;

	min_value = min_node(stack_a);
	while ((*stack_a)->data != min_value)
		rotate_stacka(stack_a);
	push_stackb(stack_a, stack_b);
	algo_three(stack_a);
	push_stacka(stack_a, stack_b);
}

void	algo_five(t_list **stack_a, t_list **stack_b)
{
	int	min_value;

	min_value = min_node(stack_a);
	while ((*stack_a)->data != min_value)
		rotate_stacka(stack_a);
	push_stackb(stack_a, stack_b);
	algo_four(stack_a, stack_b);
	push_stacka(stack_a, stack_b);
}
