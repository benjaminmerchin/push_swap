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

void	execute_instruction(t_data *data)
{
	if (data->buff[0] == 's' && data->buff[1] == 'a' && data->buff[2] == '\n')
		sa(data);
	else if (data->buff[0] == 's' && data->buff[1] == 'b' && data->buff[2] == '\n')
		sb(data);
	else if (data->buff[0] == 's' && data->buff[1] == 's' && data->buff[2] == '\n')
		ss(data);
	else if (data->buff[0] == 'p' && data->buff[1] == 'a' && data->buff[2] == '\n')
		pa(data);
	else if (data->buff[0] == 'p' && data->buff[1] == 'b' && data->buff[2] == '\n')
		pb(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'a' && data->buff[2] == '\n')
		ra(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'b' && data->buff[2] == '\n')
		rb(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == '\n')
		rr(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == 'a' && data->buff[3] == '\n')
		rra(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == 'b' && data->buff[3] == '\n')
		rrb(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == 'r' && data->buff[3] == '\n')
		rrr(data);
	else
	{
		data->error_instruc = 1;
		ft_putstr_fd("Error", 0);
		ft_putchar_fd('\n', 0);
		// free
		//exit (0);
	}
	print_state(data); //
}

void	ok_or_ko(t_data *data)
{
	int i;

	i = 0;
	if (data->size != data->spliter)
	{
		write(1, "KO", 2);
		printf("\tNumber of Instructions: %d\n", data->counter);
		return ;
	}
	while (i < data->size - 1)
	{
		if (data->list[i] > data->list[i + 1])
			i++;
		else
		{
			write(1, "KO", 2);
			printf("\tNumber of Instructions: %d\n", data->counter);
			return ;
		}
	}
	write(1, "OK", 2);
	printf("\tNumber of Instructions: %d\n", data->counter);
}

int	main(int ac, char **av)
{
	int i;
	char c;
	t_data data;
	
	if (ac == 1)
		return (0);
	data.spliter = ac - 1;
	data.size = ac - 1;
	data.error_instruc = 0;
	if (!(data.list = malloc(sizeof(int) * (ac - 1))))
		return (0); //message d'erreur
	i = ac - 1;
	while (i > 0)
	{
		//security qu'on a bien un int en entree;
		//security no duplicates
		data.list[ac - i - 1] = atoi(av[i]);
		i--;
	}
	print_state(&data);
	ft_putstr("---------------------------");
	ft_putchar('\n');
	i = 0;
	data.counter = 0;
	while (read(0, &c, 1) > 0)
	{
		data.buff[i] = c;
		i++;
		if (c == '\n')
		{
			i = 0;
			/*ft_putchar(data.buff[0]);
			ft_putchar('|');
			ft_putchar(data.buff[1]);
			ft_putchar('|');
			ft_putchar(data.buff[2]);
			ft_putchar('|');
			ft_putchar(data.buff[3]);
			ft_putchar('|');
			ft_putchar('\n');*/
			//ft_putstr(data.buff);
			data.counter++;
			execute_instruction(&data);
		} //attention si la derniere instruction est fausse
		if (i == 5)
			data.error_instruc = 1;
	}
	ft_putstr("---------------------------");
	ft_putchar('\n');
	print_state(&data);
	ok_or_ko(&data);
	free(data.list);
	return (0);
}
