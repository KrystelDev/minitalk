/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:14:43 by kryrodri          #+#    #+#             */
/*   Updated: 2023/10/31 15:22:02 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

static void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Invalid number of params");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Incorrect PID");
			exit(EXIT_FAILURE);
		}
	}
	if (ft_atoi(argv[1]) == 0)
	{
		ft_printf("Incorrect PID");
		exit(EXIT_FAILURE);
	}
}

void	signal_error(void)
{
	ft_printf("Error de client.c\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		bit;

	check_args(argc, argv);
	while (*argv[2])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((*argv[2] & (1 << bit)) == 0)
			{
				if (kill(ft_atoi(argv[1]), SIGUSR2) == -1)
					signal_error();
			}
			else
			{
				if (kill(ft_atoi(argv[1]), SIGUSR1) == -1)
					signal_error();
			}
			usleep(100);
			bit++;
		}
		argv[2]++;
	}
	return (0);
}
