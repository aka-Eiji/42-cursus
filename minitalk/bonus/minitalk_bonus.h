/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosiara <jkosiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:10:18 by jkosiara          #+#    #+#             */
/*   Updated: 2021/06/16 17:23:04 by jkosiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
#define MINITALK_BONUS_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/* utils function */

char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char *c, int fd, int byte);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_string_complement(char *string);
char	*ft_eightbit_pluse(char cara);
char    *ft_eightbit(char character);
int     ft_count_bytes(char s);

#endif