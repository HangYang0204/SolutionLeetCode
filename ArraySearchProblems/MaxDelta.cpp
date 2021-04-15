#include<iostream>
#include<vector>
using namespace std;

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
public:
    vector<vector<int>> FindMaxDelta(vector<int> nums){
        //step 1: find the maximum point
        int max_memember = findMaxPosition(nums);
        //step 2: find the maximum between MAX in left and MAX in right
        int idx_N = nums.size() - 1; 
        int slicepoint = nums[max_memember] - nums[0] > nums[max_memember] - nums[idx_N] ?
                         0 : nums.size() - 1;
        vector<vector<int>> result;
        if(slicepoint == 0){
            result.push_back({nums[0]});
            nums.erase(nums.begin());
            result.push_back(nums);
        }
        else{
            vector<int> temp = {nums[idx_N]};
            nums.pop_back();
            result.push_back(nums);
            result.push_back(temp);
        }
        return result;        
    }
};

int main(){
    vector<int> test2 = {7,3,6,3,2,9,6,0,3};
    ArraySearch s;
    vector<vector<int>> res = s.FindMaxDelta(test2);
    for(int v : res[0]){
        cout << v;
    }
    cout << "|";
    for(int u : res[1]){
        cout << u;
    }

    return 0;
}