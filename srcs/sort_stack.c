/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:59:02 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/25 16:49:05 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_moves_to_top(t_list *stack, int target)
{
	int	moves;

	moves = 0;
	while (stack != NULL)
	{
		if (stack->data == target)
			break ;
		stack = stack->next;
		moves++;
	}
	return (moves);
}

t_list	*find_min_node(t_list *stack)
{
	t_list	*min_node;
	t_list	*current;

	if (stack == NULL)
		return (NULL);
	min_node = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (current->data < min_node->data)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*min_node;
	int			moves_to_top;

	while (*stack_a != NULL)
	{
		min_node = find_min_node(*stack_a);
		moves_to_top = count_moves_to_top(*stack_a, min_node->data);
		if (moves_to_top < (ft_lstsize(*stack_a) / 2))
		{
			while ((*stack_a)->data != min_node->data)
				rotate_stacka(stack_a);
		}
		else
		{
			while ((*stack_a)->data != min_node->data)
				reverse_rotate_stacka(stack_a);
		}
		push_stackb(stack_a, stack_b);
	}
	while (*stack_b != NULL)
		push_stacka(stack_a, stack_b);
}
