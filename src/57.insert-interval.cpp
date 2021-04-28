/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //we will define is_overlap() and merge_intervals()
        
    }
private:
    bool isoverlap(vector<int> a, vector<int> b){
        return (b[0] < a[1] && b[1] > a[0]);
    }

    vector<int> mergeintervals(vector<int> a, vector<int> b){
        vector<int> result;
        if(a.empty() || b.empty())
        if(isoverlap(a,b)) result = {a[0] < b[0] ? a[0] : b[0],
                                a[1] > b[1] ? a[1] : b[1]};
        return result;
    }
};
// @lc code=end

