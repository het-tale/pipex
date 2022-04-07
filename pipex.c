/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:29:02 by het-tale          #+#    #+#             */
/*   Updated: 2022/04/07 17:12:20 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_error(char *message, int condition)
{
	if (condition < 0)
	{
		perror(message);
		exit(1);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	p;

	if (argc == 5)
	{
		p.out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
		p.pid2 = 0;
		ft_error("out", p.out);
		ft_error("Error", pipe(p.fds));
		p.pid1 = fork();
		if (p.pid1 == 0)
		{
			p.in = open(argv[1], O_RDONLY);
			ft_error("Fd", p.in);
			close(p.fds[0]);
			execute_command(p.in, p.fds[1], argv[2], env);
		}
		if (p.pid1 != 0)
			p.pid2 = fork();
		if (p.pid2 == 0)
		{
			close(p.fds[1]);
			execute_command(p.fds[0], p.out, argv[3], env);
		}
		waitpid(-1, &(p.status), 0);
	}
}
