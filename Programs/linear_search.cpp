#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key){
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    const int maxSize = 100; // Maximum size of the array
    int arr[maxSize]; // Declare an array to store elements
    int size, key;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    // Get array elements from the user
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Get the key to search from the user
    cout << "Enter the element to search: ";
    cin >> key;

    // Perform linear search
    int result = linearSearch(arr, size, key);

    // Display the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
