/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yude-oli <yude-oli@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:37:26 by yude-oli          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:26 by yude-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct push_swap
{
	struct push_swap *next;
	struct push_swap *prev;
	int data;
} push_list;

void push_stackA(push_list **stackA, push_list **stackB);
void push_stackB(push_list **stackA, push_list **stackB);
void reverse_rotate_stackA(push_list **stack);
void reverse_rotate_stackB(push_list **stack);
void reverse_rotate_both(push_list **stackA, push_list **stackB);
void rotate_stackA(push_list **stack);
void rotate_stackB(push_list **stack);
void rotate_both(push_list **stackA, push_list **stackB);
void swap_stackA(push_list **lst);
void swap_stackB(push_list **lst);
void swap_both(push_list **stackA, push_list **stackB);
int ft_atoi(char *str);
push_list	*ft_lstnew(int data);
void	ft_lstadd_back(push_list **lst, int data);
int	ft_lstsize(push_list *lst);
char	**ft_split(char const *s, char c);
int	ft_printf(const char *string, ...);

#endif



