pair<long long, long long> getMinMax(long long a[], int n) {
    
    return {*min_element(a,a+n), *max_element(a,a+n)};
}