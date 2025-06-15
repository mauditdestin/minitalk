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

char *g_str = NULL;

static void handler(int signum)
{
	
}

void	print_ascii_header(void)
{
	ft_printf(
		"   _____     ______     _____     __      __    ______     _____                    _____      _____     _____  \n"
		"  / ____|   |  ____|   |  __ \\    \\ \\    / /   |  ____|   |  __ \\                  |  __ \\    |_   _|   |  __ \\ \n"
		" | (___     | |__      | |__) |    \\ \\  / /    | |__      | |__) |                 | |__) |     | |     | |  | |\n"
		"  \\___ \\    |  __|     |  _  /      \\ \\/ /     |  __|     |  _  /                  |  ___/      | |     | |  | |\n"
		"  ____) |   | |____    | | \\ \\       \\  /      | |____    | | \\ \\                  | |         _| |_    | |__| |\n"
		" |_____/    |______|   |_|  \\_\\       \\/       |______|   |_|  \\_\\                 |_|        |_____|   |_____/ \n"
		"                                                                                                                \n"
		"                                                                                                                \n"
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
	print_ascii_header();
	ft_printf("🚀 Server PID : %d 🚀\n\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
	return (0);
}