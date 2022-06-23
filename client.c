/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trozain <trozain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:52:10 by trozain           #+#    #+#             */
/*   Updated: 2022/06/23 13:26:08 by trozain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	client(int pid, char const *text)
{
	int		bits;
	char	verif;

	while (*text)
	{
		bits = 8;
		verif = *text;
		while (bits--)
		{
			if (verif >> bits & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
		}
		text++;
	}
	bits = 8;
	while (bits--)
	{
		kill(pid, SIGUSR1);
		pause();
	}
}

void	ft_exit(int sig)
{
	static int	c = -7;

	if (sig == SIGUSR1)
		c++;
	else
	{
		ft_putstr_fd("Message send.🐥\n", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char const *argv[])
{
	int	pid_serv;

	if (argc != 3)
	{
		ft_putstr_fd("error format, this incident will be reported\n", 1);
		exit(EXIT_FAILURE);
	}
	pid_serv = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_exit);
	signal(SIGUSR2, ft_exit);
	client(pid_serv, argv[2]);
}
