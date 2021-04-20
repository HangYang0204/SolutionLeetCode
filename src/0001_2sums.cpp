#include<iostream>
#include<unordered_map>
#include<vector>

//arr = [6,7,2,3,9] target = 13 return true
bool canSum(int arr[], int Size, int target,std::unordered_map<int,int>& memo){
    if(memo.find(target) != memo.end()){
        return memo[target];
    }
    if(target == 0){
        return true;
    }
    if(target < 0){
        return false;
    }

    for(int i = 0; i < Size; i++){
        int remainder = target - arr[i];
        if(canSum(arr,Size,remainder,memo) == true){
            memo[remainder] = true;
            return true;
        }
    }

    memo[target] = false;
    return false;
}

std::vector<int>* howSum(std::vector<int>arr,int target){
    if(target == 0){
        return std::vector<int>();
    }
    if(target < 0){
        return NULL;
    }

    for(int i = 0; i < arr.size(); i++){
        int remainder = target - arr[i];
        std::vector<int>* result = howSum(arr,remainder);
        if(result == NULL){
            return vec;
        }
        else{
            return result.push_back(remainder);
        }
    }
    return NULL;
}

int main(){
    // int arr[] = {2,4};
    // int Size = sizeof(arr)/sizeof(arr[0]);
    // int target = 7;
    // std::unordered_map<int,int> memo;
    //std::cout << canSum(arr,Size,target,memo) << std::endl;
    std::vector<int> arr {2,4};
    int target = 7;
    howSum(arr,target);
    //std::cout << howSum(arr,target) << std::endl;
    return 0;
}
