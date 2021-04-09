/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //for kth largest problem think of heap
        //priority_queue by default is a max heap
        //using the following to make it a min heap
        //heap sort is online algo while sorting is offline
        priority_queue<int, vector<int>,greater<int>> pq;
        for(int i = 0; i < nums.size(); i++){
            //maintain a size k heap
            if(pq.size() < k || nums[i] >= pq.top()){
                pq.push(nums[i]);
            }
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
// @lc code=end

