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


// ft_error will output the error msg and then exit the program
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

// ft_atoi will convert each letter of the string to int of bits (ones or zeros) in-order to send it to the server
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

// handler will check for the input error if the pid is valid or not
// it will send the output msg to the ft_error function if order to print it
int handler(int pid, char *str)
{
	if (pid <= 1000 || pid >= 100000)
		ft_error("Invalid PID.\n");
	else if (*str == '\0')
		ft_error("Nothing to send.\n");
	return (1);
}

// sigtokill function will send the bits to the server in-order to output it.
// The kill(pid_t pid, char *sig) function sends a signal to a process or process group specified by pid. The signal to be sent is specified by sig and is either 0 or one of the signals from the list in the <sys/signal.h> header file.
// pid: (Input) The process ID or process group ID to receive the signal.
// sig: (Input) The signal to be sent.
/*
pid_t pid:

Specifies the processes that the caller wants to send the signal to:
If pid is greater than zero, kill() sends the signal sig to the process whose ID is equal to pid.

If pid is equal to zero, kill() sends the signal sig to all processes whose process group ID is equal to that of the sender, except for those to which the sender does not have the appropriate authority to send a signal.

If pid is equal to -1, kill() returns -1 and errno is set to [ESRCH].

If pid is less than -1, kill() sends the signal sig to all processes whose process group ID is equal to the absolute value of pid, except for those to which the sender does not have appropriate authority to send a signal.
*/
/*
int sig:

The signal that should be sent to the processes specified by pid. This must be zero, or one of the signals defined in the <sys/signal.h> header file. If sig is zero, kill() performs error checking, but does not send a signal. You can use a sig value of zero to check whether the pid argument is valid.
*/

// it has two return values either 0: if msg succesfully sent or -1: if msg has failed


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
	int		sig;

	sig = ft_atoi(argv[1]);
	if (argc != 3)
		ft_error("Wrong number of arguments\n");
	else if (handler(sig, argv[2]) == 0)
		return (0);
	sigtokill(sig, argv[2]);
	return (0);
}
