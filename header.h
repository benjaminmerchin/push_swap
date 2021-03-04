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
	int *list; // la liste qui contiens les variables a trier
	int spliter; // la limite sur la liste ou on change de pile
	int size; // taille de la liste, egal a spliter initialement
	char buff[4]; // pour ranger les instruction du checker
}				t_data;

void			sa(t_data *data);
void			sb(t_data *data);

void			ft_putchar(char c);
int				ft_strlen(char *s);
void			ft_putnbr(int n);
int				ft_atoi(const char *str);
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_putstr_fd(char *s, int fd);

#endif
