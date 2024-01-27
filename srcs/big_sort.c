/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:12:20 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/27 15:14:39 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_get_min(t_list **stack, long limit)
{
	t_list	*current;
	t_list	*min_elmt;
	int		min_found;

	if (!*stack)
		return (0);
	current = *stack;
	min_found = 2147483647;
	min_elmt = *stack;
	while (current)
	{
		if (current->data > limit && current->data <= min_found)
		{
			min_found = current->data;
			min_elmt = current;
		}
		current = current->next;
	}
	return (min_elmt);
}

void	ft_give_index(t_list **stack, int size)
{
	int		i;
	long	min_found;
	t_list	*min_elmt;

	min_found = -2147483649;
	i = 0;
	while (i < size)
	{
		min_elmt = ft_get_min(stack, min_found);
		min_elmt->index = i;
		min_found = min_elmt->data;
		i++;
	}
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	unsigned int	i;
	unsigned int	bit;
	t_list			*current;

	bit = 0;
	while (bit < 32)
	{
		i = 0;
		current = *stack_a;
		while (i < (unsigned int) size)
		{
			if ((1 & (current->index >> bit)) == 0)
				push_stackb(stack_a, stack_b);
			else
				rotate_stacka(stack_a);
			current = *stack_a;
			i++;
		}
		current = *stack_b;
		while (*stack_b)
			push_stacka(stack_a, stack_b);
		bit++;
		if (is_sorted(*stack_a))
			return ;
	}
}
