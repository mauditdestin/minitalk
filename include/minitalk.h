/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:14:29 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:14:29 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <signal.h>
#include <sys/types.h>
#include "libft.h"
#define SLEEP 200

void	get_int(int signum, int *value);
void	str_alloc(int str_size, int client_pid);