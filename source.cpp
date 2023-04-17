#include "source.h"

using namespace std;

int main()
{
    mini m;
    ifstream input_file;
    input_file.open("input.txt");
    int n;
    input_file >> n;
    int **a = new int *[n];
    bool *v = new bool [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int [n];
        v[i] = false;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            input_file >> a[i][j];
    input_file.close();
    int sum = 0;
    m = min_elem(a, n);
    v[m.pos1] = v[m.pos2] = true;
    sum += m.min;
    a[m.pos1][m.pos2] = a[m.pos2][m.pos1] = 0;
    while (check(v, n))
    {
        m = min_elem(a, n, v);
        if (!v[m.pos1] || !v[m.pos2])
        {
            v[m.pos1] = v[m.pos2] = true;
            sum += m.min;
            a[m.pos1][m.pos2] = a[m.pos2][m.pos1] = 0;
        }
    }
    ofstream output_file;
    output_file.open("output.txt");
    output_file << "Искомое значение: " << sum;
    output_file.close();
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    delete[] v;
}