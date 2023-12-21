#include <iostream>
#include <climits>
using namespace std;

void traceBack(int **grid, int rows, int cols)
{
    int i = rows - 1;
    int j = cols - 1;
    cout << "Path of optimal decisions:" << endl;
    cout << "(" << i << ", " << j << ")";
    while (i > 0 || j > 0)
    {
        if (i > 0 && j > 0)
        {
            if (grid[i - 1][j] >= grid[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
        else if (i > 0)
        {
            --i;
        }
        else
        {
            --j;
        }
        cout << " <- (" << i << ", " << j << ")";
    }
    cout << endl;
}

int coin_coll(int **C, int n, int m)
{
    int **F = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        F[i] = new int[m];
    }

    F[0][0] = C[0][0];

    for (int j = 1; j < m; j++)
    {
        F[0][j] = F[0][j - 1] + C[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        F[i][0] = F[i - 1][0] + C[i][0];

        for (int j = 1; j < m; j++)
        {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }

    cout<<"\n\n";

    traceBack(F, n, m);


    int result = F[n - 1][m - 1];

    
    for (int i = 0; i < n; ++i)
    {
        delete[] F[i];
    }
    delete[] F;

    return result;
}

int main()
{
    int n, m;
    cout << "\nEnter the number of rows: ";
    cin >> n;

    cout << "\nEnter the number of columns: ";
    cin >> m;

    int **C = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        C[i] = new int[m];
    }

    cout << "\nEnter the values for the matrix C:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> C[i][j];
        }
    }

    int maximum = coin_coll(C, n, m);

    cout << "\nThe maximum number of coins collected is: " << maximum << endl;

    cout<<"\n\n";

    return 0;
}