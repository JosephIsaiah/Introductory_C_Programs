/*****************************************************
 *
 *
 * Purpose: Write a program that accepts the name of the file as input and prints the contents of the file to the console window.
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
    FILE    *pInputFile;
    #define  BUFFER 256
    char     contents[BUFFER];

    if(argc < 2)  // Evaluates number of arguments. If less than 2, file name was not passed to program.
    {
        printf("Usage: week5 <filename>\n\n"); 
        exit(1);
    }

    else {
        FILE *pInputFile;
        pInputFile = fopen(argv[1], "r"); // Opens the file in read mode and asigns the data to pInputFile.

        if(pInputFile == NULL) {
            printf("Cannot open input file: %s\n", argv[1]); // Notifies the user if the file was not opnened.
            exit(1);
        }

        else {
           while( !feof(pInputFile)) // Loop will keep evaluating till the end of pInputFile.
           {
                fgets(contents, BUFFER, pInputFile); // Reading from pInputFile and storing the data in contents with a max number of characters set by BUFFER above.
                printf("%s", contents); // Printing the data stored in contents.
            }
           printf("\n\n");
        }

        fclose(pInputFile);
     }  
    
    return 0;
}
