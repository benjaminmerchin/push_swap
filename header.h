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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_data {
	int		*list; // la liste qui contiens les variables a trier
	int		spliter; // la limite sur la liste ou on change de pile
	int		size; // taille de la liste, egal a spliter initialement
	char	buff[4]; // pour ranger les instruction du checker
	int		error_instruc; // si une entree d'instructions est fausse
	int		counter; //nombre d'instructions

	int		pivot; //le pivot pour insertion sort
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

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_strlen(char *s);
void			ft_putnbr(int n);
int				ft_atoi(const char *str);
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);

void			print_state(t_data *data);

#endif
