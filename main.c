/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:12:34 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/11 08:39:12 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*get_last(char *str, int size)
{
	int u;
	char *tmp;

	tmp = ft_memalloc(size);
	u = 0;
	while(u != size)
	{
		tmp[u] = *str;
		++u;
		str++;
	}
	tmp[u] = '\0';
	return (tmp);
}

int			main(int ac, char **av)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		exit_message("failed to allocate memories\n");
	if (ac < 2)
		exit_message("Error\n");
	if (get_all_arg(av, info) != 0)
		exit_message("Error\n");
	return (0);
}
