/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bnx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:06:24 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/26 18:02:03 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bnx.h"

static char	*find_paths(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}

int	main(int ac, char *av[], char *envp[])
{
	t_ppbnx pipex;

	if (ac < arg_check(av[1], &pipex))
		return (msg(ERR_INPUT));
	get_infile(av, &pipex);
	get_outfile(av[ac - 1], &pipex);
	pipex.cmd_nb = ac - 3 - pipex.here_doc;
	pipex.pipe_nb = 2 * (pipex.cmd_nb - 1);
	pipex.env_paths = find_paths(envp);
	pipex.cmd_paths = ft_split(pipex.env_paths, ':');
	return (0);
}