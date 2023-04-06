/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:55:14 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/05 23:54:19 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_list(int *array, int size)
{
	t_node	*head;
	t_node	*current;
	t_node	*previous;
	int		i;

	head = NULL;
	current = NULL;
	previous = NULL;
	i = 0;
	while (i < size)
	{
		current = (t_node *)malloc(sizeof(t_node));
		current->content = array[i];
		current->next = NULL;
		if (previous)
			previous->next = current;
		else
			head = current;
		previous = current;
		i++;
	}
	current->next = NULL;
	return (head);
}

int	run_programme(int argc, char **argv)
{
	t_node	run;
	t_node	*head;
	t_node	*current;
	t_node	*tmp;

	run.size = argc - 1;
	run.array = (int *)malloc(run.size * sizeof(int));
	run.i = 0;
	while (run.i < run.size)
	{
		run.array[run.i] = ft_atoi(argv[run.i + 1]);
		run.i++;
	}
	head = init_list(run.array, run.size);
	free(run.array);
	current = head;
	tmp = NULL;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	return (0);
}

void	print_list(t_node *list)
{
	t_node	*current;

	current = list;
	while (current->next != list)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("%d\n", current->content);
}
