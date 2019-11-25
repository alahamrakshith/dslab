// A simple C++ program to rearrange
// contents of arr[] such that arr[j]
// becomes j if arr[i] is j
#include <stdio.h>
using namespace std;

// A simple method to rearrange
// 'arr[0..n-1]' so that 'arr[j]'
// becomes 'i' if 'arr[i]' is 'j'
void rearrange(int arr[], int n)
{
    for (int i = 0; i < n; i++) {

        // retrieving old value and
        // storing with the new one
        arr[arr[i] % n] += i * n;
    }

    for (int i = 0; i < n; i++) {

        // retrieving new value
        arr[i] /= n;
    }
}

// A utility function to print
// contents of arr[0..n-1]
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// Drive program
int main()
{
    int arr[] = { 2, 0, 1, 4, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is : " << endl;
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Modified array is :" << endl;
    printArray(arr, n);

    return 0;
}
