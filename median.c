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

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*dup)[i] > (*dup)[j])
			{
				temp = (*dup)[i];
				(*dup)[i] = (*dup)[j];
				(*dup)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int		median(t_data *data, int begin, int end)
{
	int i;
	int *dup;

	i = begin;
	if (!(dup = malloc(sizeof(int) * (end - begin))))
	{
		data->error = 1;
		return (0);
	}
	while (i < end)
	{
		dup[i - begin] = data->list[i];
		i++;
	}
	sort_list(&dup, end - begin);
	i = dup[(end - begin) / 2];
	/*printf(">>>dup[3] %d<<<\n", dup[3]);
	for(int j = 0; j < end - begin ;j++)
		printf("%d ", dup[j]);
	printf("\n>>>i: %d<<<\n", i);
	printf(">>>end: %d<<<\n", end);
	printf(">>>begin: %d<<<\n", begin);
	printf(">>>end - begin: %d<<<\n", end - begin);
	printf(">>>i: %d<<<\n", i);
	printf(">>>dup 0: %d<<<\n", dup[0]);
	printf(">>>dup end: %d<<<\n", dup[end - begin - 1]);*/
	data->pivot_min = dup[0];
	data->pivot_max = dup[end - begin - 1];
	free(dup);
	return (i);
}
