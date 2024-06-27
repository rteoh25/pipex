/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:05:07 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/26 19:59:06 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bnx.h"

/*
we want to open a tmp_file
we want to print here_doc>
we want to take that as an input
read that and check if the input is the code_wd
and continue or stop reading
then we set the fd of that tmp to the .infile
error handling for file error is unlink()
*/


void	here_doc(char *code_wd, t_ppbnx *pipex)
{
	int		file;
	char	*buff;

	file = open(".tmp_here_doc", O_CREAT | O_TRUNC | O_WRONLY, 00064);
	if (file < 0)
		error_msg(ERR_HERE_DOC);
	ft_putstr_fd("here_doc>", 1);
	buff = get_next_line(0);
	while (ft_strncmp(buff, code_wd, ft_strlen(code_wd)));
	{
		write("here_doc>   ")

	}


}