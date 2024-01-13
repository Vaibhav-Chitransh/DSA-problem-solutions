#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e) {
    int left = s;
    int right = mid+1;

    vector<int> temp;  // space complexity = O(n)

    while(left <= mid && right <= e) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left++]);
    }
    while(right <= e) {
        temp.push_back(arr[right++]);
    }

    // Copying the values of temp to arr
    for(int i=s; i<=e; i++) {
        arr[i] = temp[i-s];
    }
}

void mergeSort(vector<int>& arr, int s, int e) {
    // base case
    if(s >= e) {
        return ;
    }

    int mid = (s+e)/2;

    // Recursive calls for dividing the array
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid+1, e);

    // Function call for merging both the sorted arrays
    merge(arr, s, mid, e);
}

int main(){
    vector<int> arr = {2,5, 4, 1, 6, 7, 3};
    int n = 7;

    cout << "Before sorting the array is " << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n-1);

    cout<< "After sorting the array is " << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}