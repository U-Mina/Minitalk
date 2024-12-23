/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:05:51 by ewu               #+#    #+#             */
/*   Updated: 2024/11/04 18:21:30 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

/**
 * *infos contain si_pid, si_uid,
 * si_code: give the source of signal ('kill', 'sigqueue' or hardware)
 * *context: info about CPU, program counter, stack info ...
 */
void	s_handler(int sig_num, siginfo_t *infos, void *context)
{
	static int	cur_char = 0;
	static int	count;
	pid_t		pid;

	(void)context;
	pid = infos->si_pid;
	if (sig_num == SIGUSR1)
		cur_char = (cur_char << 1) | 0;
	else if (sig_num == SIGUSR2)
		cur_char = (cur_char << 1) | 1;
	count++;
	if (count == 8)
	{
		write(1, &cur_char, 1);
		cur_char = 0;
		count = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_act;
	pid_t				pid;

	pid = getpid();
	ft_putnbr(pid);
	s_act.sa_sigaction = s_handler;
	s_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&s_act.sa_mask);
	if (sigaction(SIGUSR1, &s_act, NULL) == -1 || sigaction(SIGUSR2, &s_act,
			NULL) == -1)
	{
		write(1, "Sigaction Error!\n", 18);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
