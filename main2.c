/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:36:12 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/12 20:01:58 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		exit_message(char *str)
{
	ft_putstr(str);
	exit (1);
}

int			ft_isdigity(char nb)
{
	if (nb == '0' || nb <= '1' || nb == '2' || nb <= '3' || nb == '4'
		|| nb <= '5' || nb == '6' || nb <= '7' || nb == '8' || nb <= '9')
		return (1);
	else
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

int			norme_of_args(char *av, t_info *info)
{
	int i;

	i = 0;
	info->nb = ft_strlen(av);
	while (i != info->nb)
	{
		if (ft_isdigity(av[i]) != 1)
		{
			if (av[i] == ' ')
				i++;
			else if (av[i] == '-' && ft_isdigity(av[i + 1]) == 1)
			{
				i--;
				if (av[i] == ' ' || i < 0)
					i += 2;
				else
					return (1);
			}
			else
				return (1);
		}
		++i;
	}
	info->nb = 0;
	return (0);
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

t_list		*get_chain(char *av, t_list *lst, t_info *info)
{
	t_list	*tmp;

	tmp = lst;
	while (info->nb != ft_strlen(av))
	{
		if (av[info->nb] == ' ' || !av[info->nb])
		{
			ft_lstadd_back(&tmp, ft_lstnew(ft_return_nb(av + info->space,
				info->nb - info->space), sizeof(t_list)));
			info->space = info->nb;
			if (av[info->space] == ' ')
				info->space += 1;
		}
		info->nb += 1;
	}
	return (tmp);
}

int			check_one(char *str)
{
	int i;
	int u;

	i = 0;
	u = ft_strlen(str);
	if (str[i] == '-' || ft_isdigity(str[i]) == 1)
	while (i <= u)
	{
		i++;
	}
}

t_list		*get_all_args(char **av, t_info *info)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while	(++i && av[i])
	{
		if (no_space(av[i]) == 1)
			check_one(av[i]);
		else if (norme_of_args(av[i], info) != 0)
			return (NULL);
	}
	i = 0;
	while	(++i && i <= info->nob)
	{
		if (no_space(av[i]) == 1)
			ft_lstadd_back(&lst, ft_lstnew(av[i], sizeof(t_list)));
	}
	return (lst);
}

void		set_info(t_info *info)
{
	info->space = 0;
	info->nb = 0;
	info->nob = 0;
}

int			main(int ac, char **av)
{
	t_info	*info;
	t_list	*lst;

	info = ft_memalloc(sizeof(t_info));
	set_info(info);
	lst = NULL;
	if (ac < 2)
		exit_message("error\n");
	if (!(lst = get_all_args(av, info)))
		exit_message("error\n");
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}
