/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:40:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/08 13:32:30 by jcsantos         ###   ########.fr       */
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

int		fn_check_print(t_parms *prn)
{
	char			*temp;
	int				int_temp;
	long long int	uint_temp;

	temp = NULL;
	int_temp = 0;
	uint_temp = 0;
	if (prn->current_format == 's')
		fn_print_chk_s(prn);
	else if (prn->current_format == 'i' || prn->current_format == 'd' ||
		prn->current_format == 'u' || prn->current_format == 'U')
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
		free(temp);
	}
	else if (prn->current_format == 'x' || prn->current_format == 'X' ||
				prn->current_format == 'p')
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
		free(temp);
	}
	else if (prn->current_format == 'c' || prn->current_format == '%')
	{
		if (prn->current_format == 'c')
			prn->args_char_temp = va_arg(prn->args, int);
		prn->args_len = 1;
		fn_print_c(prn);
	}
	return (0);
}

int		fn_read(t_parms *prn, int tmp_prn_cnt)
{
	while ((check_format(prn) == 0))
	{
		tmp_prn_cnt = prn->cnt;
		check_flags1(prn);
		check_flags2(prn);
		if ((check_num(&prn->flag_width, prn)) < 0)
		{
			prn->flag_width *= -1;
			prn->current_align = 1;
		}
		if (prn->string[prn->cnt] == '.')
		{
			prn->cnt++;
			prn->current_pre = 1;
			if ((check_num(&prn->flag_precision, prn)) < 0)
			{
				prn->current_align = 1;
				prn->current_pre = 0;
			}
		}
		check_parms(prn->lenght_type, &prn->current_lenght, prn);
		if (tmp_prn_cnt == prn->cnt)
			return (0);
	}
	return (1);
}

int		fn_analisys(t_parms *prn)
{
	while (prn->string[prn->cnt] != '\0')
	{
		if (prn->string[prn->cnt] == '%')
		{
			prn->cnt++;
			if (fn_read(prn, 0) < 1)
			{
				prn->prt_chars = 0;
				break ;
			}
			fn_check_print(prn);
		}
		else
		{
			fn_write(&prn->string[prn->cnt], 1, prn);
			prn->cnt++;
		}
	}
	return (prn->prt_chars);
}
