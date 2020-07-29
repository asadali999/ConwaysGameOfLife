#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

#include "BoardFile.h"

FILE* output;
time_t start;
time_t end;

int r = 0, c = 0, genNum = 0, size = 0, * board;

#define ThreadsNum 10

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


void ViewBoard(FILE* output)
{
    for (int i = 0; i < size; ++i)
    {
        if (((i % columns) == 0) ^ (i == 0))
        {
	        printf(output, "\n");
        }
        printf(output, "%c", (board[i] == 0 ? '.' : '*'));
    }
}

void Boardd(void)
{
    memcpy(board, copy, size * sizeof(int));
}

void* threading(void* arguments)
{
    thread_param_t* real;
    real = (thread_param_t*)arguments;
    int value = 0;

    for (int a = 0; a < generations; ++a)
    {
        processGeneration(real);

        value = cyclic_barrier_await(real->barrier);
    }

    return NULL;
}

void BoardNotes(void)
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
    cyclic_barrier_t barrier;


    threads = malloc(ThreadsNum * sizeof(pthread_t));
    param = malloc(ThreadsNum * sizeof(thread_param_t));

    splitBoard(param, ThreadsNum, r, c);
    cyclic_barrier_init(&barrier, NULL, NULL, NUMBER_OF_THREADS, BoardNotes);

    for (index = 0; index < NUMBER_OF_THREADS; index++) 
    {
        parameters[index].barrier = &barrier;
        pthread_create(&threads[index], NULL, threading, &parameters[index]);
    }

    start = clock();

    for (i = 0; i < ThreadsNum; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Runtime was %.6f\n", ((double)(end-start)) / 1.0E6);
    
    if(1 < argc)
    {
        output = fopen(argv[2], "w");
    }
    else
    {
       output = stdout;
    }
    
    ViewBoard(output);
    
    if(output != stdout)
    {
	fclose(output);
    }

    cyclic_barrier_destroy(&barrier);

    free(board);
    free(copy);
    free(parameters);
    free(threads);

    return 0;
}
