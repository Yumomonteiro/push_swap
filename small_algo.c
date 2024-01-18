/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:51:21 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/18 19:28:23 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_three(push_list **stack)
{
        while(!is_sorted(*stack))
        {
                if((*stack)->data > (*stack)->next->data)
                        swap_stackA(stack);
                else
                        reverse_rotate_stackA(stack);
                printList(*stack);
        }      
}
int min_node(push_list **stackA)
{
        push_list *current;
        current = *stackA;
        int min_node = current->data;
        while (current != NULL)
        {
                if(current->data < min_node)
                        min_node = current->data;
                current = current->next;
        }
        return (min_node);
}
void algo_four(push_list **stack_a, push_list **stack_b)
{
        int min_value = min_node(stack_a);
        printf("%d", min_value);
        while ((*stack_a)->data != min_value)
                rotate_stackA(stack_a);
        push_stackB(stack_a, stack_b);
        printList(*stack_a);
        algo_three(stack_a);
        printList(*stack_a);
        push_stackA(stack_a, stack_b);
}

void algo_five(push_list **stack_a, push_list **stack_b)
{
        int min_value = min_node(stack_a);
        while ((*stack_a)->data != min_value)
                rotate_stackA(stack_a);
        push_stackB(stack_a, stack_b);
        algo_four(stack_a, stack_b);
        push_stackA(stack_a, stack_b);
}






