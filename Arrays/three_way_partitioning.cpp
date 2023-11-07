void threeWayPartition(vector<int>& array,int a, int b)
    {
        int start = 0;
        int end = array.size() - 1;
        int i=0;
        
        while(i<= end) {
            if(array[i] < a) {
                swap(array[i++], array[start++]);
            }
            
            else if(array[i] > b) {
                swap(array[i], array[end--]);
            }
            else{
                i++;
            }
        }
    }