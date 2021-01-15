/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:02:42 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/15 11:34:46 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_clean(char *s1, char *s2, int clean)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strjoin(s1, s2);
	if (clean == 1)
		free(s1);
	else if (clean == 2)
		free(s2);
	if (clean == 3)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}
