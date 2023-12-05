class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        int advance = 0;
        int count = 0;

        while(advance != 1) {
            if(n%2 == 0) {
                matches = n/2;
                advance = n/2;
                count = count + matches;
            }
            else {
                matches = (n-1)/2;
                advance = ((n-1)/2) + 1;
                count = count + matches;
            }
            n = advance;
        }
        return count;
    }
};