class Solution{
public:
    void solution(vector<int>& ans, int n, int k, bool flag) {
        
        // Base case 
        if(n == k+5) {
            return ;
        }
        
        
        else if(n > 0 && flag == false) {
            ans.push_back(n);
            return solution(ans, n-5, k, false);
        }
        
        else if(n <= 0) {
            ans.push_back(n);
            return solution(ans, n+5, k, true);
        }
        
        else if(n > 0 && flag == true) {
            ans.push_back(n);
            return solution(ans, n+5, k, true);
        }
    }

    vector<int> pattern(int N){
        vector<int> ans;
        int k = N;
        ans.push_back(N);
        bool flag = false;
        
        if(N > 0) {
            solution(ans, N-5, k, flag);
        }
        
        return ans;
    }
};