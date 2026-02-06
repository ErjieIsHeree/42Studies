*This project was created as part of the curriculum of 42 by exia*

# GET_NEXT_LINE

___

## Description

The objective of this project is to recreate an easy-mid difficult level function very useful to read files. The function is called get_next_line, as it names refer, it will return the value of a file line by line.

___

### Instructions

The function signature is like this:

```c
char *get_next_line(int fd);
```

The parameter introduced is the file descriptor asigned to the opened file.
Each call to the get_next_line function will return a new string of the line read.
*Note: by default the buffer used to read the file is 42. It can be changed by compiling with the flag "-D BUFFER_SIZE=(the desired size)"*

>The function uses a static variable. In order to free that parameter, the function shall be called until a NULL pointer is returned.
___

### Resources

- [Linux read guide](https://linux.die.net/man/3/read)

___

### Algorithm

The hole point of this project remains in:

- Pointers control
- C true string control
- Read cicle knowledge
- Static variables

>Sounds easy, but imagine starting the project having no idea or a wrong idea of many of them. Yup, that was me...

Once these are clear of this project is very simple:

At the first call:

1. Read the file until the new line is found.
2. Store it into the static variable
3. Return a string that contain the new line character as the last character of the string and move the rest of the static variable content to the start of it.

In the next calls:

1. Read the file until the new line is found.
2. Store it into the static variable behind the content that it already has.
3. Return a string that contain the new line character as the last character of the string and move the rest of the static variable content to the start of it.

Finally, the last call:

1. Return the rest of the content at the static variable lane by lane.

### Bonus algorithm

The only difference between this and the normal part is that here you will be able to save into the static variable more than one string. In order to do so, just change the static variable from a character pointer to an array of character pointer (Create it in the stack with the max amount of file descriptors you can have. The default amount is 1024). Each file descriptor is unique so you can allocate each character pointer in the position of "file descriptor" at the array pointer.

For example, there are 5 files opened, each corresponding to 5, 6, 8, 123, 42.

```c
=== At main
int fd1 = 5;
int fd2 = 6;
int fd3 = 8;
int fd4 = 123;
int fd5 = 42;

get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd3);
get_next_line(fd4);
get_next_line(fd5);

=== At get_next_line
char *get_next_line(int fd)
{
 static char *memory[1025]; //1025 because 1024 is the max file descriptor

 //to get the character pointer of the actual file descriptor we just use the
 //file descriptor as the actual position at the array.
 memory[fd];

 return (read_value);
}
```
