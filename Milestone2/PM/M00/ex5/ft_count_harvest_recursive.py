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

def ft_count_harvest_recursive(i=1, day=None) -> None:
    if day is None:
        day = int(input("Days until harvest: "))
    if i <= day:
        print(f"Day {i}")
        ft_count_harvest_recursive(i + 1, day)
    else:
        print("Harvest time!")
