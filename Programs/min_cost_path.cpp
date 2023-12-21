#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

void showPath(int **matrix, int m, int n)
{
    cout << "\nPath\n";
    int i = 0;
    int j = 0;
    cout << "(" << i + 1 << "," << j + 1 << ")-->";
    while (i != m && j != n)
    {
        if (i == m)
        {
            j++;
        }
        else if (j == n)
        {
            i++;
        }
        else if (matrix[i + 1][j] <= matrix[i][j + 1] && matrix[i + 1][j] <= matrix[i + 1][j + 1])
        {
            i++;
        }
        else if (matrix[i][j + 1] <= matrix[i + 1][j] && matrix[i][j + 1] <= matrix[i + 1][j + 1])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
        cout << "(" << i + 1 << "," << j + 1 << ")-->";
    }
    cout << "(" << m + 1 << "," << n + 1 << ")";
    return;
}

int min_cost_path(int** C, int n, int m)
{
    int** F = new int*[n];
    for (int i = 0; i < n; ++i) {
        F[i] = new int[m];
    }

    F[0][0] = C[0][0];

    for(int j = 1; j < m; j++)
    {
        F[0][j] = F[0][j-1] + C[0][j];
    }
    for(int i = 1; i < n; i++)
    {
        F[i][0] = F[i-1][0] + C[i][0];

        for(int j = 1; j < m; j++)
        {
            F[i][j] = min({F[i-1][j], F[i][j-1], F[i-1][j-1]}) + C[i][j];
        }
    }

    int result = F[n-1][m-1];

    cout << "The minimum path sum is: " << result << endl;
    showPath(F, n - 1, m - 1);

    for (int i = 0; i < n; ++i) {
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

    int** M = new int*[n];
    for (int i = 0; i < n; ++i) {
        M[i] = new int[m];
    }

    cout << "\nEnter the values for the matrix C:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> M[i][j];
        }
    }

    int maximum = min_cost_path(M, n, m);

    cout << "\nThe minimum cost of the path in the matrix is: " << maximum << endl;
    cout<<"\n\n";
    return 0;
}