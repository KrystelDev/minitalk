/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:29:43 by kryrodri          #+#    #+#             */
/*   Updated: 2023/05/15 12:12:59 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// #include "ft_isalpha.c"
// #include "ft_isdigit.c"
// int	ft_isalnum(int c )
// {
// 	if ((c < '0' || c > '9') && ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')))
// 		return (0);
// 	return (1);
// }
// #include <stdio.h>
// int main(void)
// {
// 	printf("a: %d", ft_isalnum('a'));
// 	return (0);
// }