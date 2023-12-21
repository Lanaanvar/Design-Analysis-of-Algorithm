#include <iostream>
using namespace std;

void generateFibonacci(int n, int fibSeries[]) {
    if (n <= 0) {
        return;
    }

    fibSeries[0] = 0;

    if (n == 1) {
        return;
    }

    fibSeries[1] = 1;

    for (int i = 2; i < n; ++i) {
        fibSeries[i] = fibSeries[i - 1] + fibSeries[i - 2];
    }
}

int main() {
    int n;

    cout << "\nEnter the number of Fibonacci numbers to generate: ";
    cin >> n;

    if (n <= 0) {
        cout << "\nInvalid input. Please enter a positive integer." << endl;
        return 1;
    }

    int fibonacciSeries[n];
    generateFibonacci(n, fibonacciSeries);

    cout << "\nFibonacci Series:";
    for (int i = 0; i < n; ++i) {
        cout << " " << fibonacciSeries[i];
    }

    cout<<"\n\n";

    return 0;
}
