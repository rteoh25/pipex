/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:44:58 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/10 23:44:58 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
pipes!!
used in pipe() in main creates a unidirectional dta channel that connects
the stdout of one process to the stdin of another process
basically like "|" in the terminal
*/

static char	*get_cmd(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*cmd_path)
	{
		tmp = ft_strjoin(*cmd_path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free (command);
		cmd_path++;
	}
	return (NULL);
}

/*
input is <infile> <cmd1> <cmd2> <outfile>
---------------------------------------------------------
cmd_args is for example "ls -l" or "wc -l"
splitting the cmd into the command itself[0] and flag[1]
---------------------------------------------------------
cmd_path is the path to the directory of the environment
cmd is the command that is found
*/

void	first_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
