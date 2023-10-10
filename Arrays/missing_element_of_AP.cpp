//User function template for C++

class Solution{   
public:
    int findMissing(int arr[], int n) {
        // Finding common difference
        int common_diff = (arr[n-1] - arr[0])/n;
        
        // Now setting a checker at each point and run a loop
        int checker = arr[0];
        for(int i=1; i<n; i++) {
            checker += common_diff;
            if(arr[i] != checker) {
                return checker;
            }
        }
    }
};