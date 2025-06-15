/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:12:12 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:12:12 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]))
					return (0);
			i++;
		}
		i = 0;
		while (argv[2][i])
				i++;
		return (i + 1);
	}
	return (0);
}

static void send_int(unsigned int size, pid_t pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if ((size >> 1) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(SLEEP);
	}
}

static void	send_str(const char *str, pid_t pid)
{
	int	i;

	i = 42;
	while (*(str - 1) || i == 42)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(SLEEP);
		}
		str++;
	}
	return (0);
}

static void	client_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("----> Successfully wrote on the server!\n");
	else if (signum == SIGUSR2)
		ft_printf("----> Error : Server closed.\n");
	exit(0);
}

int main (int argc, char **argv)
{
	unsigned int	size;
	pid_t		pid;

	size = check_args(argc, argv);
	if (size)
	{
		pid = ft_atoi(argv[1]);
		send_int(getpid(), pid);
		sent_int(size, pid);
		send_str(argv[2], pid);
		signal(SIGUSR1);
		signal(SIGUSR2);
		ft_printf("\n[BONUS] Waiting for server response...\n");
		while (42)
			pause();
	}
	else
		ft_printf("Correct syntax: ./client <SERVER_PID> <TEXT>\n");
	return (0);
}