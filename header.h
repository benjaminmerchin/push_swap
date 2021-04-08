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
# define ALWAYS_PRINT 0

typedef	struct	s_data {
	int		*list; // la liste qui contiens les variables a trier
	int		spliter; // la limite sur la liste ou on change de pile
	int		size; // taille de la liste, egal a spliter initialement
	char	buff[4]; // pour ranger les instruction du checker
	int		error; // si une entree d'instructions est fausse
	int		instuctions; //nombre d'instructions
	int		rrr; //si on mutualise les rotations

	int		pivot; //le pivot pour insertion sort
	int		rotation; //nombre de rotations a faire pour remonter le bon chiffre a push
	int		direction; //direction de la rotation a faire //1 ou -1
	int		moving; //direction du dernier mouvement
	int		relative; //position par rapport au pivot
	int		last_relative; //ancien data->relative
	int		relative_up; //position par rapport au pivot
	int		relative_down; //position par rapport au pivot
	int		pivot_max; //valeur max dans la range du pivot
	int		pivot_min; //valeur mun pour la range du pivot
	int		too_small; //si la liste restante est plus petite que 4

	int	above_pos;
	int	a_pos;
	int	above_val;
	int	a_val;
	int	equal_pos;
	int	bellow_pos;
	int	b_pos;
	int	bellow_val;
	int	b_val;

	int		lock_a;
	int		lock_b;
	int		val; //valeur de ce qu'on bouge


	int		bool_first_move;
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


#endif
