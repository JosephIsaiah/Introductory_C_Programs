/*****************************************************
 *
 *
 * Purpose: Write a program that accepts the name of a file as input and determines how large the file is in bytes.
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
    FILE* pInputFile;
    int   size;

    if (argc < 2) // Evaluates number of arguments. If less than 2, file name was not passed to program.
    {                                                       
        printf("Usage: week5 <filename>\n\n");
        exit(1);
    }

    else
    {   
        FILE* pInputFile;
        pInputFile = fopen(argv[1], "r"); // Opens the file in read mode and asigns the data to pInputFile.
        
        if (pInputFile == NULL) {                            // Validates if a file was succesfully opened.
            printf("Cannot open input file: %s\n", argv[1]); // Notifies the user if the file was not opnened.
            exit(1);
        }
       
        fseek(pInputFile, 0, SEEK_END); // Set the position at the end of the file.
        size = ftell(pInputFile); // Using ftell to determine the position of the stream and assigning that value to size.
        fclose(pInputFile); // Close the file.

        printf(">filesize %s \n\n File %s is %d bytes in size. \n", argv[1], argv[1], size); // Print the value of size (its location) as the size of the file.
  
    }
    
    return 0;
}