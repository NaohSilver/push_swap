/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 05:20:55 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/11 07:02:57 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_good_arg(char *lst, t_info *info)
{
	int		i;

	i = 0;
	info->nb = ft_strlen(lst);
	while (i != (info->nb - 1))
	{
		if ((lst[i] <= '9' && lst[i] >= '0') || lst[i] == '-')
		{
			++i;
			info->space += 1;
		}
		else if (lst[i] == ' ')
		{
			if (lst[i - 1] == '-')
				info->nob -= 1;
			info->nob += 1;
			++i;
		}
		else if (ft_is_white_space(lst[i]) == 1)
			exit_message("Error\n");
		else
			exit_message("Error\n");
	}
	info->nob += 1;
	return (0);
}

int			check_last(char *av)
{
	int		i;

	i = 0;
	while (i != ft_strlen(av))
	{
		if (av[i] > '9' || av[i] < '0')
		{
			if (av[i] == ' ' || av[i] == '-')
				++i;
			else
				return (1);
		}
		++i;
	}
	return (0);
}

int			no_space(char *str)
{
	int		i;

	i = 0;
	while(i <= ft_strlen(str))
	{
		if (str[i] == ' ')
			return (0);
		++i;
	}
	return (1);
}

t_list		*get_chain(char *av, t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		u;

	i = 0;
	u = 0;
	tmp = lst;
	while (i != ft_strlen(av))
	{
		if (av[i] == ' ' || !av[i])
		{
			ft_lstadd_back(&tmp, ft_lstnew(ft_return_nb(av + u, i - u), sizeof(t_list)));
			u = i;
			if (av[u] == ' ')
				u++;
		}
		i++;
	}
	while (av[i] != ' ')
		i--;
	i++;
	return (tmp);
}

int			get_all_arg(char **av, t_info *info)
{
	t_list	*lst;
	int		i;

	i = 0;
	set_info(info, lst);
	while (++i && av[i])
	{
		if (get_good_arg(av[i], info) != 0)
			return (1);
		else if (ft_strlen(av[i]) == 1 && ft_isdigit((int)av[i]) != 1)
			exit_message("Error\n");
		else if (check_last(av[i]) == 1)
			exit_message("Error\n");
	}
	i = 0;
	while (++i && av[i])
	{
		if (no_space(av[i]) == 1)
			ft_lstadd_back(&lst, ft_lstnew(av[i], sizeof(t_list)));
		else
			lst = get_chain(av[i], lst);
	}
	while (lst->next)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}
