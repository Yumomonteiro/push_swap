/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:13:07 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/27 16:18:56 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		ft_printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void	args_converter(int argc, char **argv, t_list **stack, int i)
{
	int	num;

	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_lstadd_back(stack, num);
		i++;
	}
}

int	check_dup(t_list *stackA)
{
	t_list	*current;
	t_list	*runner;

	if (stackA == NULL)
		return (0);
	current = stackA;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
			{
				ft_printf("Error\n");
				return (0);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

int	check_args(int argc, char **argv, t_list **stack)
{
	char	**split_result;
	int		size;

	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			ft_printf("Error\n");
			return (0);
		}
		size = 0;
		split_result = ft_split(argv[1], ' ');
		if (split_result == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		while (split_result[size])
			size++;
		args_converter(size, split_result, stack, 0);
		ft_free(split_result);
	}
	else
		args_converter(argc, argv, stack, 1);
	return (1);
}

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	int		size_list;

	size_list = ft_lstsize(*stack_a);
	ft_give_index(stack_a, size_list);
	if (size_list == 2)
		swap_stacka(stack_a);
	if (size_list == 3)
		algo_three(stack_a);
	if (size_list == 4)
		algo_four(stack_a, stack_b);
	if (size_list == 5)
		algo_five(stack_a, stack_b);
	if (size_list >= 6)
		ft_radix_sort(stack_a, stack_b, size_list);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (check_args(argc, argv, &stack_a) == 0 || check_dup(stack_a) == 0
		|| ft_lstsize(stack_a) == 0 || ft_lstsize(stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0); 
	}
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	sort_list(&stack_a, &stack_b);
        // printlist(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
