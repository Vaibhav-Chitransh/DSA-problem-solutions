// Printing the counting with the help of recursion
#include<iostream>
using namespace std;

void printCounting(int n) {
    // Base case
    if(n == 0) {
        return ;
    }

    printCounting(n-1);
    cout << n << " ";
}

int main(){
    int n = 5;

    printCounting(n);
    return 0;
}