/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:40:52 by het-tale          #+#    #+#             */
/*   Updated: 2022/04/07 17:12:29 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(int in, int out, char *argv, char **env)
{
	char	*cmd;
	char	**exec;

	dup2(in, 0);
	dup2(out, 1);
	exec = ft_split(argv, ' ');
	cmd = check_command(exec[0], env);
	if (!cmd)
		exit(1);
	execve(cmd, exec, env);
	close(out);
}
