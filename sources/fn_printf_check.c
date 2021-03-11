/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:40:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:05:27 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	fn_check_print(t_parms *prn)
{
	char			*temp;
	int				int_temp;
	long long int	uint_temp;

	temp = NULL;
	int_temp = 0;
	uint_temp = 0;
	if (prn->cf == 's')
		fn_print_chk_s(prn);
	else if (prn->cf == 'i' || prn->cf == 'd' || \
			prn->cf == 'u' || prn->cf == 'U')
		temp = fn_print_chk_iud(prn, temp, int_temp, uint_temp);
	else if (prn->cf == 'x' || prn->cf == 'X' || \
			prn->cf == 'p')
		temp = fn_print_chk_xp(prn, temp, uint_temp);
	else if (prn->cf == 'c' || prn->cf == '%')
		fn_print_chk_c(prn);
	free(temp);
	return (0);
}

void	reset_neg(t_parms *prn)
{
	prn->flag_w *= -1;
	prn->c_align = 1;
	return ;
}

int	fn_read(t_parms *prn, int tmp_prn_cnt)
{
	while ((check_format(prn) == 0))
	{
		tmp_prn_cnt = prn->cnt;
		check_flags1(prn);
		check_flags2(prn);
		if (prn->c_hash == 1)
			check_flags2(prn);
		if ((check_num(&prn->flag_w, prn)) < 0)
			reset_neg(prn);
		if (prn->string[prn->cnt] == '.')
		{
			prn->cnt++;
			prn->c_pre = 1;
			if ((check_num(&prn->flag_p, prn)) < 0)
				prn->c_pre = 0;
		}
		check_parms(prn->lenght_type, &prn->c_lenght, prn);
		if (tmp_prn_cnt == prn->cnt)
			return (0);
	}
	return (1);
}

int	fn_analisys(t_parms *prn)
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
