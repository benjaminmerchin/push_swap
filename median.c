/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:43:17 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/03 16:43:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_list(int **dup, int len)
{
	int i;
	int j;
	int temp;

	while (i )
}

int		median(t_data *data, int begin, int end)
{
	int i;
	int *dup;

	i = begin;
	if (!(dup = malloc(sizeof(int) * (begin - end))))
		return (0);
	while (i < end)
	{
		dup[i] = data->list[i];
		i++;
	}
	sort_list(&dup, end - begin);
	free(dup);
	return (0);
}
