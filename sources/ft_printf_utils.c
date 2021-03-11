/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:24:46 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:08:30 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	fn_write(const char *str, int len, t_parms *prn)
{
	if (str == NULL || len < 1)
		return (1);
	write(1, str, len);
	prn->prt_chars += len;
	return (0);
}

static int	ft_nblen_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*dest;
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;

	nb = (n < 0 ? -n : n);
	len = ft_nblen_u(nb);
	i = 0;
	if (!(dest = (ft_calloc(sizeof(char), len + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	if (n < 0)
	{
		dest[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	dest[i] = nb % 10 + 48;
	dest[len] = '\0';
	return (dest);
}

char	*fn_dectohex(long long int n, int capital, int j)
{
	char				*converted;
	unsigned long int	quotient;
	unsigned long int	rest;
	int					add;

	if (!(converted = (ft_calloc(sizeof(char), 64))))
		return (NULL);
	add = (capital == 1 ? 55 : 87);
	if (n == 0)
		converted[0] = 48;
	else
	{
		quotient = n;
		while (quotient != 0)
		{
			rest = quotient % 16;
			if (rest < 10)
				converted[j++] = 48 + rest;
			else
				converted[j++] = add + rest;
			quotient = quotient / 16;
		}
	}
	return (ft_strrev(converted));
}
