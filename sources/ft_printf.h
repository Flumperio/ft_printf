/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:18:05 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/11 12:59:54 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define RED		"\x1B[31m"
# define GRN		"\x1B[32m"
# define YEL		"\x1B[33m"
# define BLU		"\x1B[34m"
# define MAG		"\x1B[35m"
# define CYN		"\x1B[36m"
# define WHT		"\x1B[37m"
# define DIM		"\x1B[2m"
# define RESET		"\x1B[0m"
# define FAULT		"\x1B[0;31;43m"
# define INT_MAX	+2147483647
# define INT_MIN	-2147483648

typedef struct	s_parms
{
	va_list		args;
	char		*args_temp;
	int			args_char_temp;
	int			args_len;
	int			cnt;
	int			prt_chars;
	char		current_format;
	char		current_flag;
	char		current_lenght;
	int			current_size;
	int			current_pre;
	const char	*string;
	char		*print_string;
	char		*format_type;
	char		*flags_type;
	int			current_align;
	int			current_sign;
	int			current_space;
	int			current_zero;
	int			current_hash;
	char		*lenght_type;
	int			flag_width;
	int			flag_precision;
	int			flag_size;
	char		fill_char;
	int			flag_sign;
}				t_parms;

int				ft_printf(const char *string, ...);
void			fn_reinicialize(t_parms *prn);
void			fn_inicialize(t_parms *prn);
int				fn_analisys(t_parms *prn);
void			fn_prints(t_parms *prn);
void			fill_str(int cnt, int ab, char *fill, t_parms *prn);
void			fn_printi_d(t_parms *prn);
void			fn_print_c(t_parms *prn);
void			fn_print_s(t_parms *prn);
void			fn_printx(t_parms *prn);
void			fn_print_chk_s(t_parms *prn);
char			*fn_print_chk_iud(t_parms *prn, char *temp, int int_temp,
				long long int uint_temp);
char			*fn_print_chk_xp(t_parms *prn, char *temp, int int_temp,
				long long int uint_temp);
void			fn_print_chk_c(t_parms *prn);
int				check_flags1(t_parms *prn);
int				check_flags2(t_parms *prn);
int				check_parms(char *stc, char *current, t_parms *prn);
int				check_num(int *current, t_parms *prn);
int				check_format(t_parms *prn);
int				fn_write(const char *str, int len, t_parms *prn);
char			*ft_itoa_u(unsigned int n);
char			*fn_dectohex(long long int n, int capital, int j);

#endif
