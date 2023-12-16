// #include <iostream>
// #include<climits>
// using namespace std;

// int coin_row(int D[], int n, int m)
// {
//     int *F = new int[n];
//     F[0] = 0;

//     for (int i = 1; i < n; i++)
//     {
//         int temp=INT_MAX;
//         int j=0;

//         while(j< m && i>=D[j])
//         {
//             temp=min(F[i-D[j]], temp);
//             j=j+1;
//         }
//         F[i]=temp+1;
        
//     }

//     return F[n-1];
// }

// int main()
// {
//     int n;
//     cout << "Enter the amount ";
//     cin >> n;

//     int m;
//     cout<<"Enter the no. of coins : ";
//     cin>>m;

//     int *C = new int[m];

//     cout << "Enter the coin values : ";
//     for (int i = 0; i < m; i++)
//     {
//         cin >> C[i];
//     }

//     int minimum = coin_row(C, n,m);

//     cout << "The minimum number of coins is : " << minimum;

//     return n;
// }

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
    cout << "Enter the amount ";
    cin >> n;

    int m;
    cout << "Enter the no. of coins : ";
    cin >> m;

    int *C = new int[m];

    cout << "Enter the coin values : ";
    for (int i = 0; i < m; i++) {
        cin >> C[i];
    }

    int minimum = coin_change(C, n, m);

    cout <<"\n"<< "The minimum number of coins is : " << minimum;

    return 0;
}

