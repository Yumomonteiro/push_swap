/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:39:25 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/25 17:20:49 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stackb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
	ft_printf("pb\n");
}

void	push_stacka(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (*stack_b == NULL)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
	ft_printf("pa\n");
}
