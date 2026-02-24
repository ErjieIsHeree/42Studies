#!/usr/bin/env python3
# ########################################################################### #
#                                                                             #
#                                                          :::      ::::::::  #
#   ft_plant_growth.py                                   :+:      :+:    :+:  #
#                                                      +:+ +:+         +:+    #
#   By: exia <exia@student.42madrid.com>             +#+  +:+       +#+       #
#                                                  +#+#+#+#+#+   +#+          #
#   Created: 2026/02/20 12:47:47 by exia                #+#    #+#            #
#   Updated: 2026/02/20 13:00:41 by exia               ###   ########.fr      #
#                                                                             #
# ########################################################################### #

class Plant():
    """A blueprint for creating a plant"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Use this function to remake the plant"""
        self.name = name
        self.height = height
        self.age = age

    def grow(self, height: int) -> None:
        """This function adds more heigth to the actual plant"""
        self.height += height
