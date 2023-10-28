int missingNumber(int A[], int N)
{
    int sum = N*(N+1)/2;
    
    int res = 0;
    for(int i=0; i<N-1; i++) {
        res = res + A[i];
    }
    
    int ans = sum - res;
    return ans;
}