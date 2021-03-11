/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:59:57 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:05:06 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fn_print_s(t_parms *prn)
{
	char	*temp;
	int		tmp_len;

	temp = NULL;
	tmp_len = 0;
	temp = ft_strdup(prn->args_temp);
	prn->ps = temp;
	if ((prn->flag_p > 0 && prn->flag_p < prn->args_len) || \
		prn->c_pre == 1)
		prn->ps[prn->flag_p] = 0;
	tmp_len = ft_strlen(prn->ps);
	prn->cs = (prn->flag_w - tmp_len);
	if (prn->cs >= 1 && prn->c_zero == 1 && \
		prn->c_align == 0)
		fill_str(prn->flag_w - tmp_len, prn->c_align, "0", prn);
	else
		fill_str(prn->flag_w - tmp_len, prn->c_align, " ", prn);
	tmp_len = ft_strlen(prn->ps);
	fn_write(prn->ps, tmp_len, prn);
	free(prn->ps);
	fn_reinicialize(prn);
	return ;
}
