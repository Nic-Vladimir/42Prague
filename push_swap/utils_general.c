/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:30:58 by vnicoles          #+#    #+#             */
/*   Updated: 2024/10/28 17:42:39 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Free the stack
void	ft_free(t_stack **list)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(lst);
		*lst = tmp;
	}
}


// Print Error because it's thoughtful and demure
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}


// Check if the stack is sorted
int	ft_checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->nbr;
	}
	return (1);
}
