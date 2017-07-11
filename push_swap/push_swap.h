/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:12:46 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/11 07:01:09 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"

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
void			set_info(t_info *info, t_list *lst);
int				get_good_arg(char *lst, t_info *info);
int				ft_is_white_space(char str);
void			exit_message(char *str);
t_list			*get_chain(char *av, t_list *lst);
char			*ft_return_nb(char *str, int size);

#endif
