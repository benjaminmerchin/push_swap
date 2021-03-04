/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:36:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 12:36:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_data *data) // on souhaite inverser l'emplacement data_spliter - 1 avec data_spliter - 2
{
	int temp;

	if (data->spliter < 2)
		return ;
	temp = data->list[data->spliter - 1];
	data->list[data->spliter - 1] = data->list[data->spliter - 2];
	data->list[data->spliter - 2] = temp;
}

void	sb(t_data *data) // on souhaite inverser l'emplacement data_spliter - 1 avec data_spliter - 2
{
	int temp;

	if (data->spliter < 2)
		return ;
	temp = data->list[data->spliter - 1];
	data->list[data->spliter - 1] = data->list[data->spliter - 2];
	data->list[data->spliter - 2] = temp;
}
