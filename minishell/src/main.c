/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:44:35 by vnicoles          #+#    #+#             */
/*   Updated: 2025/03/20 03:43:39 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/tokenizer.h"
#include "../inc/ast.h"
#include <readline/history.h>

/*
static void print_tokens(t_tokenizer_data *tok_data) {
	t_tokenizer_data	*tok_ptr;

	tok_ptr = tok_data;
	while (tok_ptr->tokens) {
		printf("Tokens: [%s] (Type: %d)\n", tok_ptr->tokens->value, tok_ptr->tokens->type);
		tok_ptr->tokens = tok_ptr->tokens->next;
	}
}
*/

int	main(int argc, char **argv, char **envp) {
	char                *input;
    t_arena             *arena;
	t_ast_node          *root;
	int                 status;
	t_env               *env;
    char                *prompt;

	(void)argc;
	(void)argv;
	arena = arena_init(1024 * 1024);
	//env_list = create_env_list();
	env = init_env(arena, envp);
	while (1) {
        prompt = get_prompt(env);
		input = readline(prompt);
		if (!input)
			continue;
		if (strcmp(input, "exit") == 0) {
            free(input);
			break;
        }
		if (*input)
			add_history(input);

		env->tokenizer->tokens = tokenize(env->tokenizer, input);
		root = parse(env->tokenizer);
		//debug_ast(root);
		//print_tokens(env->tokenizer);
		status = execute_ast(env, root);
        env->last_exit_code = status;
		printf("Command return value: %d\n", status);
		free(input);
	}
    rl_clear_history();
    rl_cleanup_after_signal();
	arena_free(arena);
	return 0;
}
