/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:03:47 by jcsantos          #+#    #+#             */
/*   Updated: 2021/01/14 16:23:45 by jcsantos         ###   ########.fr       */
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
			temp = ft_strjoin_clean(fill, prn->ps, 2);
			prn->ps = temp;
			cnt--;
		}
	}
	else
	{
		while (cnt > 0)
		{
			temp = ft_strjoin_clean(prn->ps, fill, 1);
			prn->ps = temp;
			cnt--;
		}
	}
	return ;
}

void		fill_sign(t_parms *prn)
{
	char	*temp;

	temp = NULL;
	if (prn->flag_s == 1)
	{
		temp = ft_strjoin_clean("-", prn->ps, 2);
		prn->ps = temp;
	}
	else if (prn->c_sign == 1)
	{
		temp = ft_strjoin_clean("+", prn->ps, 2);
		prn->ps = temp;
	}
	return ;
}

void		fill_0x(t_parms *prn)
{
	if (prn->cf == 'p' || prn->cf == 'x')
		prn->ps = ft_strjoin_clean("0x", prn->ps, 2);
	else
		prn->ps = ft_strjoin_clean("0X", prn->ps, 2);
}
