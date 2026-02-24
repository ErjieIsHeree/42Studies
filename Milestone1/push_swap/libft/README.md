*This project was created as part of the curriculum of 42 by exia.*

# LIBFT

___

## Description

This project involves creating a C library that will contain a series of general-purpose functions.
___

### Instructions

This project uses the `makefile` targets to create, compile, clean...

| Targets                    | Use case                                                                                                                      |
| -------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| `make` / `all` / `libft.a` | To create the library libft.a (it also creates a .o of each function)                                                         |
| `clean`                    | Clean all filles .o                                                                                                           |
| `fclean`                   | Clean all files .o and .a                                                                                                     |
| `re`                       | Re delete and recreate libft.a                                                                                                |
| `test`                     | This function compiles all files plus a *test.c* file. (This extra file is used for testing purposes. Add a main into test.c) |

>Must type make before each target except for make.
___

### Resources

All the webs, docs... used to create this library.

- [Linux manual pages](https://linux.die.net/man/)
- [W3 Schools (For C syntax)](https://www.w3schools.com/)
- [Stackoverflow](https://stackoverflow.com/questions)
- [Markdown Guide](https://www.markdownguide.org/cheat-sheet/)
- [Makefile Guide](https://makefiletutorial.com/)

El uso de la IA tuvo lugar en una sola situación. En la creación de la tabla en la parte inferior de este fichero markdown. Enviándole el PDF del proyecto y el prompt adecuado, la IA ha creado la tabla esperada.

>Many more were used, but these are the main and that I remember rn.
___

### Detailed description

Each function was created following a given description by either 42 docs or linux docs.

| Function              | Description                                                                                                                                                                                                                                  |
| --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ***ft_isalpha***      | [link](https://linux.die.net/man/3/isalpha)                                                                                                                                                                                                  |
| ***ft_isdigit***      | [link](https://linux.die.net/man/3/isdigit)                                                                                                                                                                                                  |
| ***ft_isalnum***      | [link](https://linux.die.net/man/3/isalnum)                                                                                                                                                                                                  |
| ***ft_isascii***      | [link](https://linux.die.net/man/3/isascii)                                                                                                                                                                                                  |
| ***ft_isprint***      | [link](https://linux.die.net/man/3/isprint)                                                                                                                                                                                                  |
| ***ft_strlen***       | [link](https://linux.die.net/man/3/strlen)                                                                                                                                                                                                   |
| ***ft_memset***       | [link](https://linux.die.net/man/3/memset)                                                                                                                                                                                                   |
| ***ft_bzero***        | [link](https://linux.die.net/man/3/bzero)                                                                                                                                                                                                    |
| ***ft_memcpy***       | [link](https://linux.die.net/man/3/memcpy)                                                                                                                                                                                                   |
| ***ft_memmove***      | [link](https://linux.die.net/man/3/memmove)                                                                                                                                                                                                  |
| ***ft_strlcpy***      | [link](https://linux.die.net/man/3/strlcpy)                                                                                                                                                                                                  |
| ***ft_strlcat***      | [link](https://linux.die.net/man/3/strlcat)                                                                                                                                                                                                  |
| ***ft_toupper***      | [link](https://linux.die.net/man/3/toupper)                                                                                                                                                                                                  |
| ***ft_tolower***      | [link](https://linux.die.net/man/3/tolower)                                                                                                                                                                                                  |
| ***ft_strchr***       | [link](https://linux.die.net/man/3/strchr)                                                                                                                                                                                                   |
| ***ft_strrchr***      | [link](https://linux.die.net/man/3/strrchr)                                                                                                                                                                                                  |
| ***ft_strncmp***      | [link](https://linux.die.net/man/3/strncmp)                                                                                                                                                                                                  |
| ***ft_memchr***       | [link](https://linux.die.net/man/3/memchr)                                                                                                                                                                                                   |
| ***ft_memcmp***       | [link](https://linux.die.net/man/3/memcmp)                                                                                                                                                                                                   |
| ***ft_strnstr***      | [link](https://linux.die.net/man/3/strnstr)                                                                                                                                                                                                  |
| ***ft_atoi***         | [link](https://linux.die.net/man/3/atoi)                                                                                                                                                                                                     |
| ***ft_calloc***       | [link](https://linux.die.net/man/3/calloc)                                                                                                                                                                                                   |
| ***ft_strdup***       | [link](https://linux.die.net/man/3/strdup)                                                                                                                                                                                                   |
| ***ft_substr***       | Allocates (with malloc) and returns a substring from string ’s’. The substring begins at index ‘start’ and has a maximum length ‘len’.                                                                                                       |
| ***ft_strjoin***      | Allocates (with malloc) and returns a new string, result of the concatenation of ‘s1’ and ‘s2’.                                                                                                                                              |
| ***ft_strtrim***      | Allocates (with malloc) and returns a copy of ‘s1’ with characters in ‘set’ removed from the beginning and end.                                                                                                                              |
| ***ft_split***        | Allocates (with malloc) and returns an array of strings obtained by splitting ‘s’ using the delimiter character ‘c’; array ends with a NULL pointer.                                                                                         |
| ***ft_itoa***         | Allocates (with malloc) and returns the string representing the integer ‘n’; handles negative numbers.                                                                                                                                       |
| ***ft_strmapi***      | Allocates (with malloc) and returns a new string resulting from applying function ‘f’ to each character of ‘s’, passing the index then the character.                                                                                        |
| ***ft_striteri***     | Applies function ‘f’ to each character of string ‘s’, passing index and address of the character; does not return a value.                                                                                                                   |
| ***ft_putchar_fd***   | Writes character ‘c’ to the given file descriptor.                                                                                                                                                                                           |
| ***ft_putstr_fd***    | Writes string ‘s’ to the given file descriptor.                                                                                                                                                                                              |
| ***ft_putendl_fd***   | Writes string ‘s’ to the given file descriptor followed by a newline.                                                                                                                                                                        |
| ***ft_putnbr_fd***    | Writes integer ‘n’ to the given file descriptor.                                                                                                                                                                                             |
| ***ft_lstnew***       | Allocates (with malloc) and returns a new node; its ‘content’ is initialized to the given pointer and its ‘next’ to NULL.                                                                                                                    |
| ***ft_lstadd_front*** | Adds the node ‘new’ at the beginning of the list pointed by ‘lst’.                                                                                                                                                                           |
| ***ft_lstsize***      | Returns the number of nodes in the list starting at ‘lst’.                                                                                                                                                                                   |
| ***ft_lstlast***      | Returns the last node of the list starting at ‘lst’.                                                                                                                                                                                         |
| ***ft_lstadd_back***  | Adds the node ‘new’ at the end of the list pointed by ‘lst’.                                                                                                                                                                                 |
| ***ft_lstdelone***    | Frees the given node ‘lst’ using function ‘del’ on its content, then frees the node itself; does not free following nodes.                                                                                                                   |
| ***ft_lstclear***     | Deletes and frees the given node and all its successors using function ‘del’ on contents and free(3); final list pointer is set to NULL.                                                                                                     |
| ***ft_lstiter***      | Iterates the list ‘lst’ and applies function ‘f’ on the content of each node.                                                                                                                                                                |
| ***ft_lstmap***       | Iterates the list ‘lst’, applies function ‘f’ to each content, creates a new list resulting from successive applications of ‘f’; if needed uses ‘del’ to free content on failure; returns the new list or NULL on memory allocation failure. |

>None of them has memory leaks errors.
