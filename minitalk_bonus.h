/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:13 by ewu               #+#    #+#             */
/*   Updated: 2024/11/04 18:29:04 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bin(pid_t pid, char c);
void	ft_putnbr(int n);
void	ft_response(int sig_num);
void	s_handler(int sig_num, siginfo_t *infos, void *context);
void	send_str(pid_t pid, char *str);

#endif