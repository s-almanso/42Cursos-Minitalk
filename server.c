/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:56 by salmanso          #+#    #+#             */
/*   Updated: 2022/11/08 20:59:41 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>


void	ft_signal(int sig)
{
	// static char/int by default is a zero
	static char	bits;
	static int	bitcount;

	bitcount++;
	bits <<= 1;

	if (sig == SIGUSR2)
		bits |= 1;
	if (bitcount == 8)
	{
		ft_putchar(bits);
		bitcount = 0;
		bits = 0;
	}
}


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	// getppid() : returns the process ID (integer) of the parent of the calling process.
	write(1, "\nThe PID is: ", 14);
	ft_putnbr(pid);
	ft_putchar('\n');

	while (1)
		{
			signal(SIGUSR1, ft_signal);
			signal(SIGUSR2, ft_signal);
			pause();
		}
	return (0);
}
