#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i; j>0; j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
            else {
                break;
            }
        }
    }
}

int main(){
    int arr[6] = {2, 3, 0, 1, 2, 4};
    int n = 6;

    cout << "Printing the array before sorting" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);

    cout << "Printing the array after sorting" << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}