/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 02:27:42 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/11 12:28:56 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*order_array(int *array, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	*temp_array(t_stack **stack_a, int *array)
{
	int		*array_head;
	t_stack	*temp;

	array_head = array;
	temp = *stack_a;
	while (temp)
	{
		*array = temp->value;
		array++;
		temp = temp->next;
	}
	return (array_head);
}

int	ft_numlen(const int *id)
{
	int	i;

	i = 0;
	while (*id)
	{
		i++;
		id++;
	}
	return (i);
}

void	index_list(t_stack **stack_a, int *array, int count)
{
	int		i;
	t_stack	*temp_l;
	t_stack	*temp_l2;

	temp_l = *stack_a;
	temp_l2 = *stack_a;
	i = 0;
	while (count)
	{
		while (temp_l->value != *array)
		{
			temp_l = temp_l->next;
		}
		temp_l->index = i;
		i++;
		count--;
		array++;
		temp_l = temp_l2;
	}
}

int	*normalize_list(t_stack **stack_a)
{
	int		count;
	int		*array;
	t_stack	*temp_l;

	temp_l = *stack_a;
	count = ft_lstsize_u(temp_l);
	array = ft_calloc(sizeof(int), count);
	array = temp_array(stack_a, array);
	array = order_array(array, count);
	index_list(stack_a, array, count);
	return (array);
}
