#include<iostream>
using namespace std;

void selection_sort(string a[], int n)
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
    cout<<"Enter length of array : ";
    cin>>n;
    cout<<"\n";

    string* array= new string[n];
    cout<<"Enter "<<n<<" array strings :";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }
    cout<<"\nGiven array : ";
    for(int k=0; k<n; k++)
    {
        cout<<array[k]<<" ";
    }

    cout<<"\nAfter sorting : ";
    selection_sort(array, n);
    cout<<"\n\n";

}
