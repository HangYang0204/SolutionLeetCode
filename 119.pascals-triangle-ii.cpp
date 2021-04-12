/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //same as 118 but only return B instead of collection
        if(memo.count(rowIndex)){
            return memo[rowIndex];
        }
        //this PT is 0 based
        if(rowIndex < 0) return {};
        if(rowIndex == 0) return {1}; //base case
        //now get A
        vector<int> lastrow = getRow(rowIndex - 1);
        //define B
        vector<int> newrow = {1}; //with B[0] = 1
        for(int i = 0; i < lastrow.size() - 1; i++){
            newrow.push_back(lastrow[i] + lastrow[i + 1]);
        }
        newrow.push_back(1);//add B[N]
        memo[rowIndex] = newrow;
        return newrow;

    }
private:
    unordered_map<int, vector<int>> memo;
};
// @lc code=end

