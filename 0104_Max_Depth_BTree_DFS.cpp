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
    int maxDepth(TreeNode* root) {
        if(not root){
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int depth = (left > right) ? left + 1 : right + 1;
        return depth;
        
    }
};

    
int main(){
    TreeNode* x = new TreeNode(3);
    TreeNode* y = new TreeNode(5,x,nullptr);
    TreeNode* z = new TreeNode(1,nullptr,y);
    Solution s;
    int res;
    res = s.maxDepth(z);
    std::cout << res << std::endl;
 
}
