/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:41:29 by vnicoles          #+#    #+#             */
/*   Updated: 2024/05/12 17:54:19 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	typedef struct node
	{
		int	val;
		struct node * next;
	} node_t;
	
	node_t * head = NULL;
	head = (node_t *) malloc(sizeof(node_t));
	if (head == NULL) {
		return (1);
	}
	head->val = 1;
	head->next = NULL;
	
	void print_list(node_t * head) {
		node_t * current = head;

		while (current != NULL) {
			printf("%d\n", current->val);
			current = current->next;
		}
	}

	print_list(head);
	
	return (0);
}
