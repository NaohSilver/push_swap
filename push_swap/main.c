/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:12:34 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/11 05:31:46 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
