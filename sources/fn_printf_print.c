/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:09:47 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/07 12:49:45 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_char(t_parms *prn)
{
	int cnt;

	cnt = prn->current_size;
	while (cnt >= 1)
	{
		fn_write(&prn->fill_char, 1, prn);
		cnt--;
	}
	return ;
}
