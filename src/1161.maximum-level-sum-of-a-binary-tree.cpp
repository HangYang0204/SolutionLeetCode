/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
If i could have sum of all levels and then store unique value one by one in a maxheap. then 
after I traversal all nodes/levels of the tree, the heap.top would be the answer.
Time Complexity O(N) + O(log2N) = O(N)
Space Complexity O(lg2N)
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        BFS(root,1);
        return FindMaxElement(levelsum) + 1;
    }
private:
    vector<int> levelsum;
    void BFS(TreeNode* root, int level){
        if(not root || level < 1) return;
        if(levelsum.size() < level) levelsum.push_back(root->val);
        else levelsum[level - 1] += root->val;
        BFS(root->left,level + 1);
        BFS(root->right,level + 1);
    }
    
    int FindMaxElement(vector<int>nums){
        if(nums.size() <= 1) return 0;
        int i = 0, j = 1;
        for(; j < nums.size(); ++j){
            if(nums[j] > nums[i]){
                i = j;
            } 
        } 
        return i;
    }

};
// @lc code=end

