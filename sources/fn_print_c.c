/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:42:45 by jcsantos          #+#    #+#             */
/*   Updated: 2021/01/08 13:09:12 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fn_chek_align(t_parms *prn)
{
	if (prn->current_zero == 1 && prn->current_align == 0)
		fill_str(prn->current_size, prn->current_align, "0", prn);
	else
		fill_str(prn->current_size, prn->current_align, " ", prn);
	return ;
}

void		fn_check_p(t_parms *prn)
{
	prn->current_size = (prn->flag_width - prn->args_len);
	if (prn->current_format == '%')
		prn->args_char_temp = 37;
	return ;
}

void		fn_print_c(t_parms *prn)
{
	int		tmp_len;
	char	tmp_char;
	char	*tmp;
	int		b;

	tmp_len = 0;
	b = 0;
	fn_check_p(prn);
	tmp_char = prn->args_char_temp;
	tmp = ft_strdup(&tmp_char);
	prn->print_string = tmp;
	if (prn->args_char_temp == 0)
		b = 1;
	if (prn->current_align == 1 && prn->args_char_temp == 0)
	{
		fn_write((char *)&prn->args_char_temp, 1, prn);
		b = 0;
	}
	fn_chek_align(prn);
	tmp_len = ft_strlen(prn->print_string);
	fn_write(prn->print_string, tmp_len + b, prn);
	free(prn->print_string);
	fn_reinicialize(prn);
	return ;
}
