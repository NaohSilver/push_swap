/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:26:42 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:45:14 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charcmp(char c, char *arg)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (arg[i])
	{
		if (arg[i] == c)
		{
			v = 1;
			break ;
		}
		i++;
	}
	return (v);
}