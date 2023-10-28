void binSort(int A[], int N)
    {
        
        int i=0;
        int j=N-1;
        
        while(i < j) {
            if(A[i] == 1 && A[j] == 0) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
            
            else if(A[i] == 0 && A[j] == 0) {
                i++;
            }
            
            else if(A[i] == 1 && A[j] == 1) {
                j--;
            }
            
            else if(A[i] == 0 && A[j] == 1) {
                i++;
                j--;
            }
        }
    }


