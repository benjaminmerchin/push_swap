/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:44:09 by bmerchin          #+#    #+#             */
/*   Updated: 2021/03/03 16:44:10 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define PRINT 0

typedef	struct	s_data {
	int		*list;
	int		spliter;
	int		size;
	char	buff[4];
	int		error;
	int		instuctions;
	int		rrr;
	int		aaa;

	int		pivot;
	int		rotation;
	int		direction;
	int		moving;
	int		relative;
	int		last_relative;
	int		relative_up;
	int		relative_down;
	int		pivot_max;
	int		pivot_min;
	int		too_small;

	int		above_pos;
	int		a_pos;
	int		above_val;
	int		a_val;
	int		equal_pos;
	int		bellow_pos;
	int		b_pos;
	int		bellow_val;
	int		b_val;

	int		lock_a;
	int		lock_b;
	int		val;
	int		bool_first_move;

	int		print;
	int		show_number;
	int		fancy;
	int		color;
	int		ac;
}				t_data;

void			sa(t_data *data);
void			sb(t_data *data);
void			ss(t_data *data);
void			pa(t_data *data);
void			pb(t_data *data);
void			ra(t_data *data);
void			rb(t_data *data);
void			rr(t_data *data);
void			rra(t_data *data);
void			rrb(t_data *data);
void			rrr(t_data *data);

void			saw(t_data *data);
void			sbw(t_data *data);
void			ssw(t_data *data);
void			paw(t_data *data);
void			pbw(t_data *data);
void			raw(t_data *data);
void			rbw(t_data *data);
void			rrw(t_data *data);
void			rraw(t_data *data);
void			rrbw(t_data *data);
void			rrrw(t_data *data);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_strlen(char *s);
void			ft_putnbr(int n);
int				ft_atoi(const char *str, t_data *data);
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
char			**ft_split(char const *s, char c);
char			**ft_free(char **tab, int nbr);
int				ft_nbr_str(char *s, char c);
int				ft_free_print_error(t_data *data, int ac, char **av, char ***tab);
void			security_duplicates(t_data *data, int i);
int				already_sorted(t_data *data);
int				free_tab_print_error(int ac, char **av, char ***tab);

void			print_state(t_data *data);
int				median(t_data *data, int begin, int end);

void			push_min_three_b_to_a(t_data *data);
void			push_min_thwo_b_to_a(t_data *data);
void			sort_two_top_a(t_data *data);
void			sort_only_three(t_data *data);
void			sort_four_five(t_data *data);

int				ft_error(void);
void			push_remainer_a_to_b(t_data *data, int pivot);
void			rotate_remainer(t_data *data, int pivot);
void			raw_optimize(t_data *data, int *i);
void			rraw_optimize(t_data *data, int *i);

void			execute_instruction_checker(t_data *data);

void			push_half_b(t_data *data, int pivot);
void			push_half_a(t_data *data, int pivot);
void			initialize_main(t_data *data, int ac);

void			insersion_sort_b(t_data *data, int min, int max);
void			manage_half_on_b_sub_sublevel(t_data *data, int min, int max);
void			manage_half_on_b_sublevel(t_data *data, int min, int max);
void			manage_half_on_b(t_data *data, int min, int max);

void			find_farthest_pos_b(t_data *data);
void			calculate_best_move(t_data *data);
void			execute_best_move_b(t_data *data, int min, int max);

void			manage_bonus(t_data *data, int *ac, char ***av);
void			print_state_fancy(t_data *data);

#endif
