/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bnx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:05:31 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/26 18:20:04 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BNX_H
# define PIPEX_BNX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define ERR_INPUT "BAD INPUT\n"
# define ERR_HERE_DOC "HERE_DOC_ERROR"
# define ERR_INFILE "INFILE ERROR"
# define ERR_OUTFILE "OUTFILE ERROR"

typedef struct s_ppbnx
{
	int	here_doc;
	int	infile;
	int	outfile;
	int	cmd_nb;
	int	pipe_nb;
	char	*env_paths;
	char	**cmd_paths;

}	t_ppbnx;

int		arg_check(char *av, t_ppbnx *pipex);

void	get_infile(char **av, t_ppbnx *pipex);
void	get_outfile(char *av, t_ppbnx *pipex);

void	error_msg(char *err);
int		msg(char *err);



#endif