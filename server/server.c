/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:22:45 by pleblond          #+#    #+#             */
/*   Updated: 2024/12/09 22:22:45 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <cstddef>

int	main(void)
{
	struct sigaction	act;
	char				*message;

	act.sa_signification = input;
	act.sa_flags = SA_SIGINFO;
	sigaction(30, &act, NULL);
	sigaction(31, &act, NULL);
	ft_printf("The PID is : %d\n", getpid());
	while (1)
	{
		message = get_next_line(1);
		if (!ft_strncmp(message, "exit", 4) && ft_strlen(message) == 5)
			break ;
		free(message);
	}
	free(message);
	return (0);
}

