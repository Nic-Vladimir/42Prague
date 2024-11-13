/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:16:18 by vnicoles          #+#    #+#             */
/*   Updated: 2024/11/11 18:58:53 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Returns the last element of stack
// t_stack	*ft_stack_last(t_stack *stack)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next)
// 		stack = stack->next;
// 	return (stack);
// }

// Returns the smallest number
int	ft_min(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

// Returns the biggest number
int	ft_max(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}
