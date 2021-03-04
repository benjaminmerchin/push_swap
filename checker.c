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
	(void)data;
	if (data->buff[0] == 's')
	{
		if (data->buff[1] == 'a')
			sa(data);
	}
}

int	main(int ac, char **av)
{
	int i;
	char c;
	t_data data;
	
	data.spliter = ac - 1;
	data.size = ac - 1;
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
			ft_putstr_fd(data.buff, 1);
			instruction_verification(&data);
			execute_instruction(&data);
		}
		//si i est trop grand quitter
		//write(1, &c, 1);
	}
	free(data.list);
	return (0);
}
