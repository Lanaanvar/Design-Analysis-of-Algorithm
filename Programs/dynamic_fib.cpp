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

    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << std::endl;
        return 1;
    }

    int fibonacciSeries[n];
    generateFibonacci(n, fibonacciSeries);

    cout << "Fibonacci Series:";
    for (int i = 0; i < n; ++i) {
        std::cout << " " << fibonacciSeries[i];
    }

    return 0;
}
