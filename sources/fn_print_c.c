/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:42:45 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/08 13:04:43 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fn_chek_align(t_parms *prn)
{
	if (prn->c_zero == 1 && prn->c_align == 0)
		fill_str(prn->cs, prn->c_align, "0", prn);
	else
		fill_str(prn->cs, prn->c_align, " ", prn);
	return ;
}

void	fn_check_p(t_parms *prn)
{
	prn->cs = (prn->flag_w - prn->args_len);
	if (prn->cf == '%')
		prn->a_c_t = 37;
	return ;
}

void	fn_print_c(t_parms *prn)
{
	int		tmp_len;
	char	tmp_char;
	char	*tmp;
	int		b;

	tmp_len = 0;
	b = 0;
	fn_check_p(prn);
	tmp_char = prn->a_c_t;
	tmp = ft_strdup(&tmp_char);
	prn->ps = tmp;
	if (prn->a_c_t == 0)
		b = 1;
	if (prn->c_align == 1 && prn->a_c_t == 0)
	{
		fn_write((char *)&prn->a_c_t, 1, prn);
		b = 0;
	}
	fn_chek_align(prn);
	tmp_len = ft_strlen(prn->ps);
	fn_write(prn->ps, tmp_len + b, prn);
	free(prn->ps);
	fn_reinicialize(prn);
	return ;
}
