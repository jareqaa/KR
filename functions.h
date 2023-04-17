struct mini
{
    int min = 100000000, pos1 = 0, pos2 = 0;
};

bool check(bool *mas, int size);
mini min_elem(int **a, int size, bool *visited);
mini min_elem(int **a, int size);