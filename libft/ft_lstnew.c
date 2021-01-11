/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 12:56:27 by juasanto          #+#    #+#             */
/*   Updated: 2020/07/28 10:00:05 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = (t_list *)malloc(sizeof(*new_content));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
