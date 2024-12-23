/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:43:58 by ewu               #+#    #+#             */
/*   Updated: 2024/11/04 18:29:09 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int		ft_atoi(const char *str);
void	ft_bin(pid_t pid, char c);
void	ft_putnbr(int n);
void	s_handler(int sig_num, siginfo_t *infos, void *context);
void	send_str(pid_t pid, char *str);

#endif