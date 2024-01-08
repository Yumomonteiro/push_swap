/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:07 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 19:00:36 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void args_converter(int argc, char **argv, push_list **stack, int i)
{
	while(i < argc)
	{
		int num = ft_atoi(argv[i]);
		ft_lstadd_back(stack, num);
		i++;
	}
}

void check_args(int argc, char **argv, push_list **stack)
{
        if(argc < 2)
                ft_printf("Numero de argumentos invalido");
        if(argc == 2)
        {
                int i;
                char **split_result;

                i = 0;
                split_result = ft_split(argv[1], ' ');
                if(split_result == NULL)
                {
                        ft_printf("Erro ao dividir a string\n");
                        return ;
                }
                args_converter(argc, split_result, stack, 0);
                free(split_result);
        }
        else 
                args_converter(argc, argv, stack, 1);
}
int main(int argc, char **argv)
{
		push_list *stackA = NULL;
		push_list *stackB = NULL;
                check_args(argc, argv, &stackA);
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