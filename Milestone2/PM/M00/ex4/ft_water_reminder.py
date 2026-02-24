#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_water_reminder.py                                 :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/18 18:52:16 by exia                #+#    #+#            #
#   Updated: 2026/02/19 13:48:03 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

def ft_water_reminder() -> None:
    if int(input("Days since last watering: ")) > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
