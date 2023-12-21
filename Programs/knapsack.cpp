#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int MAX_W = 1000;

int knapsack(int W, int weights[], int values[], int n)
{

    int dp[MAX_N + 1][MAX_W + 1] = {0};

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {

            if (weights[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
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

    /*Array Indexing:

The arrays in C++ are zero-indexed, meaning the first element has an index of 0,
the second element has an index of 1, and so on.
In this code, selectedCoins is an array used to store the indices of the selected
items (coins) in the knapsack.
Dynamic Programming Table:

dp is a two-dimensional array representing the dynamic programming table. dp[i][j]
represents the maximum value that can be achieved with the first i items (coins) and a knapsack capacity of j.
The loop iterates over all possible combinations of the number of items (i) and the
knapsack capacity (j).
While Loop Conditions:

The while loop continues as long as there are more items (i > 0) to consider and
there is still capacity in the knapsack (j > 0).
The loop checks the value stored in dp[i][j] against the value in the row above,
i.e., dp[i - 1][j].
Selection of Items:

If dp[i][j] is not equal to dp[i - 1][j], it means the i-th item is part of the
optimal solution. Therefore, its index (i - 1) is stored in the selectedCoins array.
The knapsack capacity j is then reduced by the weight of the selected item (j -= weights[i - 1]),
and the index i is decremented (i--).
If dp[i][j] is equal to dp[i - 1][j], it means the i-th item is not included in the
optimal solution, so we move to the row above by decrementing i.
Array Indexing in Storage:

The selected item indices are stored in the selectedCoins array. Since the arrays are
zero-indexed, the indices of the selected items are i - 1*/

    cout << "\nSelected weights : ";
    for (int k = selectedCount - 1; k >= 0; k--)
    {
        cout << selectedCoins[k] + 1 << " ";
    }

    return dp[n][W];
}

/*Print Statement:

cout << "\nSelected weights : ";: This line is a simple output statement indicating that the following numbers
will be the indices of the selected weights.
For Loop:

for (int k = selectedCount - 1; k >= 0; k--): This loop iterates through the selectedCoins array in reverse order.
It starts from the last selected item and goes backward until the first selected item.
Printing Selected Weights:

cout << selectedCoins[k] + 1 << " ";: Inside the loop, it prints the index of the selected item plus 1.
This is done
because array indices are zero-based, but it seems the goal here is to present results in a more natural
one-based index.
For example, if the index in selectedCoins[k] is 2, it will be printed as 2 + 1 = 3. This adjustment is
made to align
the indices with typical human counting (starting from 1).*/

int main()
{
    int n;
    cout << "\nEnter the number of items: ";
    cin >> n;

    int weights[MAX_N];
    int values[MAX_N];

    cout << "\nEnter the weights of items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    cout << "\nEnter the values of items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int W;
    cout << "\nEnter the knapsack capacity: ";
    cin >> W;
    int resultDP = knapsack(W, weights, values, n);
    cout << "\n"
         << "Dynamic Programming: The maximum value that can be obtained is: " << resultDP << endl;
    cout << "\n\n";

    return 0;
}
