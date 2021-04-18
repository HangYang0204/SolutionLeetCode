#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::priority_queue;

class ArraySearch{
public:
    void FindkthMaxmimum(vector<int> nums, int k){
        //input : the number array and the number of top 
        //maximums
        //no out put but should print out the k numbers
        priority_queue<int, vector<int>, std::greater<int>> pq; //min heap
        for(int i = 0; i < nums.size(); i++){
            if(pq.size() <= k || nums[i] > pq.top()){
                pq.push(nums[i]);
            }
            if(pq.size() > k) pq.pop();
        }
        //at the end of the loop we have k size heap. 
        while(!pq.empty()){
            std::cout << pq.top() << std::endl;
            pq.pop();
        }
    }
};


int main(){
    vector<int> vec = {2,4,6,7,8,9,2,2,3,5,8};
    ArraySearch s;
    s.FindkthMaxmimum(vec,3);
}