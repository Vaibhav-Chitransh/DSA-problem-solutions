#include<iostream>
using namespace std;

int find_pivotIndex(int arr[], int start, int end) {
    int pivot = arr[start];

    // Count all elements less than pivot 
    int count = 0;
    for(int i=start; i<=end; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }

    int pivotIndex = start+count;
    swap(arr[start], arr[pivotIndex]);
    int i = start;
    int j = end;

    // these loops are doing partition for me
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex && arr[i] > pivot && arr[j] < pivot) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    // Base case
    if(start >= end) {
        return ;
    }

    int pivotIndex = find_pivotIndex(arr, start, end);

    // Recursive call for left half
    quickSort(arr, start, pivotIndex-1);

    // Recursive call for right half
    quickSort(arr, pivotIndex+1, end);
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[6] = {4, 5, 1, 2, 0, 0};
    int n = 6;

    int start = 0;
    int end = n-1;

    cout << "Printing the array before sorting" << endl;
    printArray(arr, n);

    quickSort(arr, start, end);

    cout << "Printing the array after sorting" << endl;
    printArray(arr, n);
    return 0;
}