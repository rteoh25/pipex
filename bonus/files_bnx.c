/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bnx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:40:06 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/26 17:27:27 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bnx.h"

void	get_infile(char **av, t_ppbnx *pipex)
{
	if (pipex->here_doc == 1)
		printf("here_doc");
		// here_doc(av[2], pipex);
	else
	{
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile < 0) 
			error_msg(ERR_INFILE);
	}
}

void	get_outfile(char *av, t_ppbnx *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(av, O_WRONLY | O_APPEND | O_CREAT, 000664);
	else
		pipex->outfile = open(av, O_RDWR | O_TRUNC | O_CREAT, 000664);
	if (pipex->outfile < 0)
		error_msg(ERR_OUTFILE);
}