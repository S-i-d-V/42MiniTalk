/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:43:21 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 22:25:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_exit(t_client *client, int err)
{
	int	i;

	i = 0;
	while (i < client->len + 1)
	{
		if (client->binary_msg[i] != NULL)
		{
			free(client->binary_msg[i]);
			client->binary_msg[i] = NULL;
		}
		i++;
	}
	if (client->binary_msg)
		free(client->binary_msg);
	if (err == -1)
		printf("[ERREUR] Impossible d'envoyer le signal.\n");
	exit(0);
}

void	server_exit(int err)
{
	if (err == -1)
		printf("[ERREUR] Impossible de recevoir le signal.\n");
	else if (err == -2)
		printf("[ERREUR] Type de signal errone.\n");
	exit(0);
}
