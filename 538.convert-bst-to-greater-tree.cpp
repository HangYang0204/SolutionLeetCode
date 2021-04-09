/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        //using the Right -> root -> left 
        if(not root){
            return nullptr;
        }
        if(root->right != nullptr){
            convertBST(root->right);
        }
        int temp = root->val;
        root->val += sum; 
        sum += temp;
        if(root->left != nullptr){
            convertBST(root->left);
        }
        return root;
    }
private:
    int sum = 0;
};
// @lc code=end

