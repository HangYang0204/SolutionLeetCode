#include<iostream>

int convertsum(int N, int k){
    int sum = 0;
    while(N > 0){
        sum += N%k;
        N /= k;
    }
    return sum;
}

int main(){
    std::cout << convertsum(8,10) << std::endl;
}