# Get Next Line
Get next line is the 4th project in the 42 School Program. In this activity you need to create a function which can get the next line of any input, and return 1 if there is more to retrieve, 0 if the file is over and -1 if it encounters any error. This project is pretty memory efficient, there should me no memory leaks. 

## My approach

My approach is to create a statc variable which will contain the strings of all the diferent file descriptors that the function may get, when it get called (probably several times) in the same program. My first step is to check for any probable error like: having a null direction for the line return, a file descriptor that is not valid or an error reading the file. While I check for the error reading the file I assign the value of the file descriptor string I am going to save. I do so by creating a buffer variable which is then initialized to '\0' characters. Then I read the file, if my file string variable is empty then I just copy the buffer into the string, but if there is something in the variable then I will give a temporary variable the same address as my file string variable, then I join the string and the buffer in a new string and free my temporary variable. After that I errase the memory of the buffer and repeat this until I get to the end of the file, then I just free the buffer and return the last value of my read function which should be 0. Then I go to copy the new line into the string. To do this I get the address of the '\n' character and then copy my file string to a temporary variable. After that I set the '\n' address to be '\0' meaining the end of the string. Then I assign the line variable the substring of my file string from the beginning all the way to the new line address which now contaings a '\0' to represent the end of the string. Then I duplicate the string that goes after the new line address and free the temporary variable memory and return (1) to represent success. If there is no new line found and the file string is still existant I will create a copy of the filestring into the new line and convert my file string static variable to only '\0' so that next time the file will return (0) which represents the end of the file.

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
