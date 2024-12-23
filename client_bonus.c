/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:05:19 by ewu               #+#    #+#             */
/*   Updated: 2024/11/04 18:29:58 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}

void	ft_response(int sig_num)
{
	if (sig_num == SIGUSR2)
		write(1, "Signal Received!\n", 18);
}

void	ft_bin(pid_t pid, char c)
{
	int	i;
	int	bits;
	int	sig_sent;

	i = 8;
	while (--i >= 0)
	{
		bits = (c >> i) & 1;
		if (bits == 0)
			sig_sent = SIGUSR1;
		else
			sig_sent = SIGUSR2;
		if (kill(pid, sig_sent) == -1)
		{
			write(1, "Failure in sending signal!\n", 28);
			exit(EXIT_FAILURE);
		}
		usleep(400);
	}
}

void	send_str(pid_t pid, char *str)
{
	while (*str)
	{
		ft_bin(pid, *str);
		str++;
	}
	ft_bin(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = ft_response;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "Error!\n", 7);
	if (ac != 3)
	{
		write(1, "Invalid Parameter!\n", 20);
		exit(EXIT_FAILURE);
	}
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "Invalid PID!\n", 14);
		exit(EXIT_FAILURE);
	}
	send_str(pid, av[2]);
	return (0);
}
