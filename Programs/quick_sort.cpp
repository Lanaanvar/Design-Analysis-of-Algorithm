#include <iostream>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb + 1;
    int end = ub;

    while (start <= end)
    {
        while (start <= ub && arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}

void quick_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int piv = partition(arr, lb, ub);
        quick_sort(arr, lb, piv - 1);
        quick_sort(arr, piv + 1, ub);
    }
}

int main()
{
    int n;

    cout << "ENTER NO. OF ELEMENTS IN THE ARRAY : ";
    cin >> n;

    int *arr = new int[n];

    cout << "ENTER THE ARRAY ELEMENTS ONE BY ONE : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "AFTER QUICK SORT : ";
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}