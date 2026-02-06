/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-s <smarin-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:18:46 by smarin-s          #+#    #+#             */
/*   Updated: 2026/02/06 18:46:16 by smarin-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	recognize_number(char **argv, int i, t_list **head)
// {
// 	t_list *tail;
// 	t_list *node;

// 	tail = NULL;
// 	while(argv[i])
// 	{
// 		node = ft_lstnew(ft_atoi(argv[i]));
// 		if (!node)
// 			return ;
// 		if (!*head)
// 			*head = node;
// 		else
// 			tail->next = node;
// 		tail = node;
// 		i++;
// 	}
// 	return ;
// }


t_list	*parse_args(int argc, char **argv, t_bench *bench, t_list *stack_a)
{
	// int	bstrat;
	// int	arg_id;

	// bstrat = 0;
	// arg_id = 0;
	(void)argc;
	(void)argv;
	(void)bench;
	(void)stack_a;
	// if (recognize_flags(argv, ++arg_id, &bstrat) != -1)
	// {
	// 	if(recognize_flags(argv, ++arg_id, &bstrat) != -1)
	// 		recognize_flags(argv, ++arg_id, &bstrat);
	// }
	// printf("Stack:");
    // while (stack_a)
    // {
    //     printf("%d -> ", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    // printf("NULL\n");
	return (stack_a);
}
