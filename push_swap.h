/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:25:47 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/27 16:07:29 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct push_swap
{
	struct push_swap	*next;
	int					data;
	int					index;
}						t_list;

void	push_stacka(t_list **stackA, t_list **stackB);
void	push_stackb(t_list **stackA, t_list **stackB);
void	reverse_rotate_stacka(t_list **stack);
void	reverse_rotate_stackb(t_list **stack);
void	reverse_rotate_both(t_list **stackA, t_list **stackB);
void	rotate_stacka(t_list **stack);
void	rotate_stackb(t_list **stack);
void	rotate_both(t_list **stackA, t_list **stackB);
void	swap_stacka(t_list **lst);
void	swap_stackb(t_list **lst);
void	swap_both(t_list **stackA, t_list **stackB);
//utils
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, int data);
int		ft_lstsize(t_list *lst);
int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
int		ft_printf(const char *string, ...);
int		ft_isdigit(int c);
void	printlist(t_list *lst);
int		is_sorted(t_list *stack);
int		min_node(t_list **stackA);
void	ft_give_index(t_list **stack, int size);
//algorithm
void	algo_five(t_list **stack_a, t_list **stack_b);
void	algo_three(t_list **stack);
void	algo_four(t_list **stack_a, t_list **stack_b);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int size);
//free functions
void	free_stack(t_list **stack);
void	ft_free(char **str);

#endif