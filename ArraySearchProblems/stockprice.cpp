#include<vector>
#include<iostream>
using namespace std;//do not use for real project!!!

class ArraySearch{
private:
    int findMaxPosition(vector<int> nums){
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[i] <= nums[j]){ //this will return last found maximum if duplicates exist 
                i = j;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }

    int findMinPosition(vector<int> nums){
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[j] < nums[i]){//this will return first found maximum if duplicates exist 
                i = j;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }
public:
    vector<int> stockBuynSell(vector<int> stocks){
        int buyidx = 0, sellidx = 0;
        //first find the maximum point of stocks
        sellidx = findMaxPosition(stocks);
        //find the min in the subarray before sold point
        vector<int> substocks;
        for(int i = 0; i < sellidx; i++){
            substocks.push_back(stocks[i]);
        }
        buyidx = findMinPosition(substocks);
        return {buyidx,sellidx};
    }

    void printvector(vector<int>vec){
        for(int v : vec){
            cout << v << endl;
        }
    }
};
//driver code
int main(){
    vector<int> test1 = {3,2,5,7,0,2,1,4,7};
    ArraySearch s;
    s.printvector(s.stockBuynSell(test1));
    return 0;
}