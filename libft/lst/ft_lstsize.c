/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atinseau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:16:36 by atinseau          #+#    #+#             */
/*   Updated: 2020/11/20 13:18:35 by atinseau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*s;
	int		i;

	s = lst;
	i = 0;
	while (s != NULL)
	{
		s = s->next;
		i++;
	}
	return (i);
}