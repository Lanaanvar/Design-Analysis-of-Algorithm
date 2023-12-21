#include <iostream>
using namespace std;

void printCoins(int collected[], int coins[], int n)
{
    cout << "\ncoins collected are : ";
    for (int i = n - 1; i >= 0; i -= 2)
    {
        if (collected[i] == collected[i - 1])
        {
            i--;
        }
        cout << coins[i] << " , ";
    }
}

int coin_row(int C[], int n)
{
    int *F = new int[n];
    F[0] = 0;
    F[1] = C[0];

    for (int i = 2; i < n; i++)
    {
        F[i] = max(C[i] + F[i - 2], F[i - 1]);
    }

    printCoins(F, C, n);

    return F[n - 1];
}

int main()
{
    int n;
    cout << "\nEnter the number of coins ";
    cin >> n;

    int *C = new int[n];

    cout << "\nEnter the coin values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }

    int maximum = coin_row(C, n);

    cout << "\n"
         << "The maximum amount is : " << maximum;

    cout<<"\n\n";
    return n;
}