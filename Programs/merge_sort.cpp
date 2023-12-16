#include <iostream>
using namespace std;

void merge(double arr[], int lb, int mid, int ub)
{
    // int len = size_t(arr);
    int i = lb;
    int j = mid + 1;
    int k = lb;
    double*b=new double[ub - lb + 1];

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            /* code */
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for (int x = lb; x <= ub; x++)
    {
        arr[x] = b[x];
    }
}

void merge_sort(double arr[], int lb, int ub)
{
    // int len=size_t(arr);
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int n;
    cout << "Enter length of array : ";
    cin >> n;

    double* array= new double[n];
    cout << "Enter " << n << " array elements :";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    merge_sort(array, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n\n";

    return 0;
}
