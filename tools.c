/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 05:22:31 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/11 06:53:03 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	if (!(*alst))
		*alst = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

void		exit_message(char *str)
{
	ft_putstr(str);
	exit (1);
}

int	ft_is_white_space(char str)
{
	if (str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r')
		return (1);
	else
		return (0);
}

void	set_info(t_info *info, t_list *lst)
{
	info->space = 0;
	info->nob = 0;
	lst->content = NULL;
}

char *ft_return_nb(char *str, int size)
{
	char *tmp;
	int i;

	i = 0;
	tmp = ft_memalloc(size);
	while (i != size)
	{
		tmp[i] = *str;
		++i;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}
