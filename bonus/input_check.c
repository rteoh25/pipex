/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:16:53 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/26 16:32:42 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bnx.h"

int	arg_check(char *av, t_ppbnx *pipex)
{
	if (av && !ft_strncmp("here_doc", av, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}