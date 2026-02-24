#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_harvest_total.py                                  :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/18 18:02:51 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:44:22 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def ft_harvest_total() -> None:
    day1: int = int(input("Day 1 harvest: "))
    day2: int = int(input("Day 2 harvest: "))
    day3: int = int(input("Day 3 harvest: "))
    print(f"Total harvest: {day1 + day2 + day3}")
