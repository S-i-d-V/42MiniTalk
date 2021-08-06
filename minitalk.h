/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:59:17 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 22:25:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_client
{
	pid_t	pid;
	int		len;
	char	**binary_msg;
}				t_client;

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);

void	client_exit(t_client *client, int err);
void	server_exit(int err);

#endif