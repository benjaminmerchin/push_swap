/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:43:17 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/03 16:43:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	quick_sort(t_data *data)
{
	(void)data;
}

void	sort_two_top_a(t_data *data)
{
	if (data->list[data->spliter - 1] > data->list[data->spliter - 2])
	{
		sa(data);
		ft_putstr("sa\n");
	}
}

void	sort_only_three(t_data *data)
{
	if (data->list[data->spliter - 1] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 2])
	{
		ra(data);
		ft_putstr("ra\n");
		sa(data);
		ft_putstr("sa\n");
		rra(data);
		ft_putstr("rra\n");
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 3])
	{
		sa(data);
		ft_putstr("sa\n");
	}
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 2])
	{
		rra(data);
		ft_putstr("rra\n");
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 1])
	{
		ra(data);
		ft_putstr("ra\n");
	}
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 2] &&
	data->list[data->spliter - 2] < data->list[data->spliter - 1])
	{
		sa(data);
		ft_putstr("sa\n");
		rra(data);
		ft_putstr("rra\n");
	}
}

void	sort(t_data *data)
{
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sort_two_top_a(data);
	else if (data->size == 3)
		sort_only_three(data);
	else
		quick_sort(data);
}

int main(int ac, char **av)
{
	int i;
	t_data data;
	char **tab;
	
	i = 0;
	if (ac == 1)
		return (0);
	data.spliter = ac - 1;
	data.size = ac - 1;
	data.error_instruc = 0;
	if (!(data.list = malloc(sizeof(int) * (ac - 1))))
		return (0); //message d'erreur
	i = ac - 1;
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		i = ft_nbr_str(av[1], ' ');
		//printf(">>>i : %d<<<\n", i);
		//printf(">>>tab 0: %s<<<\n", tab[0]);
		//printf(">>>tab 1: %s<<<\n", tab[1]);
		data.spliter = i;
		data.size = i;
	}
	while (i > 0)
	{
		//security qu'on a bien un int en entree;
		//security no duplicates
		if (ac == 2)
		{
			data.list[data.spliter - i] = atoi(tab[i - 1]);
			//printf(">>>%d<<<\n", atoi(tab[i - 1]));
		}
		else
			data.list[ac - i - 1] = atoi(av[i]);
		i--;
	}
	//printf(">>>lst 0: %d<<<\n", data.list[0]);
	//printf(">>>lst 1: %d<<<\n", data.list[1]);
	print_state(&data);
	sort(&data);
	print_state(&data);
	free(data.list);
	if (ac == 2)
		ft_free(tab, ft_nbr_str(av[1], ' '));
	//ft_putstr(av[1]);
	return (0);
}
