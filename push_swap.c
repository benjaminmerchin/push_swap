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
int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	find_three_closest_pos_b(t_data *data, int pivot) //outdated function
{
	int i;

	i = data->spliter;
	data->above_val = 2147483647;
	data->bellow_val = -2147483648;
	data->equal_pos = -1;
	while (i < data->size)
	{
		if (data->list[i] == pivot)
			data->equal_pos = i;
		else if (data->list[i] >= pivot)
		{
			if (data->list[i] <= data->above_val)
			{
				data->above_val = data->list[i];
				data->above_pos = i;
			}
		}
		else if (data->list[i] <= pivot)
		{
			if (data->list[i] >= data->bellow_val)
			{
				data->bellow_val = data->list[i];
				data->bellow_pos = i;
			}
		}
		i++;
	} // i pivort est positif ou egal a 0, ca signifie qu'on est sur un premier passage et on a pivot
}




void	find_farthest_pos_b(t_data *data) // -2147483648 // 2147483647
{
	int i;

	i = data->spliter;
	data->above_val = -2147483648;
	data->a_val = -2147483648;
	data->bellow_val = 2147483647;
	data->b_val = 2147483647;
	while (i < data->size)
	{
		if (data->list[i] >= data->above_val)
		{
			data->above_val = data->list[i];
			data->above_pos = i;
		}
		if (data->list[i] <= data->bellow_val)
		{
			data->bellow_val = data->list[i];
			data->bellow_pos = i;
		}
		i++;
	}
	if (data->size - data->spliter < 5)
	{
		data->too_small = 1;
		return ;
	}
	i = data->spliter;
	while (i < data->size)
	{
		if (data->list[i] == data->above_val || data->list[i] == data->bellow_val)
			;
		else
		{
			if (data->list[i] >= data->a_val)
			{
				data->a_val = data->list[i];
				data->a_pos = i;
			}
			if (data->list[i] <= data->b_val)
			{
				data->b_val = data->list[i];
				data->b_pos = i;
			}
		}
		i++;
	}		//if (data->a_val == -9)ft_putstr("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	/*ft_putstr("above_val : ");
	ft_putnbr(data->above_val);
	ft_putstr("\n");
	ft_putstr("a_val : ");
	ft_putnbr(data->a_val);
	ft_putstr("\n");
	ft_putstr("bellow_val : ");
	ft_putnbr(data->bellow_val);
	ft_putstr("\n");
	ft_putstr("b_val : ");
	ft_putnbr(data->b_val);
	ft_putstr("\n");*/
}

void	calculate_best_move2(t_data *data) //write the 8 options with all the  //priority for 	above
{
	int min;

	min = data->above_pos - data->spliter;
	if (data->bellow_pos - data->spliter < min)
		min = data->bellow_pos - data->spliter;
	if (data->size - data->above_pos < min)
		min = data->size - data->above_pos;
	if (data->size - data->bellow_pos < min)
		min = data->size - data->bellow_pos;
	if (data->a_pos - data->spliter + 1 < min && !data->lock_a && !data->too_small)
		min = data->a_pos - data->spliter + 1;
	if (data->b_pos - data->spliter + 2 < min && !data->lock_b && !data->too_small)
		min = data->b_pos - data->spliter + 2;
	if (data->size - data->a_pos + 1 < min && !data->lock_a && !data->too_small)
		min = data->size - data->a_pos + 1;
	if (data->size - data->b_pos + 2 < min && !data->lock_b && !data->too_small)
		min = data->size - data->b_pos + 2;

	if (min == data->above_pos - data->spliter)
	{
		data->rotation = min;
		data->direction = 1;
		data->relative = 4;  /* 1 2       3 4 */
		data->val = data->above_val;
	}
	else if (min == data->size - data->above_pos)
	{
		data->rotation = min;
		data->direction = -1;
		data->relative = 4;
		data->val = data->above_val;
	}
	else if (min == data->a_pos - data->spliter + 1 && !data->lock_a && !data->too_small)
	{
		data->rotation = data->a_pos - data->spliter;
		data->direction = 1;
		data->relative = 3;
		data->val = data->a_val;
	}
	else if (min == data->size - data->a_pos + 1 && !data->lock_a && !data->too_small)
	{
		data->rotation = data->size - data->a_pos;
		data->direction = -1;
		data->relative = 3;
		data->val = data->a_val;
	}
	else if (min == data->bellow_pos - data->spliter)
	{
		data->rotation = min;
		data->direction = 1;
		data->relative = 1;
		data->val = data->bellow_val;
	}
	else if (min == data->size - data->bellow_pos)
	{
		data->rotation = min;
		data->direction = -1;
		data->relative = 1;
		data->val = data->bellow_val;
	}
	else if (min == data->size - data->b_pos + 2 && !data->lock_b && !data->too_small)
	{
		data->rotation = data->size - data->b_pos;
		data->direction = -1;
		data->relative = 2;
		data->val = data->b_val;
	}
	else if (min == data->b_pos - data->spliter + 2 && !data->lock_b && !data->too_small)
	{
		data->rotation = data->b_pos - data->spliter;
		data->direction = 1;
		data->relative = 2;
		data->val = data->b_val;
	}
	/*else
	{
		ft_putstr("##########");
		ft_putstr("\nMin : ");
		ft_putnbr(min);
		ft_putstr("\nVal : ");
		ft_putnbr(data->val);
		ft_putstr("\nToo_small : ");
		ft_putnbr(data->too_small);		
		ft_putstr("\n##########\n");
	}*/

	//above_pos up
	//above_pos down
	//a_pos up		//bloquer si on a un a_pos dernierement avant d'avoir un above_pos
	//a_pos down	//idem
	//bellow_pos up
	//bellow_pos down
	//b_pos up      //bloquer si on a un b_pos dernierement avant d'avoir un bellow_pos //rajouter + 
	//b_pos down	//idem

	//une fois qu'on a le meilleur mouv
}

