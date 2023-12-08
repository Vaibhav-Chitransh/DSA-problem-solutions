bool checkPrime(int n) {
    int i = 1;
    int count = 0;
    
    while(i <= n) {
        if(n % i == 0) {
            count++;
        }
        if(count > 2) {
            return false;
        }
        i++;
    }
    if(count == 2) {
        return true;
    }
}

int minNumber(int arr[],int N)
{
    int sum = 0;
    for(int i=0; i<N; i++) {
        sum = sum + arr[i];
    }
    
    if(checkPrime(sum)) {
        return 0;
    }
    
    int k = 0;
    while(true) {
        sum = sum + 1;
        bool flag = checkPrime(sum);
        
        if(flag == true) {
            return k+1;
        }
        k++;
    }
}