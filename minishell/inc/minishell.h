/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:48:22 by vnicoles          #+#    #+#             */
/*   Updated: 2025/03/20 02:04:46 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "arena.h"
#include "ast.h"
#include "env.h"
#include "tokenizer.h"

#include "../lib/libft/inc/libft.h"
#include <dirent.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

t_arena *arena_init(size_t size);
void *arena_malloc(t_arena *arena, size_t size);
void arena_reset(t_arena *arena);
void arena_free(t_arena *arena);
t_token *tokenize(t_tokenizer_data *data, char *input);
t_ast_node *parse(t_tokenizer_data *data);
void debug_ast(t_ast_node *root);
int execute_node(t_env *env, t_ast_node *node, int in_fd, int out_fd);
int hashmap_insert(t_env *env, char *key, char *value);
t_env *init_env(t_arena *arena, char **envp);
char **get_envp_from_hashmap(t_env *env);
int execute_ast(t_env *env, t_ast_node *root);
int djb2_hash(const char *key);
char *find_executable(t_env *env, const char *command);
char *get_env_value(t_env *env, const char *key);
char *get_prompt(t_env *env);

#endif
