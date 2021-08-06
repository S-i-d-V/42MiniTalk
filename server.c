/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:59:22 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 22:25:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bits_to_char(int sigusr)
{
	static char	c = 0;
	static int	i = 8;

	if (sigusr == SIGUSR1)
		c |= (0 << --i);
	else if (sigusr == SIGUSR2)
		c |= (1 << --i);
	if (i == 0)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		i = 8;
		c = 0;
	}
}

void	handler_sigusr(int sigusr)
{
	if (sigusr == SIGUSR1 || sigusr == SIGUSR2)
		bits_to_char(sigusr);
	else
		server_exit(-2);
}

int	main(void)
{
	printf("Le PID du serveur est '%d'.\n", getpid());
	if (signal(SIGUSR1, handler_sigusr) == SIG_ERR)
		server_exit(-1);
	if (signal(SIGUSR2, handler_sigusr) == SIG_ERR)
		server_exit(-1);
	while (1)
		pause();
}
