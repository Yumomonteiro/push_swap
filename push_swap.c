/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:07 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/24 12:53:44 by yude-oli         ###   ########.fr       */
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

int    check_dup(push_list *stackA)
{
        if (stackA == NULL)
                return 0;
        push_list *current = stackA;

        while(current != NULL)
        {
                push_list *runner = current->next;
                while (runner != NULL)
                {
                        if (current->data == runner->data)
                        {
                                printf("achou duplicados na lista");
                                return (0);
                        }
                        runner = runner->next;
                }
                current = current->next;
        }
        return (1);
}
int is_valid_argument(const char *arg)
{
        while (*arg)
        {
                if(!ft_isdigit(*arg) && *arg != ' ')
                        return 0;
                arg++;
        }
        return 1;   
}

int is_sorted(push_list *stackA)
{
        push_list *current;
        current = stackA;
        while(current && current->next)
        {
                if(current->data > current->next->data)
                        return 0;
                current = current->next;
        }
        return 1;
}

int check_args(int argc, char **argv, push_list **stack)
{
    if (argc < 2)
    {
        ft_printf("Error(args)\n");
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        if (argv[1][0] == '\0' || !is_valid_argument(argv[1]))
        {
            ft_printf("Error\n");
            return 0;
        }

        int size = 0;
        char **split_result;

        split_result = ft_split(argv[1], ' ');
        if (split_result == NULL)
        {
            ft_printf("Erro ao dividir a string\n(split)");
            return 0;
        }

        while (split_result[size])
            size++;
        args_converter(size, split_result, stack, 0);
        free(split_result);
    }
    else
    {
        args_converter(argc, argv, stack, 1);
    }
    return 1;
}

int main(int argc, char **argv)
{
		push_list *stackA = NULL;
		push_list *stackB = NULL;
                if(check_args(argc, argv, &stackA) == 0 && check_dup(stackA) == 0)
                        return 0;
                if(is_sorted(stackA))
                {
                        printf("list sorted");
                        return 0;
                }
                int size_list = ft_lstsize(stackA);
                if(size_list == 2)
                        swap_stackA(&stackA);
                if(size_list == 3)
                        algo_three(&stackA);
                if(size_list == 4)
                        algo_four(&stackA, &stackB);
                if(size_list == 5)
                        algo_five(&stackA, &stackB);
                if(size_list >= 6)
                        insertion_sort(&stackA, &stackB);
		printList(stackA);
                // printf("B");
                // printList(stackB);
                return 0;
}