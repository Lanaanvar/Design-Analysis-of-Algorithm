#include<iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        int j=i+1;
        while(j<n)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            j++;
        }
        if(min!=i)
        {
            swap(a[i], a[min]);
        }
    }
    for(int k=0; k<n; k++)
    {
        cout<<a[k]<<" ";
    }
}

int main()
{
    int n;
    cout<<"\nEnter length of array : ";
    cin>>n;
    cout<<"\n";

    int* array= new int[n];
    cout << "\nEnter the array elements one by one : ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout<<"\n";
    cout<<"\nGiven array : ";
    for(int k=0; k<n; k++)
    {
        cout<<array[k]<<" ";
    }
    cout<<"\n";

    cout<<"\nAfter sorting : ";
    selection_sort(array, n);
    cout<<"\n\n";

}
