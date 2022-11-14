/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:56 by salmanso          #+#    #+#             */
/*   Updated: 2022/11/09 23:59:43 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		ft_putchar('-');
		i = n * -1;
	}
	if (i / 10 != 0)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}

void	ft_signal(int sig)
{
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
	write(1, "Your PID is: ", 13);
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
