#include "functions.h"

bool check(bool *mas, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (mas[i])
            count++;
    if (count == size)
        return false;
    else
        return true;
}

mini min_elem(int **a, int size)
{
    mini temp;
    for (int i = 0; i < size; i++)
    {   
            for (int j = 0; j < size; j++)
            {
                if (a[i][j] < temp.min && a[i][j] != 0)
                {
                    temp.min = a[i][j];
                    temp.pos1 = i;
                    temp.pos2 = j;
                }
            }
    }
    return temp;
}

mini min_elem(int **a, int size, bool *visited)
{
    mini temp;
    for (int i = 0; i < size; i++)
    {   
        if (visited[i])
            for (int j = 0; j < size; j++)
            {
                if (a[i][j] < temp.min && a[i][j] != 0)
                {
                    temp.min = a[i][j];
                    temp.pos1 = i;
                    temp.pos2 = j;
                }
            }
    }
    return temp;
}