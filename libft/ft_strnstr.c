/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:59:03 by jcsantos          #+#    #+#             */
/*   Updated: 2020/08/06 11:35:01 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	int size_str2;

	if (*str2 == '\0')
		return ((char *)str1);
	size_str2 = ft_strlen((char *)str2);
	while (*str1 && size_str2 <= (int)len--)
	{
		if (ft_strncmp(str1, str2, size_str2) == 0)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
