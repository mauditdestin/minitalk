/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:22:09 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 19:22:09 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

extern char *g_str;

// Alloue dynamiquement la mémoire nécessaire 
// pour stocker le message du client.
// Si l'allocation échoue, envoie une erreur 
// au client et quitte le programme.
void	str_alloc(int str_size, int client_pid)
{
	if (g_str == NULL && str_size > 0)
	{
		g_str = malloc(str_size * sizeof(char));
		if (!g_str)
		{
			kill(client_pid, SIGUSR1);
			free(g_str);
			exit(0);
		}
	}
}