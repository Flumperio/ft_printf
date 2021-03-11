/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:09:47 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:06:25 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fn_print_chk_s(t_parms *prn)
{
	if (prn->flag_p == 0 && prn->c_pre > 0 && \
		prn->flag_w <= 0)
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
	if (prn->cf == 'c')
		prn->a_c_t = va_arg(prn->args, int);
	prn->args_len = 1;
	fn_print_c(prn);
}

char	*fn_print_chk_iud(t_parms *prn, char *temp, int int_temp,
							long long int uint_temp)
{
	if (prn->cf == 'u' || prn->cf == 'U')
	{
		uint_temp = va_arg(prn->args, unsigned int);
		if (uint_temp < 0)
		{
			uint_temp *= -1;
			prn->flag_s = 1;
		}
		temp = ft_itoa_u(uint_temp);
	}
	else
	{
		int_temp = va_arg(prn->args, int);
		if (int_temp < 0)
		{
			int_temp *= -1;
			prn->flag_s = 1;
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
	if (prn->cf == 'p')
		uint_temp = va_arg(prn->args, unsigned long int);
	else
	{
		uint_temp = va_arg(prn->args, unsigned int);
	}
	if (prn->cf == 'x' || prn->cf == 'p')
		temp = fn_dectohex(uint_temp, 0, 0);
	else
		temp = fn_dectohex(uint_temp, 1, 0);
	prn->args_temp = temp;
	prn->args_len = ft_strlen(prn->args_temp);
	fn_printi_d(prn);
	return (temp);
}
