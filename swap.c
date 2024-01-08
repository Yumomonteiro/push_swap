/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:39:51 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 12:40:00 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap_stackA(push_list **lst)
{
	if(*lst == NULL || (*lst)->next == NULL)
		return ;
	push_list *first = *lst;
	push_list *second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
        printf("sa\n");
}
void swap_stackB(push_list **lst)
{
	if(*lst == NULL || (*lst)->next == NULL)
		return ;
	push_list *first = *lst;
	push_list *second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
        printf("sb\n");
}
void swap_both(push_list **stackA, push_list **stackB)
{
        swap_stackA(stackA);
        swap_stackB(stackB);
        printf("ss\n");
}