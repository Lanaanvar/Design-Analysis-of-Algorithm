#include <iostream>
#include <climits>
using namespace std;

void printCoins(int F[], int n, int coins[], int d) {
    cout << "\nCoins selected: ";
    while (n > 0) {
        for (int i = d - 1; i >= 0; i--) {
            if (n - coins[i] >= 0 && F[n - coins[i]] + 1 == F[n]) {
                n -= coins[i];
                cout << coins[i] << ", ";
                break;
            }
        }
    }
}



int coin_change(int D[], int n, int m) {
    int *F = new int[n];
    F[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (i >= D[j]) {
                temp = min(F[i - D[j]], temp);
            }
        }
        F[i] = temp + 1;
    }
    printCoins(F, n, D, m);

    return F[n];
}

int main() {
    int n;
    cout << "\nEnter the amount ";
    cin >> n;

    int m;
    cout << "\nEnter the no. of coins : ";
    cin >> m;

    int *C = new int[m];

    cout << "\nEnter the coin values : ";
    for (int i = 0; i < m; i++) {
        cin >> C[i];
    }

    int minimum = coin_change(C, n, m);

    cout <<"\n"<< "The minimum number of coins is : " << minimum;

    cout<<"\n\n";

    return 0;
}

