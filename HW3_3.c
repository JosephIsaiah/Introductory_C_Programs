/*****************************************************
 *
 * 
 * Purpose: Write a program that accepts the name of the file as input and dumps the binary content to the console window.
 *
******************************************************/
#define _CRT_SECURE_NO_WARNINGS
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
    FILE*            pInputFile;
    int              dataToPrint;
    unsigned char    buffer[500]; // Created an unsigned variable to hold the read data with a 500 byte limit.
    int colums     = 8;

    if (argc < 2) // Evaluates number of arguments. If less than 2, file name was not passed to program.
    {
        printf("Usage: week5 <filename>\n\n");
        exit(1);
    }

    else {
        FILE* pInputFile;
        pInputFile = fopen(argv[1], "r");

        if (pInputFile == NULL)
        {
            printf("Cannot open input file: %s\n", argv[1]);
            exit(1);
        }

        else {
            dataToPrint = fread(buffer, 1, sizeof(buffer), pInputFile);
            // Assign data from pInputFile to buffer in one byte increments up to the max size of buffer. dataToPrint is assigned the return number of fread.

            if (dataToPrint > 1) // Will only run if data is assigned to dataToPrint
            {
                for (int i = 0; i < dataToPrint; ++i) // Will iterate (and increment) as long as i is less than the fread integer assigned to dataToPrint.
                {
                    printf("0x%02x ", buffer[i]);
                    /*Expressed 0x before each expression to identify to the user that this is being expressed in hex.
                     *Added space after each hex expression to aid with ease of reading.*/
                   
                    if ((i > 0) && (((i + 1) % colums) == 0)) // Print a new line if position i is greater than zero and if i+1 modulo the variable colums is zero.
                    {
                        printf("\n");
                    }
                }
            }

            printf("\n\n");
        }

        fclose(pInputFile);
    }

    return 0;
}
