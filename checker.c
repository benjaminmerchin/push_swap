/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:13:57 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/04 11:13:58 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ok_or_ko(t_data *data)
{
	int i;

	i = 0;
	if (data->size != data->spliter)
	{
		write(1, "KO", 2);
		printf("\tNumber of Instructions: %d\n", data->instuctions);
		return ;
	}
	while (i < data->size - 1)
	{
		if (data->list[i] > data->list[i + 1])
			i++;
		else
		{
			write(1, "KO", 2);
			printf("\tNumber of Instructions: %d\n", data->instuctions);
			return ;
		}
	}
	write(1, "OK", 2);
	printf("\tNumber of Instructions: %d\n", data->instuctions);
}

int		main_extension_two(int ac, char **av, int i, char ***tab, t_data *data)
{
	char c;

	while (read(0, &c, 1) > 0)
	{
		data->buff[i] = c;
		i++;
		if (c == '\n')
		{
			i = 0;
			data->instuctions++;
			execute_instruction_checker(data);
		}
		if (data->error)
			return (ft_free_print_error(data, ac, av, tab));
	}
	ok_or_ko(data);
	free(data->list);
	if (ac == 2)
		ft_free(*tab, ft_nbr_str(av[1], ' '));
	return (0);
}

int		main_extension(int ac, char **av, int i, char ***tab, t_data *data)
{
	if (!(data->list = malloc(sizeof(int) * data->size)))
		return (free_tab_print_error(ac, av, tab));
	while (i > 0)
	{
		if (ac == 2)
		{
			data->list[data->spliter - i] = ft_atoi((*tab)[i - 1], data);
			security_duplicates(data, data->spliter - i);
		}
		else
		{
			data->list[ac - i - 1] = ft_atoi(av[i], data);
			security_duplicates(data, ac - i - 1);
		}
		if (data->error == 1)
			return (ft_free_print_error(data, ac, av, tab));
		i--;
	}
	i = 0;
	data->instuctions = 0;
	return (main_extension_two(ac, av, i, tab, data));
}

int		main(int ac, char **av)
{
	int		i;
	t_data	data;
	char	**tab;

	tab = NULL;
	data.error = 0;
	data.rrr = 0;
	if (ac == 1)
		return (0);
	data.spliter = ac - 1;
	data.size = ac - 1;
	data.error = 0;
	i = ac - 1;
	if (ac > 10000)
		return (ft_error());
	if (ac == 2)
	{
		i = ft_nbr_str(av[1], ' ');
		if (i > 10000)
			return (ft_error());
		tab = ft_split(av[1], ' ');
		data.spliter = i;
		data.size = i;
	}
	return (main_extension(ac, av, i, &tab, &data));
}
