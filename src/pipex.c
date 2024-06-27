/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:33:51 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/07 16:33:51 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

static char	*find_paths(char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	return (*envp + 5);
}

/*
to learn parent process and child process
child processes inherit the environment varaibles and fds and PATH as the parent
cmd_path is the paths to the command
PATH=/Users/rteoh/goinfre/homebrew/bin:
/Users/rteoh/miniconda3/bin:/usr/local/bin:
/usr/bin:/bin:/usr/sbin:
/sbin:/usr/local/munki:/Library/Apple/usr/bin
*/
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (msg(ERR_INPUT));
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		error_msg(ERR_INFILE);
	pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		error_msg(ERR_OUTFILE);
	if (pipe(pipex.pipe) < 0)
		error_msg(ERR_TUBE);
	pipex.paths = find_paths(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
