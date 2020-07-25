#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

#include "BoardFile.h"

FILE* output;
time_t start;
time_t end;

int r = 0, c = 0, genNum = 0, size = 0, *board;

#define ThreadsNum 1

void inputFunc(char* file_name)
{
    FILE* read;
    read = fopen(file_name, "r");
    if (!read)
    {
        printf("Opening Failed.");
        exit(EXIT_FAILURE);
    }

    fscanf(read, "%d %d %d", &genNum, &r, &c);
    size = r * c;
    board = malloc(sizeof(int) * size);

    int readChar = 0;
    int point = 0;

    do 
    {
        readChar = fgetc(read);
        if (EOF != readChar) 
        {
            // Ignore whitsespace in reading in the string
            if (!isspace(readChar)) 
            {
                if ('*' == readChar)
                {
                    board[point] = 1;
                    point = point + 1;
                }
                else if ('.' == readChar)
                {
                    board[point] = 0;
                    point = point + 1;
                }                
            }
        }
    } while (EOF != readChar);

    fclose(read);
    if (point != size)
    {
        printf("Invalid Input File");
        free(board);
        exit(EXIT_FAILURE);
    }
}

void Boardd(void)
{
    memcpy(board, copy, size * sizeof(int));
}

int main(int argc, char** argv)
{
   inputFunc(argv[1]);
   
   copy = malloc(sizeof(int) * size);

   memcpy(copy, board, size * sizeof(int));

   pthread_t* threads;
   thread_param_t* param;
    
  

    threads = malloc(ThreadsNum * sizeof(pthread_t));
    param = malloc(ThreadsNum * sizeof(thread_param_t));

    splitBoard(param, ThreadsNum, r, c);
    
    start = clock();

    for (i = 0; i < ThreadsNum; i++) 
    {
        pthread_join(threads[i], NULL);
    }

    end = clock();

    
    free(threads);
    free(param);

    return 0;
}
