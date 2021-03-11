/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:38:22 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/18 12:49:13 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
