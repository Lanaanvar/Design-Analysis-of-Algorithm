#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}
int main() {
    const int maxSize = 100; 
    int arr[maxSize]; 
    int size, key;

    
    cout<<"\n";
    cout << "Enter the size of the array: ";
    cin >> size;

    
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    
    cout << "Enter the element to search: ";
    cin >> key;

    
    int result = linearSearch(arr, size, key);

    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    
    cout << "\n";

    return 0;
}
