/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bnx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:25:38 by rteoh             #+#    #+#             */
/*   Updated: 2024/06/25 17:44:02 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bnx.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	error_msg(char *err)
{
	perror(err);
	exit(1);
}
