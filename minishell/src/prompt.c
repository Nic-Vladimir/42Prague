/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnicoles <vnicoles@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:30:29 by vnicoles          #+#    #+#             */
/*   Updated: 2025/03/20 04:04:14 by vnicoles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char    *get_prompt(t_env *env)
{
    char        *cwd;
    char        *prefix;
    char        *suffix;
    char        *prompt;
    size_t      prompt_len;
    size_t      offset;

    cwd = get_env_value(env, "PWD");
    if (env->last_exit_code == 0)
        prefix = "╭─✅─\033[38;5;46m";
    else
        prefix = "╭─💀─\033[38;5;46m";
    suffix = "\033[0m\n╰─ ";
    prompt_len =  ft_strlen(prefix) + ft_strlen(cwd) + ft_strlen(suffix) + 1;
    prompt = (char *)arena_malloc(env->arena, prompt_len);
    if (!prompt)
        return (ft_strdup("minishell> "));
    offset = 0;
    offset += ft_strlcpy(prompt + offset, prefix, prompt_len - offset);
    offset += ft_strlcpy(prompt + offset, cwd, prompt_len - offset);
    offset += ft_strlcpy(prompt + offset, suffix, prompt_len - offset);
    return (prompt);
}
