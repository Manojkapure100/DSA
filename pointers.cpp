#include<iostream>
#include<vector>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr; // Pointer to the first element of the array
    int** ptr2 = &ptr;

    cout << **ptr2 << endl;
    cout << *ptr2 << endl;

    cout << ptr << "\t" << *ptr << endl; // Output the first element using pointer dereferencing
    
    ptr+=2;

    cout << ptr << "\t" << *ptr << endl; // Output the first element using pointer dereferencing

    cout << arr[0] << arr[1] << arr[2] << endl;

    cout << ptr[0] << ptr[1] <<ptr[2] << ptr[3] << ptr[4] << ptr[5] << endl;

    return 0;
}