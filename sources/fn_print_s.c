/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:59:57 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/07 13:05:28 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fn_print_s(t_parms *prn)
{
	char	*temp;
	int		tmp_len;

	temp = NULL;
	tmp_len = 0;
	temp = ft_strdup(prn->args_temp);
	prn->print_string = temp;
	if ((prn->flag_precision > 0 && prn->flag_precision < prn->args_len) ||
		prn->current_pre == 1)
		prn->print_string[prn->flag_precision] = 0;
	tmp_len = ft_strlen(prn->print_string);
	prn->current_size = (prn->flag_width - tmp_len);
	if (prn->current_size >= 1 && prn->current_zero == 1 &&
		prn->current_align == 0)
		fill_str(prn->flag_width - tmp_len, prn->current_align, "0", prn);
	else
		fill_str(prn->flag_width - tmp_len, prn->current_align, " ", prn);
	tmp_len = ft_strlen(prn->print_string);
	fn_write(prn->print_string, tmp_len, prn);
	free(prn->print_string);
	fn_reinicialize(prn);
	return ;
}