void	raw_optimize(t_data *data, int *i)
{
	if (*i < data->rotation && data->direction > 0)
	{
		rrw(data);
		(*i)++;
	}
	else
		raw(data);
}

void	rraw_optimize(t_data *data, int *i)
{
	if (*i < data->rotation && data->direction < 0)
	{
		rrrw(data);
		(*i)++;
	}
	else
		rraw(data);
}

void	execute_best_move_b2(t_data *data, int min, int max)
{
	int i;

	i = 0;
	if (!data->bool_first_move)
	{
		if (data->list[data->spliter - 1] < data->val && data->list[data->spliter - 1] >= min && data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val && data->list[data->spliter - 1] >= min && data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val && data->list[data->spliter - 1] >= min && data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[0] > data->val && data->list[0] >= min && data->list[0] < max)
			rraw_optimize(data, &i);
		if (data->list[0] > data->val && data->list[0] >= min && data->list[0] < max)
			rraw_optimize(data, &i);
	}
	print_state(data);
	if (data->relative == 1)
		data->lock_b = 0;
	else if (data->relative == 2)
		data->lock_b = 1;
	else if (data->relative == 3)
		data->lock_a = 1;
	else if (data->relative == 4)
		data->lock_a = 0;
	data->bool_first_move = 0;
	while(i < data->rotation)
	{
		if (data->direction > 0)
			rbw(data);
		else
			rrbw(data);
		i++;
	}
	data->last_relative = data->relative;
	paw(data);
}

void	execute_best_move_b(t_data *data) //combine up & down with the first operation
{
	int i;

	i = 0;
	if (!data->bool_first_move && data->last_relative < 0)
	{
		if (i < data->rotation && data->direction > 0)
		{
			rrw(data);
			i++;
		}
		else
			raw(data);
	}
	data->bool_first_move = 0;
	while(i < data->rotation)
	{
		if (data->direction > 0)
			rbw(data);
		else
			rrbw(data);
		i++;
	}
	data->last_relative = data->relative;
	paw(data);
}

void	insersion_sort_b(t_data *data, int min, int max)
{
	int i;

	i = data->spliter;
	data->bool_first_move = 1;
	data->lock_a = 0;
	data->lock_b = 0;
	data->too_small = 0;
	while (i < data->size)
	{
		find_farthest_pos_b(data);
		calculate_best_move2(data);
		execute_best_move_b2(data, min, max);
		i++;
	}
}

void	push_remainer_a_to_b(t_data *data, int pivot)
{
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	while (data->list[data->spliter - 1] >= pivot)
		pbw(data);
}

void	rotate_remainer(t_data *data, int pivot)
{
	while (data->list[data->spliter - 1] >= pivot)
		raw(data);
}

