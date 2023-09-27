/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:28:10 by gvardaki          #+#    #+#             */
/*   Updated: 2023/09/27 16:37:32 by gvardaki         ###   ########.fr       */
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

void	signal_handler(int num, siginfo_t *info, void *context)
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
		if (bin == '\0')
			kill(info->si_pid, SIGUSR2);
		i = 0;
		bin = 0;
	}
//	printf("Signal %d reçu de PID %d\n", num, info->si_pid);
}

int	main(void)
{
	struct sigaction sa;

    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
