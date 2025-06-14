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



int main (int argc, char **argv)
{

	return (0);
}