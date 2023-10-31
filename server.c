/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:59:36 by kryrodri          #+#    #+#             */
/*   Updated: 2023/10/31 15:09:51 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	ft_print_mess(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_printf("\n");
	signal(SIGUSR1, &ft_print_mess);
	signal(SIGUSR2, &ft_print_mess);
	while (1)
		;
	return (0);
}
