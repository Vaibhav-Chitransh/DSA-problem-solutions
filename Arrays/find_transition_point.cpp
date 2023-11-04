int transitionPoint(int arr[], int n) {
        int start = 0;
        int end = n-1;
        
        if(arr[0]==1){
            return 0;
        }
        
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(arr[mid] == 1) {
                ans = mid;
                end = mid-1;
            }
            
            else {
                start = mid + 1;
            }
        }
        return ans;
    }