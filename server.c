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

char *str = NULL;

static void handler(int signum)
{
	
}

int	main(int argc, char **argv)
{
	int	pid;
	
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Correct syntax : ./server\n");
	}
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGURS2, handler);
	while (42)
		pause();
	return (0);
}