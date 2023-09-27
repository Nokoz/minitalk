/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:56:43 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/27 13:50:23 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	long	nb;
	int		len;
	int		i;

	len = 0;
	while (str && str[len])
		len++;
	i = 0;
	nb = 0;
	while (i < len)
		nb = (nb * 10) + (str[i++] - 48);
	return (nb);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_send_sig(int pid, char c)
{
	int	ascii;
	int	bin[8];
	int	i;

	ascii = (int)c;
	i = 7;
	while (i >= 0)
	{
		bin[i] = (ascii >> i) & 1;
		i--;
	}
	i = 8;
	while (--i >= 0)
	{
		if (bin[i] == 0)
			kill(pid, SIGUSR1);
		else if (bin[i] == 1)
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		write(1, "Arguments error\n", 16);
	else
	{
		pid = ft_atoi(av[1]);
		if (pid < 0 || ft_strlen(av[1]) > 5)
		{
			write(1, "Wrong PID\n", 10);
			exit(1);
		}
		while (*av[2])
			ft_send_sig(pid, *av[2]++);
	}
	return (0);
}
