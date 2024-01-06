/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:07 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/06 17:23:12 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct push_swap
{
	struct push_swap *next;
	struct push_swap *prev;
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
void args_converter(int argc, char **argv, push_list **stack)
{
        int i = 1;
	while(i < argc)
	{
		int num = ft_atoi(argv[i]);
		ft_lstadd_back(stack, num);
		i++;
	}
}
void free_list(int i, push_list **stackA);

int	ft_lstsize(push_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if(argc <= 1)
        {
               //funcao para sair do programa e limpar tudo 
               //tratamento de erros e free da lista  
        }
		push_list *stackA = NULL;
		push_list *stackB = NULL;
                args_converter(argc, argv, &stackA);
                if(ft_lstsize(stackA) == 2)
                        swap_stackA(&stackA);
               
                        
                        
                //bubble_sort(&stackA);
		// int num2 = 225;
		// int num3 = 100;
		// ft_lstadd_back(&stackB, num2);
		// ft_lstadd_back(&stackB, num3);
		//reverse_rotate_stackA(&stackA);
                //reverse_rotate_stackB(&stackB);
                //reverse_rotate_both(&stackA, &stackB);
		//rotate_stackA(&stackA);
                //rotate_stackB(&stackB);
                //rotate_both(&stackA, &stackB);
		//push_to_stackA(&stackA, &stackB);
		//push_stackB(&stackA, &stackB);
		//swap_top_stackA(&stackA);
		//swap_top_stackB(&stackB);
                //swap_both(&stackA, &stackB);
		//print list
		printf("linked list stackA: ");
		printList(stackA);
		printf("\nstackB\n");
		printList(stackB);
		return 0;
}