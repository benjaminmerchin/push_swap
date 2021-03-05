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

int	instruction_verification(t_data *data)
{
	(void)data; // verifier la validité des instructions
	return (0);
}

void	execute_instruction(t_data *data)
{
	if (data->buff[0] == 's' && data->buff[1] == 'a' && data->buff[2] != '\n')
		sa(data);
	else if (data->buff[0] == 's' && data->buff[1] == 'b' && data->buff[2] != '\n')
		sb(data);
	else if (data->buff[0] == 's' && data->buff[1] == 's' && data->buff[2] != '\n')
		ss(data);
	else if (data->buff[0] == 'p' && data->buff[1] == 'a' && data->buff[2] != '\n')
		pa(data);
	else if (data->buff[0] == 'p' && data->buff[1] == 'b' && data->buff[2] != '\n')
		pb(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'a' && data->buff[2] != '\n')
		ra(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'b' && data->buff[2] != '\n')
		rb(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] != '\n')
		rr(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == 'a' && data->buff[3] != '\n')
		rra(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == 'b' && data->buff[3] != '\n')
		rra(data);
	else if (data->buff[0] == 'r' && data->buff[1] == 'r' && data->buff[2] == 'r' && data->buff[3] != '\n')
		rrr(data);
	else
		data->error_instruc = 1;
}

int	main(int ac, char **av)
{
	int i;
	char c;
	t_data data;
	
	data.spliter = ac - 1;
	data.size = ac - 1;
	data.error_instruc = 0;
	if (!(data.list = malloc(sizeof(int) * (ac - 1))))
		return (0); //message d'erreur
	i = 1;
	while (i < ac)
	{
		//security qu'on a bien un int en entree;
		data.list[i - 1] = atoi(av[i]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		printf("%d\n", data.list[i]);
		i++;
	}
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		data.buff[i] = c;
		i++;
		if (c == '\n')
		{
			data.buff[i] = '\0';
			i = 0;
			ft_putstr(data.buff);
			instruction_verification(&data);
			execute_instruction(&data);
		}
		//si i est trop grand quitter
		//write(1, &c, 1);
	}
	free(data.list);
	return (0);
}
