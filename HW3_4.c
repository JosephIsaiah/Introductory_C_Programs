/*****************************************************
 *
 * 
 * Purpose: Write a program that reads a string from the user and writes the string to a file called output.txt.
 *
******************************************************/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/


int main(int argc, char** argv)
{
    FILE        *pInputFile;
    #define      BUFFER 500
    char         contents[BUFFER]; // Created contents variable to hold the user entered data with a size limit set to BUFFER.
    pInputFile = fopen("output.txt", "w"); // Use fopen "w" to create an empty file named output.txt (will overight any same named files).

    if(pInputFile == NULL) {
        printf("Unable to open / create the output.txt file.");
        exit(1);
     }

    else {
        printf("Please enter your string: \n\n");
        fgets(contents, BUFFER, stdin); // Use fgets stdin to accept input from the keyboard and assign it to contents with BUFFER max size.

        fputs(contents, pInputFile); // Takes the string data from contents and writes to output.txt.

        printf("\n\n");
        fclose(pInputFile);
     }

    
    return 0;
}