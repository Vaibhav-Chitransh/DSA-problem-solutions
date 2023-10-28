long long int totalFine(int n, int date, int car[], int fine[])
    {
        long long int sum = 0;
        
        if(date%2 ==  0) {
            for(int i=0; i<n; i++) {
                if(car[i] % 2 == 1) {
                    sum = sum + fine[i];
                }
            }
        }
        
        else {
            for(int i=0; i<n; i++) {
                if(car[i] % 2 == 0) {
                    sum = sum + fine[i];
                }
            }
        }
        
        return sum;
    }