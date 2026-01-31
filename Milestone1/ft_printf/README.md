*This project was created as part of the curriculum of 42 by exia*

# ft_printf

___

## Description

The next project is about a very famous and useful function in C: **printf_f**. This project will help a lot on improving the programation logic and learn about the variatic functions. 

The difficult of this project is moderated.
___

### Instructions

This project has a `Makefile` which makes easier the creation of the lib of this project. The targets callable are the next:

| Target                           | Action                                                                                                                      |
| -------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `make` / `all` / `libftprintf.a` | To create the library libftprintf.a (it also creates a .o of each function)                                                 |
| `clean`                          | Clean all filles .o                                                                                                         |
| `fclean`                         | Clean all files .o and .a                                                                                                   |
| `re`                             | Re delete and recreate libft.a                                                                                              |
| `test`                           | This function compiles all files plus a *test.c* file. (This extra file is used for testing purposes. Add a main into test. |

>Must type make before each target except for make.
___

### Resources

- [Printf guide](https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html)
- [Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [Base conversion](https://www.rapidtables.com/convert/number/decimal-to-hex.html?x=1234)

___

### Algorithm and data structure description

This excercise is very simple to create. In order to do so, understanding how printf is the key of it.
>Also knowledge about *variadic parameters* will be requiered.

- It prints the hole string sent to it.
- For each `%(rule)` in the string, the printf will instead print the variadic parameter. (If there are more than one, these will be printed in order)
- The original function have many more rules, but this mini version of it have the next ones:

| Rules   | Description                                  |
| ------- | -------------------------------------------- |
| ***c*** | Prints a `character`.                        |
| ***s*** | Prints a `C-string`.                         |
| ***p*** | Prints a `pointer in hexadecimal` format.    |
| ***d*** | Prints a `decimal number`.                   |
| ***i*** | Prints a `decimal number`.                   |
| ***u*** | Prints a `decimal number without sign`.      |
| ***x*** | Prints a number in `low case hexadecimal`.   |
| ***X*** | Prints a number in `upper case hexadecimal`. |
| ***%*** | Prints a `p`.                                |

>If % is used with any other character or itself alone, printf will print it as a normal part of the string.

Understanding this, we can easily make the algorithm:

1. Read & write each character one by one.
2. If a % character is found and it is followed by another character, the corresponding case will be evaluated and the required change will be applied. 
