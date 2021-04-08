#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;

void Fizzbuzz(int n){
    for(int i = 1; i <= n; i++){
        if(i%3 == 0 && i%5 == 0){
            cout << "FizzBuzz" << endl;
        } else if(i%3 == 0 && i%5 != 0){
            cout << "Fizz" << endl;
        } else if(i%3 != 0 && i%5 == 0){
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }
}

int gcd(int a, int b){
    
    while(a != b){
        if(a > b){
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main(){
    Fizzbuzz(15);
    cout << gcd(15,5) << endl;
}