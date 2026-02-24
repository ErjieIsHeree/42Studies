#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_garden_summary.py                                 :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/19 12:26:47 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:06:38 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def ft_garden_summary() -> None:
    garden_name: str = input("Enter garden name: ")
    n_plants: str = input("Enter number of plants: ")
    print(f"Garden: {garden_name}")
    print(f"Plants: {n_plants}")
    print("Status: Growing well!")
