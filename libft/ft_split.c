/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:12:23 by juasanto          #+#    #+#             */
/*   Updated: 2020/08/04 11:51:55 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_word(char const *str, char chr)
{
	int		swtch;
	int		cnt;

	swtch = 0;
	cnt = 0;
	while (*str != 0)
	{
		if (swtch == 1 && *str == chr)
			swtch = 0;
		if (swtch == 0 && *str != chr)
		{
			swtch = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

char		**ft_split(char const *s, char c)
{
	int		split_num;
	char	**split_array;
	int		start;
	int		cnt_pnt;
	int		cnt_array;

	cnt_pnt = 0;
	cnt_array = -1;
	split_num = count_word(s, c);
	if (!(split_array = (char **)malloc((sizeof(char *)) * split_num + 1)))
		return (NULL);
	while (++cnt_array < split_num)
	{
		while (s[cnt_pnt] == c && s[cnt_pnt] != 0)
			cnt_pnt++;
		start = cnt_pnt;
		while (s[cnt_pnt] != c && s[cnt_pnt] != 0)
			cnt_pnt++;
		split_array[cnt_array] = ft_substr(s, start, cnt_pnt - start);
		cnt_pnt++;
	}
	split_array[cnt_array] = 0;
	return (split_array);
}
