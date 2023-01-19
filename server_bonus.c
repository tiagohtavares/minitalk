/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:47:26 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/19 12:17:51 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	one(int signal, siginfo_t *info, void *s)
{
	static char	c = 0xFF;
	static int	total = 0;

	(void)s;
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
			kill(info->si_pid, SIGUSR1);
		}
		total = 0;
		c = 0xFF;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error, too many arguments! Quitting... \n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = one;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
