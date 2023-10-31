/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:32:02 by krodcas           #+#    #+#             */
/*   Updated: 2023/10/31 15:38:34 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	int			signed_nptr;
	int			zero;
	long int	result;

	i = 0;
	signed_nptr = 1;
	result = 0;
	zero = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if ((*nptr == '-' && !ft_isdigit(nptr[1]))
		|| *nptr == '\e' || ft_isalpha((int)*nptr))
		return (result);
	if (nptr[i] == '-')
		signed_nptr = -1;
	while (ft_isdigit(nptr[++i]))
		;
	i--;
	while (i >= 0 && ft_isdigit(nptr[i]))
	{
		result = (result + (((int)nptr[i--]) - 48) * zero);
		zero = (zero * 10);
	}
	return (result * signed_nptr);
}
