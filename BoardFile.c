#include "Board_Splitter.h"

int Board(thread_param_t* list, int count, int rows, int columns)
{
    if ((rows / count) != 0)
    {
        int row = rows % count;
        int RowPer = rows / count;

        int currentRow = 0;
        for (int i = 0; i < count; ++i)
        {
            if (row > 0)
            {
                list[i].firstRow = currentRow;
                list[i].firstCol = 0;
                list[i].length = (RowPer + 1) * columns;
                currentRow += RowPer + 1;
                --row;
            }
            else
            {
                list[i].firstRow = currentRow;
                list[i].firstCol = 0;
                list[i].length = RowPer * columns;
                currentRow += RowPer;
            }
        }
    }
    else if (count > (rows * columns))
    {
        int overflow = 0;
        overflow = count - (rows * columns);
        int currentRow = 0;
        int currentCol = 0;

        for (int i = 0; i < count; ++i)
        {
            if ((count - i) > overflow)
            {
                list[i].firstRow = currentRow;
                list[i].firstCol = currentCol;
                list[i].length = 1;

                if ((currentCol + 1) >= columns)
                {
                    currentCol = 0;
                    ++currentRow;
                }
                else
                {
                    ++currentCol;
                }
            }
            else
            {
                list[i].firstRow = 0;
                list[i].firstCol = 0;
                list[i].length = 0;
            }
        }
    }
    else
    {
        int currentRow = 0;
        int currentCol = 0;

        for (int i = 0; i < count; ++i)
        {
            if ((count - i) > (rows - currentRow))
            {
                list[i].firstRow = currentRow;
                list[i].firstCol = currentCol;
                list[i].length = 1;

                if ((currentCol + 1) >= columns)
                {
                    currentCol = 0;
                    ++currentRow;
                }
                else
                {
                    ++currentCol;
                }
            }
            else
            {             
                if (currentCol != 0)
                {
                    int columnsLeft = columns - currentCol;
                    list[i].firstRow = currentRow;
                    list[i].firstCol = currentCol;
                    list[i].length = columnsLeft;

                    currentCol = 0;
                    ++currentRow;
                }
                else
                {
                    list[i].firstRow = currentRow;
                    list[i].firstCol = currentCol;
                    list[i].length = columns;

                    ++currentRow;
                }
            }
        }
    }

    return 0;
}