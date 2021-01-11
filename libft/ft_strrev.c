/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:57:03 by juasanto          #+#    #+#             */
/*   Updated: 2020/12/29 10:59:56 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		cnt;
	int		length;
	char	buff;

	cnt = 0;
	length = ft_strlen(str);
	while (length - 1 > cnt)
	{
		buff = str[cnt];
		str[cnt] = str[length - 1];
		str[length - 1] = buff;
		length--;
		cnt++;
	}
	return (str);
}
