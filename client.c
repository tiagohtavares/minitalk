/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:51 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/19 10:33:44 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signals(char *str, int pid)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 0;
		while (i < 8)
		{
			if (str[j] & (128 >> i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			usleep(200);
		}
		j++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid input! Try: \"PID\" \"STRING\" \n");
		return (0);
	}
	pid = atoi(argv[1]);
	signals(argv[2], pid);
	return (0);
}
