/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:23:32 by het-tale          #+#    #+#             */
/*   Updated: 2022/04/07 15:41:39 by het-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/******* extract the command from the path
1/extract the paths from PATH variable
2/locate "PATH=" in env  
3/remove "PATH=" (strtrim)
3/split the paths (:)
4/res = add "/" at the end of each path (join)
5/join res w/ cmd and check if it's correct (join + access)
*/

static int	locate(char *str, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(str, envp[i], 5) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*check_command(char *cmd, char *env[])
{
	int		index;
	char	*trim;
	char	**split;
	int		j;
	char	*path;

	j = -1;
	path = NULL;
	index = locate("PATH=", env);
	trim = ft_strtrim(env[index], "PATH=");
	split = ft_split(trim, ':');
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (split[++j])
	{
		split[j] = ft_strjoin(split[j], "/");
		split[j] = ft_strjoin(split[j], cmd);
		if (access(split[j], F_OK) == 0)
			path = split[j];
	}
	if (!path)
	{
		write(2, "command not found\n", 19);
	}
	return (path);
}
