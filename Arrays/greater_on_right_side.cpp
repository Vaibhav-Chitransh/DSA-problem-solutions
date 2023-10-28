void nextGreatest(int arr[], int n) {
        vector<int> v;
        v.push_back(-1);
    
        int maxi = arr[n-1];
        
        for(int i=n-1; i>0; i--) {
            if(maxi > arr[i]) {
                v.push_back(maxi);
            }
            else {
                maxi = arr[i];
                v.push_back(maxi);
            }
        }
        
        for(int i=0; i<n; i++) {
            arr[i] = v[n-1-i];
        }
    }