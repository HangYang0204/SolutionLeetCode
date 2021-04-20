/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
            1. for given numRows, there will be same number of levels of PT
            2. on level n, there is a size n vector
            3. set level N - 1 vector A, level N vector B we observed:
                B[n - 1] = A[n - 1] + A[n], B[0] = B[N] = 1;
            4. the above is fibonachii thus using recursion                 
        */
        if(memo.count(numRows)){ //if already in memo return stored vv 
            return memo[numRows];
        }
        if(numRows <= 0) return {};
        if(numRows == 1) return {{1}}; //the heap of PT 
        vector<vector<int>> res = generate(numRows - 1);
        vector<int> lastrow = res.back(); //this is the method to retrive last element of a vector
        vector<int> newrow = {1};//initialize B with B[0]
        for(int i = 0; i < lastrow.size() - 1; i++){// loop between 0 ~ n-2 since we willu st i + 1
            newrow.push_back(lastrow[i] + lastrow[i+1]);
        }
        newrow.push_back(1);//add B[N] = 1
        res.push_back(newrow);
        memo[numRows] = res; // add to memo
        return res;
    }
private:
    unordered_map<int, vector<vector<int>>> memo;
};
// @lc code=end

