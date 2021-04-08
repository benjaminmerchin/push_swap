/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:43:17 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/03 16:43:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	execute_instruction_2(t_data *data)
{
	if (data->buff[1] == 'a' && data->buff[2] == '\n')
		ra(data);
	else if (data->buff[1] == 'b' && data->buff[2] == '\n')
		rb(data);
	else if (data->buff[1] == 'r' && data->buff[2] == '\n')
		rr(data);
	else if (data->buff[1] == 'r'
	&& data->buff[2] == 'a' && data->buff[3] == '\n')
		rra(data);
	else if (data->buff[1] == 'r'
	&& data->buff[2] == 'b' && data->buff[3] == '\n')
		rrb(data);
	else if (data->buff[1] == 'r'
	&& data->buff[2] == 'r' && data->buff[3] == '\n')
		rrr(data);
	else
		data->error = 1;
}

void	execute_instruction(t_data *data)
{
	if (data->buff[0] == 's' && data->buff[1] == 'a' && data->buff[2] == '\n')
		sa(data);
	else if (data->buff[0] == 's'
	&& data->buff[1] == 'b' && data->buff[2] == '\n')
		sb(data);
	else if (data->buff[0] == 's'
	&& data->buff[1] == 's' && data->buff[2] == '\n')
		ss(data);
	else if (data->buff[0] == 'p'
	&& data->buff[1] == 'a' && data->buff[2] == '\n')
		pa(data);
	else if (data->buff[0] == 'p'
	&& data->buff[1] == 'b' && data->buff[2] == '\n')
		pb(data);
	else if (data->buff[0] == 'r')
		execute_instruction_2(data);
	else
		data->error = 1;
}
