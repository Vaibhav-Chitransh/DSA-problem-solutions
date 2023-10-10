
//User function Template for C++

void rotate(int arr[], int n)
{
    int* a = new int[n];
    
    for(int i=0; i<n; i++) {
        a[(i+1)%n] = arr[i];
    }
    for(int i=0; i<n; i++) {
        arr[i] = a[i];
    }
}