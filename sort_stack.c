#include "push_swap.h"

int count_moves_to_top(push_list *stack, int target)
{
    int moves = 0;

    while (stack != NULL)
    {
        if (stack->data == target)
            break;

        stack = stack->next;
        moves++;
    }

    return moves;
}

push_list *find_min_node(push_list *stack)
{
    if (stack == NULL)
        return NULL;

    push_list *min_node = stack;
    push_list *current = stack->next;

    while (current != NULL)
    {
        if (current->data < min_node->data)
            min_node = current;

        current = current->next;
    }

    return min_node;
}
void insertion_sort(push_list **stack_a, push_list **stack_b)
{
    while (*stack_a != NULL)
    {
        push_list *min_node = find_min_node(*stack_a);
        int moves_to_top = count_moves_to_top(*stack_a, min_node->data);

        if (moves_to_top < (ft_lstsize(*stack_a) / 2))
        {
            while ((*stack_a)->data != min_node->data)
                rotate_stackA(stack_a);
        }
        else
        {
            while ((*stack_a)->data != min_node->data)
                reverse_rotate_stackA(stack_a);
        }

        push_stackB(stack_a, stack_b);
    }

    while (*stack_b != NULL)
        push_stackA(stack_a, stack_b);
}