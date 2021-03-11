/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:55:21 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/18 12:48:56 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fn_reinicialize(t_parms *prn)
{
	prn->args_temp = NULL;
	prn->a_c_t = 0;
	prn->args_len = 0;
	prn->cf = '\0';
	prn->c_flag = 0;
	prn->c_align = 0;
	prn->c_sign = 0;
	prn->c_space = 0;
	prn->c_zero = 0;
	prn->c_hash = 0;
	prn->cs = 0;
	prn->ps = NULL;
	prn->c_pre = 0;
	prn->fill_char = ' ';
	prn->flag_s = 0;
	return ;
}

void	fn_inicialize(t_parms *prn)
{
	prn->args_temp = NULL;
	prn->a_c_t = 0;
	prn->args_len = 0;
	prn->cnt = 0;
	prn->prt_chars = 0;
	prn->cf = '\0';
	prn->c_flag = '\0';
	prn->c_lenght = '\0';
	prn->cs = 0;
	prn->c_pre = 0;
	prn->string = NULL;
	prn->ps = NULL;
	prn->format_type = "scdiuUxXp%";
	prn->flags_type = "-+0#";
	prn->c_align = 0;
	prn->c_sign = 0;
	prn->c_space = 0;
	prn->c_zero = 0;
	prn->c_hash = 0;
	prn->lenght_type = "lhjz";
	prn->flag_w = 0;
	prn->flag_p = 0;
	prn->fill_char = ' ';
	prn->flag_s = 0;
	return ;
}
