#include<iostream>
#include<vector>

// void ComputeFibonacchi(std::vector<long>& vec){
//     vec.push_back() = 1;
//     vec.push_back() = 1;
//     for(int i = 2; i < N; i++){
//         vec.push_back() = vec[i] + vec[i-1];
//     } 
// }

int main(){
    int N;
    int i;
    std::cout << "type the maximum number: ";
    std::cin >> N;
    std::vector<long> vec = {0,1};
    for(int i = 1; i < N; i++){
        long temp = vec[i] + vec[i-1];
        vec.push_back(temp);
    } 

    do{
        std::cout << "type the position to return in the sequence(type 0 to exit): ";
        std::cin >> i;
        std::cout << vec[i] << std::endl; 
    } while(i != 0);
    return 0;
}