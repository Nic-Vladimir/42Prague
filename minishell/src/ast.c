/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:13 by vnicoles          #+#    #+#             */
/*   Updated: 2025/03/04 19:23:01 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/ast.h"

t_ast_node *ast_new_node(t_arena *arena, t_node_type type, char **args) {
	t_ast_node	*node;

	node = (t_ast_node *)arena_malloc(arena, sizeof(t_ast_node));
    if (!node)
        return NULL;
    node->type = type;
    node->args = args;
	node->left = NULL;
	node->right = NULL;
    return node;
}

t_ast_node *ast_node_insert(t_arena *arena, t_ast_node *root, t_node_type type, char **args) {
	if (!root)
		return ast_new_node(arena, type, args);
	if (type == NODE_PIPE || type == NODE_AND || type == NODE_OR) {
		t_ast_node *new_root = ast_new_node(arena, type, NULL);
		new_root->left = root;
		new_root->right = ast_new_node(arena, NODE_CMD, args);
		return new_root;
	}
	root->right = ast_node_insert(arena, root->right, type, args);
	return root;
}

void	ast_execute(t_ast_node *node) {
	if (!node)
		return;
	ast_execute(node->left);
	printf("Executing: %s\n", node->args ? node->args[0] : "[OPERATOR]");
	ast_execute(node->right);
}
