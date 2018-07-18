# Get Next Line
Get next line is the 4th project in the 42 School Program. In this activity you need to create a function which can get the next line of any input, and return 1 if there is more to retrieve, 0 if the file is over and -1 if it encounters any error. This project is pretty memory efficient, there should me no memory leaks. 

## My approach

The way I did get next line is by creating a static linked list in which you save a structure that has 3 elements: The string read from the input, the file descriptor and a pointer to the next element. Each time you call the function it checks if the fd was already called before, in case that it has not it proceeds to create a new element saving the FD and reading the input information. On the other hand, if the file has been read before, the function will return the string and 1. If there is any error along the function cal it will simply return (-1).

## Installing / Using this function

In order to use this function a library called libft must be generated. To get the function running follow the next steps: 

1) Clone the repository
2) Go to ./Activity/libft and run the command
'''
make re
''
4) Copy the generated library and the header file to your source directory.
5) Copy get_next_line.c and get_next_line.h files into your source directory too.
	This files are located inside ./Activity/

## Running Pre-created test

If you wish to run the sample tests included in this file:

1) Clone the repository
2) Run the following command 
'''
	gcc -Wall -Wextra -Werror main.c Activity/get_next_line.c  Activity/libft/*.c -IActivity/ -o Getline
'''
3) Run the Getline executable with as many file paths as you want
'''
./Getline testfiles/test1.txt
'''
