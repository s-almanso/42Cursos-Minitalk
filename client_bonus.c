/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:58 by salmanso          #+#    #+#             */
/*   Updated: 2022/11/09 23:59:47 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	ft_puterror(char *c)
{
	while (*c)
		write(1, c++, 1);
	exit (1);
}

int	ft_handler(int pid, char *str)
{
	if (pid <= 1000 || pid >= 100000)
		ft_puterror("Invalid PID.\n");
	else if (!str)
		ft_puterror("Nothing to send.\n");
	return (1);
}

int	ft_atoi(const char *str)
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
		if (str[i++] == '-')
			sign *= -sign;
	}
	while (str[i] > '0' && str[i] < '9' && str[i])
	{
		num *= 10;
		num = num + (str[i++] - '0');
	}
	if (num > 2147483648 && sign == -1)
		return (0);
	else if (num > 2147483647 && sign == 1)
		return (-1);
	return ((int) num * sign);
}

void	sigtokill(pid_t pid, char *sig)
{
	int	i;

	while (*sig != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((*sig >> i & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_puterror("Invalid PID\n");
			}
			else if ((*sig >> i & 1) == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_puterror("Invalid PID\n");
			}
			usleep(160);
			i--;
		}
		sig++;
	}
}

int	main(int argc, char **argv)
{
	int			pid;
	char		*sig;
	static int	i;

	if (argc != 3)
		ft_puterror("Wrong number of arguments\n");
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] >= 33 && argv[1][i] <= 47) ||
				(argv[1][i] >= 58 && argv[1][i] <= 64)
				|| (argv[1][i] >= 91 && argv[1][i] <= 96)
				|| (argv[1][i] >= 123 && argv[1][i] <= 124))
			ft_puterror("Invalid PID\n");
		i++;
	}
	pid = ft_atoi(argv[1]);
	sig = argv[2];
	if (ft_handler(pid, sig) == 0)
		return (0);
	sigtokill(pid, sig);
	return (0);
}
