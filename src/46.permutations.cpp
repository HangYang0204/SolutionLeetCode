/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*input: [1,2] output: [[1,2],[2,1]]
        the nature of the problem is recursive. supposing we have a function f
        Taken [1,2] for example, we could loop through the array
        f([1,2]) = -- 1, f([2]) 
                   |
                   -- 2, f([1])
        the sub problem will return [[2]] and [[1]], we need to add the current value in
        the beginning of each vector a.k.a add 1 to top of [2] and add 2 to top pf [1].
        then we need to push back the result in a global vector collection. 
        */
        if(nums.size() <= 0) return {nums};
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            //drop the current ele from the array
            vector<int> subnums = nums;
            subnums.erase(subnums.begin() + i);
            //process the sub problem
            auto res = permute(subnums);
            for(int j = 0; j < res.size(); j++){
                vector<int> _v = res[j];
            //add current member nums[i] in the beginning of the array
                _v.insert(_v.begin(),nums[i]);
                result.push_back(_v);
            }
        }
        return result;
    }
};
// @lc code=end

