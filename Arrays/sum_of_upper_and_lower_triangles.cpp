vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
{
    vector<int> ans;
    int upperSum = 0;
    int lowerSum = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            upperSum+=matrix[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            lowerSum+=matrix[i][j];
        }
    }
    
    ans.push_back(upperSum);
    ans.push_back(lowerSum);
    
    return ans;
}