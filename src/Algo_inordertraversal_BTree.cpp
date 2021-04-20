#include<iostream>
#include<vector>
#include<stack>

typedef struct TreeNode{
    int data;
    TreeNode* root;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->data = val;
        this->left = left;
        this->right = right;
    }
}* Treeptr;

class Solution{
public:
    std::vector<int> inordertraversal(Treeptr root){
        std::stack<Treeptr> ptrs;
        std::vector<int> result;
        Treeptr curr = root;
        while(curr != NULL || !ptrs.empty()){
            while(curr != NULL){
                ptrs.push(curr);
                curr = curr->left;
            }
            curr = ptrs.top();//relocate ancestor
            result.push_back(ptrs.top()->data);
            ptrs.pop();
            curr = curr->right;  
        }
        return result;
    }
};

int main(){
    Treeptr x = new TreeNode(4);
    Treeptr x2 = new TreeNode(5);
    Treeptr x3 = new TreeNode(6);
    Treeptr y = new TreeNode(2,x,x2);
    Treeptr y2 = new TreeNode(3,x3,nullptr);
    Treeptr z = new TreeNode(1,y,y2);
    Solution s;
    std::vector<int> res;
    res = s.inordertraversal(z);
    for(int i : res){
        std::cout << i << std::endl;
    }
    return 0;
}
