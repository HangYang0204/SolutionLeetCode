/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() <= k) return nums;
        //frequency map nums[i] : frequency
        map<int,int> fmap;
        for(int n : nums){
            fmap[n] += 1;
        }
        //create and maintain a k min heap
        auto comp = [&fmap](int n1, int n2){return fmap[n1] > fmap[n2];};
        priority_queue<int, vector<int>,decltype(comp)> pq(comp);

        for(pair<int,int> p : fmap){
            pq.push(p.first); //store nums[i]
            if(pq.size() > k) pq.pop();
        }
        
        //build a vector from the k size heap and return 
        vector<int> top;
        while(!pq.empty()){
            top.push_back(pq.top());
            pq.pop();
        }
        return top;
    }
};
// @lc code=end

