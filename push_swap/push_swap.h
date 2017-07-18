/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:12:46 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/18 05:08:49 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"

typedef struct	s_info
{
	int			nb;
	int			nob;
	int			space;
}				t_info;

void			ft_lstadd_back(t_list **alst, t_list *new);
int				get_all_arg(char **av, t_info *info);
int				no_space(char *str);
int				check_last(char *av);
void			set_info(t_info *info);
int				get_good_arg(char *lst, t_info *info);
int				ft_is_white_space(char str);
void			exit_message(char *str);
t_list			*get_chain(char *av, t_list *lst, t_info *info);
char			*ft_return_nb(char *str, int size);
char			*get_last(char *str, int ptr);
void			check_double(t_list *lst, char *u, t_list *origine);

#endif
