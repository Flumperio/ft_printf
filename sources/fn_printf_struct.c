/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:55:21 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/11 17:44:11 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fn_reinicialize(t_parms *prn)
{
	prn->args_temp = NULL;
	prn->args_char_temp = 0;
	prn->args_len = 0;
	prn->current_format = '\0';
	prn->current_flag = 0;
	prn->current_align = 0;
	prn->current_sign = 0;
	prn->current_space = 0;
	prn->current_zero = 0;
	prn->current_hash = 0;
	prn->current_size = 0;
	prn->print_string = NULL;
	prn->current_pre = 0;
	prn->fill_char = ' ';
	prn->flag_sign = 0;
	return ;
}

void	fn_inicialize(t_parms *prn)
{
	prn->args_temp = NULL;
	prn->args_char_temp = 0;
	prn->args_len = 0;
	prn->cnt = 0;
	prn->prt_chars = 0;
	prn->current_format = '\0';
	prn->current_flag = '\0';
	prn->current_lenght = '\0';
	prn->current_size = 0;
	prn->current_pre = 0;
	prn->string = NULL;
	prn->format_type = "scdiuUxXp%";
	prn->flags_type = "-+0#";
	prn->current_align = 0;
	prn->current_sign = 0;
	prn->current_space = 0;
	prn->current_zero = 0;
	prn->current_hash = 0;
	prn->lenght_type = "lhjz";
	prn->flag_width = 0;
	prn->flag_precision = 0;
	prn->flag_size = 0;
	prn->fill_char = ' ';
	prn->flag_sign = 0;
	return ;
}
