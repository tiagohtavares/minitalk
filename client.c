/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:51 by ttavares          #+#    #+#             */
/*   Updated: 2023/01/11 15:37:17 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void	signals(char *str, int pid)
{
	int	i;
	int j;

	j = 0;
while(str[j] != '\0')
{
	i = 0;
	while (i < 8)
	{
		if (str[j] & 128 >> i)
		{
			kill(pid, SIGUSR2);
			printf("1");
		}
		else
		{
			kill(pid, SIGUSR1);
			printf("0");
		}
		i++;
		usleep(150);
	}
	printf("\n");
	j++;
}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("client: invalid input\n");
		return (0);
	}
	pid = atoi(argv[1]);
	signals(argv[2], pid);
	return (0);
}
