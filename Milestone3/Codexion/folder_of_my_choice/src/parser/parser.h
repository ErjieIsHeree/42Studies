/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exia <exia@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:18:17 by erjieishere       #+#    #+#             */
/*   Updated: 2026/05/28 11:38:00 by exia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../codexion_types.h"
# include <limits.h>
# include <stdlib.h>
# include <string.h>

int	parse_data(int argc, char **argv, t_sim *sim);

#endif
