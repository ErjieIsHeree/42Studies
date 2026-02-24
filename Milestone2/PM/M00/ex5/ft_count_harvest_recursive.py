#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_count_harvest_recursive.py                        :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/18 19:00:25 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:51:37 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def __recursive_print_day(days: int) -> None:
    if days != 1:
        __recursive_print_day(days - 1)
    print(f"Day {days}")


def ft_count_harvest_recursive() -> None:
    print("Days until harvest: ", end="")
    __recursive_print_day(int(input()))
    print("Harvest time!")
