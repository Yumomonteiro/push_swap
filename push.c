/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:39:25 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 12:39:34 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_stackB(push_list **stackA, push_list **stackB)
{
	if(*stackA == NULL)
		return;
		
	push_list *topA = *stackA;
	
	*stackA = topA->next;

	topA->next = *stackB;
	*stackB = topA;
        printf("pb\n");
}
void push_stackA(push_list **stackA, push_list **stackB)
{
	if(*stackB == NULL)
		return;
		
	push_list *topB = *stackB;
	
	*stackB = topB->next;

	topB->next = *stackA;
	*stackA = topB;
        printf("pa\n");
}