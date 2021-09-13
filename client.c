/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:59:19 by user42            #+#    #+#             */
/*   Updated: 2021/09/13 22:54:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*char_to_binary(int c)
{
	int		tab[8];
	char	*binary;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (c != 0)
	{
		while (i < 8)
		{
			tab[i] = 0;
			if (c > 0)
				tab[i] = get_binary(&c);
			i++;
		}
		binary = malloc(sizeof(char) * 8 + 1);
		while (i-- > 0)
			binary[j++] = tab[i] + 48;
		binary[j] = '\0';
	}
	else
		binary = ft_strdup("00000000");
	return (binary);
}

void	msg_to_binary(t_client *client, char *msg)
{
	int	i;

	i = 0;
	client->binary_msg = malloc(sizeof(char *) * (client->len + 2));
	while (i < client->len + 2)
	{
		client->binary_msg[i] = NULL;
		i++;
	}
	i = 0;
	while (msg[i] != '\0')
	{
		client->binary_msg[i] = char_to_binary((int)msg[i]);
		i++;
	}
	client->binary_msg[i] = char_to_binary(0);
	client->binary_msg[i + 1] = NULL;
}

void	send_signals(t_client *client, int i, int j)
{
	usleep(50);
	if (client->binary_msg[i][j] == '0')
	{
		if (kill(client->pid, SIGUSR1) == -1)
			client_exit(client, -1);
	}
	else if (client->binary_msg[i][j] == '1')
	{
		if (kill(client->pid, SIGUSR2) == -1)
			client_exit(client, -1);
	}
}

void	send_msg(t_client *client, char *msg)
{
	int	i;
	int	j;

	i = 0;
	msg_to_binary(client, msg);
	while (client->binary_msg[i])
	{
		j = 0;
		usleep(75);
		while (j < 8)
		{
			send_signals(client, i, j);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_client	client;

	if (ac == 3)
	{
		client.pid = ft_atoi(av[1]);
		client.len = ft_strlen(av[2]);
		send_msg(&client, av[2]);
		client_exit(&client, 0);
	}
	else
		printf("[ERREUR] parametres incorrectes. (./client PID \"message\")\n");
}
