int remove_duplicate(int a[],int n){
        int ans = 1;
        for(int i=1; i<n; i++) {
            if(a[i] != a[ans - 1]) {
                a[ans] = a[i];
                ans++;
            }
        }
        return ans;
    }