/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:10:38 by exia              #+#    #+#             */
/*   Updated: 2026/02/12 11:18:28 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main_protections(int argc, char **argv)
{
	int		i;
	int		numeric_found;
	char	*s;

	if (!argv[1] || argv[1][0] == '\0')
		return (1);
	numeric_found = 0;
	i = 1;
	while (i < argc)
	{
		s = argv[i];
		if (s && s[0] != '\0')
		{
			if ((s[0] >= '0' && s[0] <= '9')
				|| (s[0] == '-' && s[1] && s[1] >= '0' && s[1] <= '9'))
			{
				numeric_found = 1;
				break ;
			}
		}
		i++;
	}
	if (!numeric_found)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_bench	*bench;

	if (argc == 1)
		return (0);
	if (argc <= 3 && main_protections(argc, argv))
		return (fatal_error(), 1);
	stack_a = NULL;
	bench = ft_calloc(sizeof(t_bench), 1);
	if (!bench)
		return (fatal_error(), 1);
	if (check(argv, &stack_a, &bench))
		return (free_stack(&stack_a), free(bench), fatal_error(), 1);
	if (!execute_alg(&bench, &stack_a))
		return (free_stack(&stack_a), free(bench), fatal_error(), 1);
	if (bench->use_bench)
		print_bench(&bench);
	free(bench);
	free_stack(&stack_a);
	return (0);
}
