#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_garden_data.py                                    :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/20 12:47:17 by exia                #+#    #+#            #
#   Updated: 2026/02/20 12:53:11 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

class Plant():
    """A blueprint for creating a plant"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Use this function to remake the plant"""
        self.name = name
        self.height = height
        self.age = age


plant_l = [
            Plant(age=30, height=25, name="Rose"),
            Plant("Sunflower", 80, 45),
            Plant("Cactus", 15, 120)
           ]


print("=== Garden PLant Registry ===")
for plant in plant_l:
    print(f"{plant.name}: {plant.height}cm, {plant.age} days old")
