#include <iostream>
using namespace std;

void printLCS(int row, int col, string text1, string text2, int **mat)
{
    int length = mat[row][col];
    char *lcs = new char[length + 1];

    int i = row, j = col, index = length;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs[index] = text1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (mat[i - 1][j] > mat[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "\nThe largest common subsequence is: ";
    for (int k = 1; k <= length; k++)
    {
        cout << lcs[k];
    }

    delete[] lcs;
}

void lcs(int row, int col, string text1, string text2)
{
    int **mat = new int *[row + 1];
    for (int i = 0; i <= row; i++)
    {
        mat[i] = new int[col + 1];
    }

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    cout << "\n"
         << "The largest common subsequence length is: " << mat[row][col];
    printLCS(row, col, text1, text2, mat);

    for (int i = 0; i <= row; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

int main()
{
    string S1;
    cout << "\nEnter string1 : ";
    cin >> S1;

    string S2;
    cout << "\nEnter string2 : ";
    cin >> S2;

    int m = S1.size();
    int n = S2.size();

    lcs(m, n, S1, S2);
    cout<<"\n\n";
    
    return 0;
}