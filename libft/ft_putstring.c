/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:16:25 by juasanto          #+#    #+#             */
/*   Updated: 2020/07/01 12:34:24 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstring(char *putstring)
{
	int countprint;

	countprint = 0;
	while (putstring[countprint] != 0)
		ft_putchar(putstring[countprint++]);
}
