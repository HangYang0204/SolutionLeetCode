/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> memo; //memo stores arr[i] : i;
        for(int i = 0; i < nums.size(); i++){
            //if already in memo return key and current i
            int delta = target - nums[i];
            if(memo.count(delta)){
                return {memo[delta],i};
            }
            memo[nums[i]] = i;
        }
        return {};
        
    }
};
// @lc code=end

