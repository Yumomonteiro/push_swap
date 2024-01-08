/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:38:52 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 12:39:01 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stackA(push_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return; 

    push_list *first = *stack;
    push_list *current = *stack;

    while (current->next != NULL)
    {
        current = current->next;
    }

    // Faz o shift up
    *stack = first->next;
    current->next = first;
    first->next = NULL;
    printf("ra\n");
}
void rotate_stackB(push_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return; 

    push_list *first = *stack;
    push_list *current = *stack;

    while (current->next != NULL)
    {
        current = current->next;
    }

    // Faz o shift up
    *stack = first->next;
    current->next = first;
    first->next = NULL;
    printf("rb\n");
}
void rotate_both(push_list **stackA, push_list **stackB)
{
        rotate_stackA(stackA);
        rotate_stackB(stackB);
        printf("rr\n");
}