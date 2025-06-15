/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:12:05 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:12:05 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

char	*g_str = NULL;

// Gère la reconstruction d'un message envoyé 
// bit par bit via des signaux.
// Récupère d'abord le PID du client, 
// puis la taille du message, puis le contenu caractère par caractère.
static void	handler(int signum)
{
	static int	i = 0;
	static int	client_pid = 0;
	static int	str_size = 0;
	static int	count = 0;
	static int	c = 0;

	if (count == 0 && i == 0)
		g_str = NULL;
	if (client_pid == 0)
		get_int(signum, &client_pid);
	else if (str_size == 0)
		get_int(signum, &str_size);
	else
	{
		str_alloc(str_size, client_pid);
		if (signum == SIGUSR2)
			c += 1 << (7 - i);
		next_byte(&i, &count, &c);
		str_reset(&count, &i, &client_pid, &str_size);
	}
}

void	print_ascii_pid(void)
{
	ft_printf(
		" __________  .___  ________   \n"
		" \\______   \\ |   | \\______ \\  \n"
		"  |     ___/ |   |  |    |  \\ \n"
		"  |    |     |   |  |    `   \\\n"
		"  |____|     |___| /_______  /\n"
		"                           \\/ \n\n"
		);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Correct syntax : ./server\n");
		return (0);
	}
	pid = getpid();
	print_ascii_pid();
	ft_printf("🚀 PID : %d 🚀\n\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
	return (0);
}
