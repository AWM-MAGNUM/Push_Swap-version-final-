/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:47:03 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/04 01:47:06 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *pile)
{
	t_node	*tmp;

	ft_printf("Les éléments de la pile sont :\n");
	tmp = pile;
	while (pile != NULL)
	{
		ft_printf("%d\n", pile->value);
		pile = pile->next;
	}
	pile = tmp;
}

void	ft_my_push(t_node **pile, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->value = value;
	new_node->next = *pile;
	*pile = new_node;
}

void	array_to_index_dlist(t_node **stack, int *array, int size)
{
	t_node	*tmp;
	int		j;

	tmp = *stack;
	while (tmp)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] == tmp->value)
			{
				tmp->index = j;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
	return ;
}

int	max_index_position(t_node **pile_a)
{
	t_node	*current;
	int		max_index;

	current = *pile_a;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	max_bit_position(int max_bits)
{
	int	max;

	max = 0;
	while (max_bits > 0)
	{
		max_bits /= 2;
		max++;
	}
	return (max - 1);
}
