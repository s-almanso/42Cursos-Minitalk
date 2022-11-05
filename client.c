/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:58 by salmanso          #+#    #+#             */
/*   Updated: 2022/11/05 23:46:56 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void ft_error(char *error)
{
	int	i;

	i = 0;
	while (error[i] != '\0')
	{
		write(1, &error[i], 1);
		i++;
	}
	exit(1);
}

int ft_atoi(const char *str)
{
	unsigned int	num;
	int				sign;
	int				i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		num = num * 10;
		num = num + (str[i++] - '0');
	}
	if (num > 2147483648 && sign == -1)
		return (0);
	else if (num > 2147483647 && sign == 1)
		return (-1);
	return ((int) num * sign);
}

int handler(int pid, char *str)
{
	if (pid <= 1000 || pid >= 100000)
		ft_error("Invalid PID.\n");
	else if (*str == '\0')
		ft_error("Nothing to send.\n");
	return (1);
}

void	sigtokill(pid_t pid, char *str)
{
	int	i;

	while (*str != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error("Invalid PID\n");
			}
			else if ((*str >> i & 1) == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error("Invalid PID\n");
			}
			usleep(80);
			i--;
		}
		str++;
	}
}

// prints possible errors
// takes the first argument and converts it to the server PID
// coverts the string to binary
// sends the binary chars to the server
int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
		ft_error("Wrong number of arguments\n");
	else if (handler(ft_atoi(argv[1]), argv[2]) == 0)
		return (0);
	sigtokill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
