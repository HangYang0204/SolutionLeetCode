#include<vector>
#include<iostream>

int main(){
    std::vector<int> vec = {1,2,3,4};
    for(int i : vec){
        std::cout << i << std::endl;
    }
    std::cout << "max size return: " << vec.max_size() << std::endl;
    std::cout << "baxk return: " << vec.back() << std::endl;
}