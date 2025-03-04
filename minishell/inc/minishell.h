/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:48:22 by vnicoles          #+#    #+#             */
/*   Updated: 2025/03/04 16:21:23 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_node_type {
	NODE_CMD,
	NODE_PIPE,
	NODE_REDIR_IN,
	NODE_REDIR_OUT,
	NODE_REDIR_APPEND,
	NODE_HEREDOC,
	NODE_AND,
	NODE_OR,
	NODE_GROUP,
} t_node_type;

typedef struct s_ast_node {
	t_node_type type;
	char **args;
	struct s_ast_node *left;
	struct s_ast_node *right;
} t_ast_node;

typedef struct s_arena {
	char	*mem;
	size_t	size;
	size_t	used;
} t_arena;

t_arena	*arena_init(size_t size);
static int	arena_expand(t_arena *arena);
void	*arena_malloc(t_arena *arena, size_t size);
void	arena_reset(t_arena *arena);
void	arena_free(t_arena *arena);


#endif


