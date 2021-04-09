/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    //the key point is stated below:
    //define the sum until inde x is sum(x)
    //then if exists index y > x such that
    //sum(y) - sum(x) = k then count++
    //stored all sum(0 - n) in a map
        int count = 0;
        int sum = 0; //global variable to record sum
        unordered_map<int, int> memo;
        //memo stores sum : frequency of this sum
        memo[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(memo.count(sum - k)){
                count += memo[sum-k]; //found one possible x y
            }
             
            memo[sum]++;
           
        }
        return count;
    }
};
// @lc code=end

