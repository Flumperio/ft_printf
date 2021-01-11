/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:09:47 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/11 16:40:33 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fn_print_chk_s(t_parms *prn)
{
	if (prn->flag_precision == 0 && prn->current_pre > 0 &&
		prn->flag_width <= 0)
	{
		prn->args_temp = "";
		return ;
	}
	prn->args_temp = va_arg(prn->args, char *);
	if (!prn->args_temp)
		prn->args_temp = "(null)";
	prn->args_len = ft_strlen(prn->args_temp);
	fn_print_s(prn);
	return ;
}

void	fn_print_chk_c(t_parms *prn)
{
	if (prn->current_format == 'c')
		prn->args_char_temp = va_arg(prn->args, int);
	prn->args_len = 1;
	fn_print_c(prn);
}

char	*fn_print_chk_iud(t_parms *prn, char *temp, int int_temp,
							long long int uint_temp)
{
	if (prn->current_format == 'u' || prn->current_format == 'U')
	{
		uint_temp = va_arg(prn->args, unsigned int);
		if (uint_temp < 0)
		{
			uint_temp *= -1;
			prn->flag_sign = 1;
		}
		temp = ft_itoa_u(uint_temp);
	}
	else
	{
		int_temp = va_arg(prn->args, int);
		if (int_temp < 0)
		{
			int_temp *= -1;
			prn->flag_sign = 1;
		}
		temp = ft_itoa_u(int_temp);
	}
	prn->args_temp = temp;
	prn->args_len = ft_strlen(prn->args_temp);
	fn_printi_d(prn);
	return (temp);
}

char	*fn_print_chk_xp(t_parms *prn, char *temp, long long int uint_temp)
{
	if (prn->current_format == 'p')
		uint_temp = va_arg(prn->args, unsigned long int);
	else
	{
		uint_temp = va_arg(prn->args, unsigned int);
	}
	if (prn->current_format == 'x' || prn->current_format == 'p')
		temp = fn_dectohex(uint_temp, 0, 0);
	else
		temp = fn_dectohex(uint_temp, 1, 0);
	prn->args_temp = temp;
	prn->args_len = ft_strlen(prn->args_temp);
	fn_printi_d(prn);
	return (temp);
}
