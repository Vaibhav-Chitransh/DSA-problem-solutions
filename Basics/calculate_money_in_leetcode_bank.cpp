class Solution {
public:
    int totalMoney(int n) {
        int i = 1;
        int k = 1;
        int d = 0;
        int count = 0;

        while(i <= n) {
            count = count + k;
            k++;
            d++;
            i++;

            if(d == 7) {
                k = k - d + 1;
                d = 0;
            }
        }
        return count;
    }
};