/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:57:18 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/27 13:47:44 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_putnbr(long nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

void	handler(int num)
{
	static int	i;
	static int	bin = 0;

	if (num == 30)
		bin = (bin << 1) + 0;
	else
		bin = (bin << 1) + 1;
	i++;
	if (i == 8)
	{
		write(1, &bin, 1);
		i = 0;
		bin = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
