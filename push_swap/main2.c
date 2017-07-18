/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:36:12 by niludwig          #+#    #+#             */
/*   Updated: 2017/07/18 05:23:03 by niludwig         ###   ########.fr       */
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
	if (nb == '0' || nb == '1' || nb == '2' || nb == '3' || nb == '4'
		|| nb == '5' || nb == '6' || nb == '7' || nb == '8' || nb == '9')
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
		if (av[i] == ' ' || ft_isdigity(av[i]) == 1)
			++i;
		else if (av[i] == '-' && (i == 0 || av[i - 1] == ' '))
			++i;
		else
			exit_message("yolo\n");
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
	info->space = 0;
	while (av[info->nb] != ' ')
	{
		info->nb -= 1;
		info->space += 1;
	}
	info->nb += 1;
	ft_lstadd_back(&tmp, ft_lstnew(get_last(av + info->nb, info->space),
		sizeof(t_list)));
	return (tmp);
}

t_list		*get_all_args(char **av, t_info *info)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while	(++i && av[i])
	{
		if (norme_of_args(av[i], info) != 0)
			return (NULL);
	}
	i = 0;
	while	(++i && av[i])
	{
		if (no_space(av[i]) == 1)
			ft_lstadd_back(&lst, ft_lstnew(av[i], sizeof(t_list)));
		else
			lst = get_chain(av[i], lst, info);
	}
	return (lst);
}

int			check_lst(t_list *lst, char *u)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (ft_strcmp(u, tmp->content) == 0)
			exit_message("erroro\n");
	}
	lst = lst->next;
	if (lst->next == NULL)
		return (1);
	else
		check_lst(lst, lst->content);
	return (1);
}

t_list *get_next(void)
{
	t_list	*tmp;
	char *buff;

	tmp = NULL;
	while (get_next_line(0, &buff) > 0)
	{
		//petit message pour moi meme, transformer en brute les instruction, puit cree un tableau de pointeur sur fonction qui appliquera a chaque fonction la bonne instruction
		if (ft_strncmp(buff, "sa", 2) == 0)//- intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "sb", 2) == 0)// intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "ss", 2) == 0)//sa et sb en même temps
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "pa", 2) == 0)// prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "pb", 2) == 0)//prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "rr", 2) == 0)//ra et rb en même temps.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "ra", 2) == 0)//décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "rb", 2) == 0)//décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "rra", 3) == 0)//décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "rrb", 3) == 0)//décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else if (ft_strncmp(buff, "rrr", 2) == 0)//rra et rrb en même temps.
			ft_lstadd_back(&tmp, ft_lstnew(buff,  sizeof(t_list)));
		else
			exit_message("yolo\n");
		free(buff);
	}
	return (tmp);
}

int			main(int ac, char **av)
{
	t_info	*info;
	t_list	*lst;
	t_list	*inst;

	info = ft_memalloc(sizeof(t_info));
	lst = NULL;
	inst = NULL;
	if (ac < 2)
		exit_message("error\n");
	if (!(lst = get_all_args(av, info)))
		exit_message("erroru\n");
	check_lst(lst, lst->content);
/*	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}*/
	inst = get_next();//cree un fichier instruction init tab instru .h
	return (0);
}
