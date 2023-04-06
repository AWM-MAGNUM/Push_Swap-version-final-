/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:56:15 by bel-kase          #+#    #+#             */
/*   Updated: 2023/04/06 00:46:36 by bel-kase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	ft_func_to_sort(t_node *pile_a)
{
	t_node		*pile_b;

	pile_b = NULL;
	if (ft_lstsize(pile_a) == 3)
	{
		sort_three_num(&pile_a);
		exit(1);
	}
	else if (ft_lstsize(pile_a) == 4)
	{
		sort_four_num(&pile_a, &pile_b);
		exit(1);
	}
	else if (ft_lstsize(pile_a) == 5)
	{
		sort_five_elm(&pile_a, &pile_b);
		exit(0);
	}
}

void	bubble_sort(int *arr, int size)
{
	int	temp;
	int	swapped;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		i++;
		if (swapped == 0)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_node		*pile_a;
	t_node		*pile_b;
	t_node		main;

	main.o = 0;
	main.z = 0;
	if (argc < 2)
		exit(1);
	ft_range_value_int(argv, argc);
	run_programme(argc, argv);
	pile_a = NULL;
	pile_b = NULL;
	main.p = argc - 1;
	while (main.p > 0)
		ft_my_push(&pile_a, ft_atoi(argv[main.p--]));
	main.arr = (int *)malloc(sizeof(int) * (argc - 1));
	while (++main.z < argc)
		main.arr[main.o++] = ft_atoi(argv[main.z]);
	bubble_sort(main.arr, argc - 1);
	array_to_index_dlist(&pile_a, main.arr, argc - 1);
	if (argc <= 6)
		ft_func_to_sort(pile_a);
	radix(&pile_a, &pile_b);
	return (0);
}
