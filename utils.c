/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:13:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 11:13:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_state(t_data *data)
{
	int i;

	i = 0;
	while (i < data->size)
	{
		ft_putnbr(data->list[i]);
		if (i == data->spliter - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\t');
	ft_putstr("spliter : ");
	ft_putnbr(data->spliter);
	ft_putchar('\n');
}
