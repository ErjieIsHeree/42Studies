#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_plot_area.py                                      :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/18 11:25:26 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:45:20 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def ft_plot_area() -> None:
    length: int = int(input("Enter length: "))
    width: int = int(input("Enter width: "))
    print(f"Plot area: {width * length}")
