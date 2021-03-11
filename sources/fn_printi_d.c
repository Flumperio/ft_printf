/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printi_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:39:54 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:08:01 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	init_zero(t_parms *prn)
{
	prn->ps[0] = 0;
	prn->cs += 1;
	prn->c_hash = 0;
}

void	fill_space_zero(t_parms *prn)
{
	int		tmp_len;

	tmp_len = ft_strlen(prn->ps);
	if (prn->c_sign == 1 || prn->flag_s == 1)
		tmp_len += 1;
	if (prn->c_zero == 0 || (prn->c_zero == 1 && prn->flag_p >= 0 && \
			prn->c_pre == 1) || prn->c_align == 1)
	{
		fill_sign(prn);
		if (prn->c_hash == 1 && (prn->ps[1] != 'x' && prn->ps[1] != 'X') && \
			*prn->args_temp != '0')
		{
			fill_0x(prn);
			tmp_len += 2;
		}
		fill_str(prn->flag_w - tmp_len, prn->c_align, " ", prn);
	}
	else
	{
		fill_str(prn->flag_w - tmp_len, prn->c_align, "0", prn);
		fill_sign(prn);
		if (prn->c_hash == 1 && *prn->args_temp != '0')
			prn->ps[1] = (prn->cf == 'x' ? 'x' : 'X');
	}
}

void		fn_sign_str(t_parms *prn)
{
	int		tmp_len;

	tmp_len = 0;
	fill_str((prn->flag_p - prn->args_len), 0, "0", prn);
	if ((prn->cf == 'p' && (prn->ps[1] != 'x' && prn->ps[1] != 'X')) || \
			((prn->cf == 'x' || prn->cf == 'X') && *prn->args_temp != '0' && \
			(prn->c_hash == 1 && prn->cs == 1)))
		fill_0x(prn);
	fill_space_zero(prn);
}

void	fn_printi_d(t_parms *prn)
{
	char	*temp;
	int		tmp_len;

	temp = ft_strdup(prn->args_temp);
	prn->ps = temp;
	prn->cs = ((prn->flag_w > prn->flag_p ? \
				prn->flag_w : prn->flag_p) - prn->args_len);
	if (prn->c_pre == 1 && prn->flag_p <= 0 && \
			prn->ps[0] == '0')
		init_zero(prn);
	if (prn->cf == 'p' && prn->flag_p <= prn->args_len)
		fill_0x(prn);
	if ((prn->cf == 'x' || prn->cf == 'X') && *prn->args_temp != '0' && \
		prn->c_hash == 1 && prn->cs <= 0)
		fill_0x(prn);
	if (prn->cs >= 1)
		fn_sign_str(prn);
	else
		fill_sign(prn);
	tmp_len = ft_strlen(prn->ps);
	fn_write(prn->ps, tmp_len, prn);
	free(prn->ps);
	fn_reinicialize(prn);
	return ;
}
