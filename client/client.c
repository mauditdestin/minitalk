/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:25:32 by pleblond          #+#    #+#             */
/*   Updated: 2024/12/09 22:25:32 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Not enough arguments. Or maybe too much arguments, I don't know. ehe\n");
		return (1);
	}
	else if (ft_atoi(argv[1]) < 1)
	{
		ft_printf("Invalid PID.\n");
		return (1);
	}
	ft_printf("Sent	: \n");
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_printf("Received : ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}