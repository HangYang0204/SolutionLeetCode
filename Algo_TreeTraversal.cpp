#include<vector>
#include<iostream>

struct TreeNode{
    int val;
    struct TreeNode* root;
    struct TreeNode* left;
    struct TreeNode* right;
    //TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(){
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    //TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x){
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
    //TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x, TreeNode* left, TreeNode* right){
        this->val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution{
    public:
    std::vector<int> inordertraversal(TreeNode* root){
        treeTraversal(root);
        return result;
    }
    private:
    void treeTraversal(TreeNode* root){
        if(not root){
            return;
        }
        treeTraversal(root->left);
        result.push_back(root->val);
        treeTraversal(root->right);
    }
    std::vector<int> result;
};

int main(){
    TreeNode* x = new TreeNode(3);
    TreeNode* y = new TreeNode(5,x,nullptr);
    TreeNode* z = new TreeNode(1,nullptr,y);
    Solution s;
    std::vector<int> res;
    res = s.inordertraversal(z);
    for(int i : res){
        std::cout << i << std::endl;
    }
 
}
