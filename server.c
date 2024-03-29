/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:47 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/19 12:40:14 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	one(int signal)
{
	static char	c = 0xFF;
	static int	total = 0;

	if (signal == SIGUSR1)
		c ^= 128 >> total;
	else if (signal == SIGUSR2)
		c |= 128 >> total;
	total++;
	if (total == 8)
	{
		if (c != 0)
			write(1, &c, 1);
		else
		{
			write(1, "\n", 1);
		}
		total = 0;
		c = 0xFF;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error, too many arguments! Quitting... \n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, one);
	signal(SIGUSR2, one);
	while (1)
		pause();
	return (0);
}
