#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_plant_age.py                                      :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/18 18:37:00 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:45:10 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def ft_plant_age() -> None:
    age: int = int(input("Enter plant age in days: "))
    if age > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
