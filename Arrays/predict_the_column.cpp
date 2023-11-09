int columnWithMaxZeros(vector<vector<int>>arr,int N){
    
    vector<int> store;
    
    for(int i=0; i<N; i++) {
        int count = 0;
        for(int j=0; j<N; j++) {
            if(arr[j][i] == 0) {
                count++;
            }
        }
        store.push_back(count);
    }
    
    int maxi = -1;
    int val = 0;
    for(int i=0; i<store.size(); i++) {
        if(store[i] > maxi) {
            maxi = store[i];
            val = i;
        }
    }
    
    if(maxi == 0) {
        return -1;
    }
    return val;
}