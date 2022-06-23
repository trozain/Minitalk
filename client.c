/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:52:10 by trozain           #+#    #+#             */
/*   Updated: 2022/06/22 16:52:10 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static int	g_signal;

void	client(int pid, char const *text)
{
	int		b;
	char	c;

	while (*text)
	{
		b = 8;
		c = *text;
		while (b--)
		{
			if (c >> b & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
		}
		text++;
	}
	b = 8;
	while (b--)
	{
		kill(pid, SIGUSR1);
		pause();
	}
}

void	ft_error(int sig)
{
	static int	count = -7;

	if (sig == SIGUSR1)
		count++;
	else
	{
		ft_putchar_fd('\n', 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char const *argv[])
{
	int	pid;

	g_signal = 1;
	if (argc != 3)
	{
		ft_putstr_fd("client: c'est pas le bon format.\n", 1);
		ft_putstr_fd("format correct: [./client <PID> \"string\"].\n", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_error);
	signal(SIGUSR2, ft_error);
	client(pid, argv[2]);
}
