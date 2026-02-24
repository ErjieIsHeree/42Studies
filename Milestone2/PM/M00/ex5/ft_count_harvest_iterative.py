#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_count_harvest_iterative.py                        :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/18 18:54:26 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:49:18 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def ft_count_harvest_iterative() -> None:
    for num in range(int(input("Days until harvest: "))):
        print(f"Day {num + 1}")
    print("Harvest time!")
