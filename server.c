/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:47 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/11 15:57:47 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdio.h>

void	one(int signal)
{
	int total;

	total = 0;
	if (signal == SIGUSR1)
		write (1,"0",1);
	else
		write (1,"1",1);
	total++;

}
int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, one);
	signal(SIGUSR2, one);
	while (1)
		pause();
	return (0);
}
