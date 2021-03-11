/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_chk_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:16:32 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/08 13:06:01 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	check_flags1(t_parms *prn)
{
	int	cnt1;

	cnt1 = -1;
	while (prn->flags_type[++cnt1] != 0)
	{
		if (prn->string[prn->cnt] == '-')
		{
			prn->c_align = 1;
			prn->cnt++;
		}
		if (prn->string[prn->cnt] == '+')
		{
			prn->c_sign = 1;
			prn->cnt++;
		}
		if (prn->string[prn->cnt] == ' ')
		{
			prn->c_space = 1;
			prn->cnt++;
		}
		return (1);
	}
	return (0);
}

int	check_flags2(t_parms *prn)
{
	int	cnt1;

	cnt1 = -1;
	while (prn->flags_type[++cnt1] != 0)
	{
		if (prn->string[prn->cnt] == '0')
		{
			prn->c_zero = 1;
			prn->cnt++;
		}
		if (prn->string[prn->cnt] == '#')
		{
			prn->c_hash = 1;
			prn->cnt++;
		}
		return (1);
	}
	return (0);
}

int	check_parms(char *stc, char *current, t_parms *prn)
{
	int		cnt1;

	cnt1 = -1;
	while (stc[++cnt1] != 0)
	{
		if (prn->string[prn->cnt] == stc[cnt1])
		{
			*current = prn->string[prn->cnt];
			prn->cnt++;
			return (1);
		}
	}
	return (0);
}

int	check_num(int *current, t_parms *prn)
{
	*current = 0;
	if (prn->string[prn->cnt] == '*')
	{
		*current = va_arg(prn->args, int);
		prn->cnt++;
		return (*current);
	}
	else if (prn->string[prn->cnt] >= '0' && prn->string[prn->cnt] <= '9')
	{
		while (prn->string[prn->cnt] && prn->string[prn->cnt] >= '0' && \
				prn->string[prn->cnt] <= '9')
		{
			*current *= 10;
			*current += prn->string[prn->cnt++] - '0';
		}
		return (*current);
	}
	else
		return (0);
}

int	check_format(t_parms *prn)
{
	int		cnt1;

	cnt1 = -1;
	while (prn->format_type[++cnt1] != 0)
	{
		if (prn->string[prn->cnt] == prn->format_type[cnt1])
		{
			prn->cf = prn->string[prn->cnt];
			prn->cnt++;
			return (1);
		}
	}
	return (0);
}
