/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:35:55 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 11:35:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../source/so_long.h"

t_checking_map	init_checking_map(void)
{
	t_checking_map	new;

	new.y = 0;
	new.e = 0;
	new.c = 0;
	new.p = 0;
	return (new);
}