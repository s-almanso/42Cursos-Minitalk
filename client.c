/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:58 by salmanso          #+#    #+#             */
/*   Updated: 2022/10/29 15:23:22 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid_handler(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i] >= '0' && str[j] <= '9')
		j = j * 10 + (str[i++] - 48);
	return (j);
}

void inf_loop(int sig)
{
	(void) sig;
	write(1, "Messege Recieved.\n", 18);
}

int main(int argc, char **argv)
{
	int		pid;
	int		i;
	struct sigaction	sa_loops;

	sa_loops.sa_handler = inf_loop;
	sa_loops.sa_flags = SA_SIGINFO;
	i = 0;
	sigaction(SIGUSR1, &sa_loops, 0);
	pid = pid_handler(argv[1]);

	return (0);
}