void	manage_half_on_b_sub_sublevel(t_data *data, int min, int max) //du minimum a la moitie
{
	int i;
	int pivot;
	int pivot_min;
	int pivot_max;
	(void)min;
	(void)max;

	i = data->spliter;
	pivot = median(data, data->spliter, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	while (i < data->size)
	{
		if (data->list[data->spliter] >= pivot)
			paw(data);
		else
			rbw(data);
		i++;
	}
	print_state(data);
	insersion_sort_b(data, pivot_min, pivot);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	print_state(data);
	while (data->list[data->spliter - 1] >= pivot && data->list[data->spliter - 1] <= max)
		pbw(data);
	insersion_sort_b(data, pivot, pivot_max);
}

void	manage_half_on_b_sublevel(t_data *data, int min, int max) //du minimum a la moitie
{
	int i;
	int pivot;
	int pivot_min;
	int pivot_max;
	(void)min;
	(void)max;

	i = data->spliter;
	pivot = median(data, data->spliter, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	while (i < data->size)
	{
		if (data->list[data->spliter] >= pivot)
			paw(data);
		else
			rbw(data);
		i++;
	}
	print_state(data);
	manage_half_on_b_sub_sublevel(data, pivot_min, pivot);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	print_state(data);
	while (data->list[data->spliter - 1] >= pivot && data->list[data->spliter - 1] <= max)
		pbw(data);
	manage_half_on_b_sub_sublevel(data, pivot, pivot_max);
}

void	manage_half_on_b(t_data *data, int min, int max) //du minimum a la moitie
{
	int i;
	int pivot;
	int pivot_min;
	int pivot_max;
	(void)min;
	(void)max;

	i = data->spliter;
	pivot = median(data, data->spliter, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	while (i < data->size)
	{
		if (data->list[data->spliter] >= pivot)
			paw(data);
		else
			rbw(data);
		i++;
	}
	print_state(data);
	manage_half_on_b_sublevel(data, pivot_min, pivot);
	print_state(data);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	print_state(data);
	while (data->list[data->spliter - 1] >= pivot && data->list[data->spliter - 1] <= max)
		pbw(data);
	manage_half_on_b_sublevel(data, pivot, pivot_max);
}


void	quick_sort_ultimate(t_data *data)
{
	int i;
	int pivot;
	int pivot_min;
	int pivot_max;

	i = 0;
	pivot = median(data, 0, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] < pivot)
			pbw(data);
		else
			raw(data);
		i++;
	}
	print_state(data);

	//insersion_sort_b(data, pivot_min, pivot);
	manage_half_on_b(data, pivot_min, pivot - 1);
	print_state(data);

	//push_remainer_a_to_b(data, pivot);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	while (data->list[data->spliter - 1] >= pivot)
		pbw(data);
	print_state(data);
	//insersion_sort_b(data, pivot, pivot_max);
	manage_half_on_b(data, pivot, pivot_max);

	print_state(data);
	rotate_remainer(data, pivot);
}

void	quick_sort(t_data *data)
{
	int i;
	int pivot;

	i = 0;
	pivot = median(data, 0, data->size);
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] < pivot)
			pbw(data);
		else
			raw(data);
		i++;
	}
	print_state(data);
	insersion_sort_b(data, data->pivot_min, pivot);
	print_state(data);
	push_remainer_a_to_b(data, pivot);
	print_state(data);
	insersion_sort_b(data, pivot, data->pivot_max);
	print_state(data);
	rotate_remainer(data, pivot);
}

void	sort_two_top_a(t_data *data)
{
	if (data->list[data->spliter - 1] > data->list[data->spliter - 2])
		saw(data);
}

void	sort_only_three(t_data *data)
{
	if (data->list[data->spliter - 1] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 2])
	{
		raw(data);
		saw(data);
		rraw(data);
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 3])
		saw(data);
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 2])
		rraw(data);
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 1])
		raw(data);
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 2] &&
	data->list[data->spliter - 2] < data->list[data->spliter - 1])
	{
		saw(data);
		rraw(data);
	}
}

void	push_min_three_b_to_a(t_data *data)
{
	if (data->list[data->spliter] > data->list[data->spliter + 1] &&
	data->list[data->spliter] > data->list[data->spliter + 2])
		paw(data);
	else if (data->list[data->spliter + 1] > data->list[data->spliter] &&
	data->list[data->spliter + 1] > data->list[data->spliter + 2])
	{
		rbw(data);
		paw(data);
	}
	else if (data->list[data->spliter + 2] > data->list[data->spliter] &&
	data->list[data->spliter + 2] > data->list[data->spliter + 1])
	{
		rrbw(data);
		paw(data);
	}
}

void	push_min_thwo_b_to_a(t_data *data)
{
	if (data->list[data->spliter] > data->list[data->spliter + 1])
		paw(data);
	else
	{
		rbw(data);
		paw(data);
	}
}

void	sort_four_five(t_data *data)
{
	int i;
	int pivot;

	i = 0;
	pivot = median(data, 0, data->size);
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] <= pivot)
			pbw(data);
		else
			raw(data);
		i++;
	}
	if (data->size == 5)
	{
		if (data->list[0] < data->list[1])
			raw(data);
	}
	push_min_three_b_to_a(data);
	push_min_thwo_b_to_a(data);
	paw(data);
}

void	sort(t_data *data)
{
	if (already_sorted(data))
		return ;
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sort_two_top_a(data);
	else if (data->size == 3)
		sort_only_three(data);
	else if (data->size < 6)
		sort_four_five(data);
	else if (data->size < 300)
		quick_sort(data);
	else
		quick_sort_ultimate(data);
}

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 0);
	return (0);
}

int main(int ac, char **av)
{
	int i;
	t_data data;
	char **tab;
	
	i = 0;
	data.error = 0;
	data.rrr = 0;
	if (ac == 1)
		return (0);
	data.spliter = ac - 1;
	data.size = ac - 1;
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
	if (!(data.list = malloc(sizeof(int) * data.size)))
		return (free_tab_print_error(ac, av, &tab));
	while (i > 0)
	{
		if (ac == 2)
		{
			data.list[data.spliter - i] = ft_atoi(tab[i - 1], &data);
			security_duplicates(&data, data.spliter - i);
		}
		else
		{
			data.list[ac - i - 1] = ft_atoi(av[i], &data);
			security_duplicates(&data, ac - i - 1);
		}
		if (data.error == 1)
			return(ft_free_print_error(&data, ac, av, &tab));
		i--;
	}
	print_state(&data);
	sort(&data);
	print_state(&data);
	free(data.list);
	if (ac == 2)
		ft_free(tab, ft_nbr_str(av[1], ' '));
	return (0);
}
