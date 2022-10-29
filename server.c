/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:56 by salmanso          #+#    #+#             */
/*   Updated: 2022/10/29 15:25:44 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ft_putnbr(int n)
{
	if (n < 10)
	{
		n += 48;
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}



int main()
{
	// The sigaction() system call is used to change the action
	// taken by a process on receipt of a specific signal.
	struct sigaction		sins;

	

	// getppid() : returns the process ID (integer) of
	// the parent of the calling process.
	write(1, "PID is: ", 8);
	ft_putnbr(getpid());







	return (0);
}
