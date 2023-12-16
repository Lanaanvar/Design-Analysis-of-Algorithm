#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000; // Maximum number of items
const int MAX_W = 1000; // Maximum knapsack capacity

int knapsack(int W, int weights[], int values[], int n)
{
    // Initialize a 2D array to store the results of subproblems
    int dp[MAX_N + 1][MAX_W + 1] = {0};

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            // If the current item's weight is greater than the remaining capacity, skip it
            if (weights[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                // Choose the maximum value between including and excluding the current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
        }
    }
    
    int selectedCoins[n];
    int selectedCount = 0;
    int i = n;
    int j = W;

    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            selectedCoins[selectedCount++] = i - 1;
            j -= weights[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }

    cout << "\nSelected weights : ";
    for (int k = selectedCount - 1; k >= 0; k--)
    {
        cout << selectedCoins[k] + 1 << " ";
    }

    // The result is stored in the bottom-right cell of the table
    return dp[n][W];
}


int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[MAX_N];
    int values[MAX_N];

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    // Using dynamic programming solution
    int resultDP = knapsack(W, weights, values, n);
    cout <<"\n"<< "Dynamic Programming: The maximum value that can be obtained is: " << resultDP << endl;


    return 0;
}
