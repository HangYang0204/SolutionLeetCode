/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*similar to permutation, this time we exclude the duplicates*/
        if(nums.size() <= 1) return {nums};
        vector<vector<int>> result;
        const int MAX = nums.size() - 1;
        for(int i = 0; i <= MAX; i++){
            vector<int> subnums = nums;
            subnums.erase(subnums.begin() + i);
            auto res = permuteUnique(subnums);
            for(int j = 0; j < res.size(); j++){
                vector<int> _v = res[j];
                _v.insert(_v.begin(),nums[i]);
                auto it = std::find(result.begin(),result.end(),_v);
                if(it == result.end()){
                    result.push_back(_v);
                }
            }
        }
        return result;
    }
};
// @lc code=end

