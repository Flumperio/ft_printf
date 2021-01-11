/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printi_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:39:54 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/07 13:01:42 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_str(int cnt, int ab, char *fill, t_parms *prn)
{
	char	*temp;

	temp = NULL;
	if (ab == 0)
	{
		while (cnt > 0)
		{
			temp = ft_strjoin_clean(fill, prn->print_string, 2);
			prn->print_string = temp;
			cnt--;
		}
	}
	else
	{
		while (cnt > 0)
		{
			temp = ft_strjoin_clean(prn->print_string, fill, 1);
			prn->print_string = temp;
			cnt--;
		}
	}
	return ;
}

void		fill_sign(t_parms *prn)
{
	char	*temp;

	temp = NULL;
	if (prn->flag_sign == 1)
	{
		temp = ft_strjoin_clean("-", prn->print_string, 2);
		prn->print_string = temp;
	}
	else if (prn->current_sign == 1)
	{
		temp = ft_strjoin_clean("+", prn->print_string, 2);
		prn->print_string = temp;
	}
	return ;
}

void		fn_printi_d(t_parms *prn)
{
	char	*temp;
	int		tmp_len;

	temp = NULL;
	tmp_len = 0;
	temp = ft_strdup(prn->args_temp);
	prn->print_string = temp;
	prn->current_size = ((prn->flag_width > prn->flag_precision ?
						prn->flag_width : prn->flag_precision) - prn->args_len);
	if (prn->current_pre == 1 && prn->flag_precision <= 0 &&
		prn->print_string[0] == '0')
	{
		prn->print_string[0] = 0;
		prn->current_size += 1;
	}
	if (prn->current_format == 'p' && prn->flag_precision <= prn->args_len)
		prn->print_string = ft_strjoin_clean("0x", prn->print_string, 2);
	if (prn->current_size >= 1)
	{
		fill_str((prn->flag_precision - prn->args_len), 0, "0", prn);
		if (prn->current_format == 'p' && prn->print_string[1] != 'x')
			prn->print_string = ft_strjoin_clean("0x", prn->print_string, 2);
		tmp_len = ft_strlen(prn->print_string);
		if (prn->current_sign == 1 || prn->flag_sign == 1)
			tmp_len += 1;
		if (prn->current_zero == 0 || (prn->current_zero == 1 &&
			prn->flag_precision >= 0 && prn->current_pre == 1) ||
			prn->current_align == 1)
		{
			fill_sign(prn);
			fill_str(prn->flag_width - tmp_len, prn->current_align, " ", prn);
		}
		else
		{
			fill_str(prn->flag_width - tmp_len, prn->current_align, "0", prn);
			fill_sign(prn);
		}
	}
	else
		fill_sign(prn);
	tmp_len = ft_strlen(prn->print_string);
	fn_write(prn->print_string, tmp_len, prn);
	free(prn->print_string);
	fn_reinicialize(prn);
	return ;
}
