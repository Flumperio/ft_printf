/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:40:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/11 13:02:24 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		temp = fn_print_chk_iud(prn, temp, int_temp, uint_temp);
	else if (prn->current_format == 'x' || prn->current_format == 'X' ||
			prn->current_format == 'p')
		temp = fn_print_chk_xp(prn, temp, int_temp, uint_temp);
	else if (prn->current_format == 'c' || prn->current_format == '%')
		fn_print_chk_c(prn);
	free(temp);
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
