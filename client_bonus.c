/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:51 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/19 14:35:51 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	response(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Recieved! \n");
}

void	signals(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (128 >> i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(200);
	}
	i = 0;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Invalid input! Try: \"PID\" \"STRING\" \n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		signal(SIGUSR1, response);
		signal(SIGUSR2, response);
		signals(argv[2][i], pid);
		i++;
	}
	signals(argv[2][i], pid);
	return (0);
}
