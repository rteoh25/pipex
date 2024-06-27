/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:33:44 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/07 16:33:44 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>

# define ERR_INPUT "BAD ARGUMENTS\n<filein> <cmd1> | <cmd2> <fileout>"
# define ERR_INFILE "infile doesnt exist or cant be read\n"
# define ERR_OUTFILE "Outfile cannot be created, error\n"
# define ERR_TUBE "Tube error\n"
# define ERR_CMD "Cmd error\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	first_child(t_pipex pipex, char **av, char **envp);
void	second_child(t_pipex pipex, char **av, char **envp);
void	free_child(t_pipex *pipex);
void	free_parent(t_pipex *pipex);
int		msg(char *err);
void	error_msg(char *err);

#endif
