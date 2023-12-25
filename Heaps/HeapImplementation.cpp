#include<iostream>
#include<queue>
using namespace std;

class heap {
    public:
        int arr[100];
        int size = 0;

        // Constructor
        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int value) {
            size = size + 1;
            int index = size;
            arr[index] = value;

            while(index > 1) {
                int parent = index/2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else {
                    return ;
                }
            }
        }

        void deleteFromHeap() {
            if(size == 0) {
                cout << "Nothing to delete" << endl;
                return ;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i < size) {
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if(leftIndex < size && arr[leftIndex] > arr[i]) {
                    swap(arr[leftIndex], arr[i]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[rightIndex] > arr[i]) {
                    swap(arr[rightIndex], arr[i]);
                    i = rightIndex;
                }
                else {
                    return ;
                }
            }
        }

        void print() {
            for(int i=1; i<=size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    h.insert(3);
    h.insert(2);
    h.insert(6);
    h.insert(1);
    h.insert(5);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 5, 6, 2, 3, 1};
    int n = 5;

    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing the array" << endl;

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Printing the array" << endl;

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Using STL
    priority_queue<int> maxHeap;

    maxHeap.push(3);
    maxHeap.push(6);
    maxHeap.push(1);
    maxHeap.push(2);
    maxHeap.push(4);

    cout << maxHeap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(4);

    cout << minHeap.top() << endl;

    return 0;
}