/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:38:22 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/07 13:06:58 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	t_parms		prn;

	fn_inicialize(&prn);
	if (string != 0)
	{
		prn.string = string;
		va_start(prn.args, string);
		prn.prt_chars = fn_analisys(&prn);
		va_end(prn.args);
	}
	return (prn.prt_chars);
}
