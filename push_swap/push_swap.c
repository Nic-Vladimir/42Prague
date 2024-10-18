/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:35:39 by vnicoles          #+#    #+#             */
/*   Updated: 2024/10/18 05:15:44 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int argc, char **argv) {
  t_stack *a;

  a = ft_process(argc, argv);
  if (!a || ft_checkdup(a)) {
    ft_free(&a);
    ft_error();
  }
  if (!ft_checksorted(a))
    ft_sort(&a);
  ft_free(&a);
  return (0);
}

int ft_checkdup(t_stack *a) {
  t_stack *tmp;

  while (a) {
    tmp = a->next;
    while (tmp) {
      if (a->nbr == tmp->nbr)
        return (1);
      tmp = tmp->next;
    }
    a = a->next;
  }
  return (0);
}

int ft_checksorted(t_stack *stack_a) {
  int i;

  i = stack_a->nbr;
  while (stack_a) {
    if (i > stack_a->nbr)
      return (0);
    i = stack_a->nbr;
    stack_a = stack_a->next;
  }
  return (1);
}
