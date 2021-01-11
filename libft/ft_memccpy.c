/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:39:39 by juasanto          #+#    #+#             */
/*   Updated: 2020/07/13 12:58:09 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str_dst, const void *str_src, int ser_c, size_t leng)
{
	while (leng--)
	{
		*(unsigned char *)str_dst++ = *(unsigned char *)str_src;
		if (*(unsigned char *)str_src++ == (unsigned char)ser_c)
			return (str_dst);
	}
	return (NULL);
}
