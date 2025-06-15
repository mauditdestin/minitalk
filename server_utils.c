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

// Reconstruit un entier bit par bit à 
// chaque signal reçu (SIGUSR1 ou SIGUSR2).
// Une fois les 32 bits reçus, stocke 
// la valeur entière dans *value.
void	get_int(int signum, int *value)
{
	static int	result = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		result += 1 << (31 - i);
	i++;
	if (i == 32)
	{
		*value = result;
		result = 0;
		i = 0;
	}
}