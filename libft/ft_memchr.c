/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:52:06 by juasanto          #+#    #+#             */
/*   Updated: 2020/07/13 11:37:23 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t lng)
{
	while (lng-- != 0)
	{
		if (*(unsigned char *)str == (unsigned char)chr)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
