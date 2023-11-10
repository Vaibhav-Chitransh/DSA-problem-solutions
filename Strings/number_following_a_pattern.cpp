string printMinNumberForPattern(string S){
    int length = S.size()+1;
    vector<int> store;
    string ans;
    
    for(int i=0; i<length; i++) {
        ans.push_back(i+1+'0');
    }
    
    int k = 1;
    
    while(k) {
        int t = 0;
        for(int i=0; i<S.size(); i++) {
            if(S[i] == 'I' && ans[i] > ans[i+1]) {
                swap(ans[i], ans[i+1]);
                t = 1;
            }
            else if(S[i] == 'D' && ans[i] < ans[i+1]) {
                swap(ans[i], ans[i+1]);
                t = 1;
            }
        }
        if(t == 0) {
            k=0;
        }
    }
    return ans;
}