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
        int depth = 0;
        //TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();//this is important to keep outside of the for-loop
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL){
                    q.push(curr->left);                    
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
            depth++;
        }
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