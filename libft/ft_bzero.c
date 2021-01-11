/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:18:01 by juasanto          #+#    #+#             */
/*   Updated: 2020/08/25 13:23:03 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *bzero_string, unsigned int num_char)
{
	unsigned char *temp_pointer;

	temp_pointer = (unsigned char *)bzero_string;
	while (num_char-- > 0)
		*temp_pointer++ = 0;
	return (bzero_string);
}
