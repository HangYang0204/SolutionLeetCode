#include<iostream>
#include<vector>
#include<queue>

using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return max;
    }
private:
    int max = 0;
    void helper(TreeNode* root, int num){
        num = num * 10 + root->val; //the num stores parent accumlated value. 
        //base case is reach leaf
        if(root->left == NULL && root->right == NULL){
            max += num;//accumlate all that reached leaf.
            return;
        }

        if(root->left != NULL){
            helper(root->left,num);
        }

        if(root->right != NULL){
            helper(root->right,num);
        }
    }
};

    
int main(){
    TreeNode* x = new TreeNode(3);
    TreeNode* y = new TreeNode(5,x,nullptr);
    TreeNode* z = new TreeNode(1,nullptr,y);
    Solution s;
    int res;
    res = s.sumNumbers(z);
    std::cout << res << std::endl;
 
}