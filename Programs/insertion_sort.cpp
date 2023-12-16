#include <iostream>
using namespace std;

void insertion_sort(double arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        double temp = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] < temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter length of array : ";
    cin >> n;

    cout << "\n";

    double *array = new double[n];
    cout << "Enter " << n << " array elements :";

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "\nGiven array : ";
    for (int k = 0; k < n; k++)
    {
        cout << array[k] << " ";
    }

    cout << "\n\n";
    cout << "After sorting : ";
    insertion_sort(array, n);

    cout << "\n";
    return 0;
}
