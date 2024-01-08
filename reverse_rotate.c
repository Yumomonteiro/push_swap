/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:36:28 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 12:36:58 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_stackA(push_list **stack)
{

    if (*stack == NULL || (*stack)->next == NULL)
        return; 
    push_list *current = *stack;
    push_list *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    current->next = *stack;
    *stack = current;
    previous->next = NULL;
    printf("rra\n");
}
void reverse_rotate_stackB(push_list **stack)
{

    if (*stack == NULL || (*stack)->next == NULL)
        return; 
    push_list *current = *stack;
    push_list *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    // Faz o reverse rotate
    current->next = *stack;
    *stack = current;
    previous->next = NULL;
    printf("rrb\n");
}

void reverse_rotate_both(push_list **stackA, push_list **stackB)
{
        reverse_rotate_stackA(stackA);
        reverse_rotate_stackB(stackB);
        printf("rrr\n");
        
}