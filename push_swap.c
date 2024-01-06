/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:07 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/06 14:35:22 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CREATE STACKS AND INPLEMENT SWAP, ROTATE, REVERSE ROTATE, PUSH
//

#include <stdlib.h>
#include <stdio.h>

typedef struct push_swap
{
	void *next;
	void *prev;
	int data;
} push_list;


int ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == 9)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

push_list	*ft_lstnew(int data)
{
	push_list	*new_node;

	new_node = (push_list *)malloc(sizeof(push_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(push_list **lst, int data)
{
	push_list	*new;
	push_list	*last;
	
	new = ft_lstnew(data);
	if (!data)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new; 
}

void printList(push_list *lst)
{
	push_list *current = lst;
	while(current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void swap_top_stackA(push_list **lst)
{
	if(*lst == NULL || (*lst)->next == NULL)
		return ;
	push_list *first = *lst;
	push_list *second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	
	*lst = second;
}
void swap_top_stackB(push_list **lst)
{
	if(*lst == NULL || (*lst)->next == NULL)
		return ;
	push_list *first = *lst;
	push_list *second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	
	*lst = second;
}

void push_to_stackB(push_list **stackA, push_list **stackB)
{
	if(*stackA == NULL)
		return;
		
	push_list *topA = *stackA;
	
	*stackA = topA->next;

	topA->next = *stackB;
	*stackB = topA;
}
void push_to_stackA(push_list **stackA, push_list **stackB)
{
	if(*stackB == NULL)
		return;
		
	push_list *topB = *stackB;
	
	*stackB = topB->next;

	topB->next = *stackA;
	*stackA = topB;
}

void rotate_stack(push_list **stack)
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
}

void reverse_rotate_stack(push_list **stack)
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
}

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		push_list *stackA = NULL;
		push_list *stackB = NULL;
		int i;
		
		i = 1;
		while(i < argc)
		{
			int num = ft_atoi(argv[i]);
			ft_lstadd_back(&stackA, num);
			i++;
		}
		int num2 = 225;
		int num3 = 100;
		ft_lstadd_back(&stackB, num2);
		ft_lstadd_back(&stackB, num3);
		//reverse_rotate_stack(&stackA);
		//rotate_stack(&stackA);
		//push_to_stackA(&stackA, &stackB);
		//push_to_stackB(&stackA, &stackB);
		//swap_top_stackA(&stackA);
		//swap_top_stackB(&stackB);
		//print list
		printf("linked list stackA: ");
		printList(stackA);
		printf("\nstackB\n");
		printList(stackB);
		return 0;
		
	}
}