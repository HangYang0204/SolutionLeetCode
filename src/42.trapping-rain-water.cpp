/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
       //at column i the rain water is determined by
       //the min between maximum hight on the left 
       //and the maximum height on the right
       //then minus the current height 
       //task: what is the maximum element in a vector
       //range? it is max_element(range)
       //task 2: how to represent a range in vector?
       //using cbegin() and cend()
        int rainsum = 0;
        auto l = cbegin(height);
        auto r = cend(height);
        for(int i = 0; i < height.size(); i++){
            int lmax = *max_element(l, l + i + 1);
            int rmax = *max_element(l + i, r);
            rainsum += min(lmax,rmax) - height[i];
        }
        return rainsum;
    }
};
// @lc code=end

